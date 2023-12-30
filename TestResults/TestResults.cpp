#include <TestCases.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace testResults
{

std::vector<std::string> g_errors;
std::vector<std::string> g_warnings;
std::vector<std::string> g_diffs;
std::vector<std::string> g_preamble;
std::vector<const char *> g_testReports;
struct TestResult
{
    std::string line;
    bool hasResult;
    bool deprecated;
    bool passed;
};
std::map<std::string, std::vector<TestResult>> g_testResults;
std::map<std::string, std::vector<std::string>> g_testResultsLabels;

bool isTestCaseResult(const std::string &line)
{
    if (line.empty())
    {
        return false;
    }
    const auto bar = line.find_first_of('|');
    if (bar == std::string::npos)
    {
        return false;
    }
    const auto firstNonSpace = line.find_first_not_of(' ');
    if (firstNonSpace == bar)
    {
        return false;
    }
    const auto endFirstWord = line.find_last_not_of(' ', bar);
    const std::string firstWord = line.substr(firstNonSpace, endFirstWord - firstNonSpace - 1);
    if (firstWord.empty() || firstWord == "Case" || firstWord.find_first_not_of('-') == std::string::npos)
    {
        return false;
    }
    const auto beginSecondWord = line.find_first_not_of(' ', bar + 1);
    if (beginSecondWord == std::string::npos)
    {
        // Test label with no result reported
        return true;
    }
    const auto lastNonSpace = line.find_last_not_of(' ');
    if (lastNonSpace == bar)
    {
        return false;
    }
    const std::string secondWord = line.substr(beginSecondWord, lastNonSpace - beginSecondWord + 1);
    return secondWord != "Result" && secondWord.find_first_not_of('-') != std::string::npos;
}

void scanResultsFile(std::filesystem::path path)
{
    if (!is_regular_file(path))
    {
        throw std::runtime_error(path.string() + " is not a plain file.");
    }

    std::ifstream file(path);
    std::string line;
    int lineNum{};
    const auto getLine = [&]
    {
        std::getline(file, line);
        ++lineNum;
    };
    while (file)
    {
        getLine();
        if (!file)
        {
            break;
        }
        if (line.find("##") == 0)
        {
            break;
        }
        g_preamble.push_back(line);
    }
    while (file && line.find("##") == 0)
    {
        const std::string title = line.substr(line.find_first_not_of(' ', line.find_first_of(' ')));
        const char *prefix = testCases::getPrefixForTestName(title);
        if (prefix == nullptr)
        {
            g_errors.push_back(path.string() + '(' + std::to_string(lineNum) + "): test title '" + std::string{title}
                               + "' not found.");
            while (file)
            {
                getLine();
                if (!file || line.find("##") == 0)
                {
                    break;
                }
            }
            continue;
        }

        g_testReports.push_back(prefix);
        const std::string test = prefix;
        std::vector<TestResult> &results = g_testResults[test];
        std::vector<std::string> &labels = g_testResultsLabels[test];
        while (file)
        {
            getLine();
            if (!file || line.find("##") == 0)
            {
                break;
            }
            if (line.substr(0, test.length()) == test)
            {
                labels.push_back(line.substr(0, line.find_first_of(' ')));
            }
            if (!isTestCaseResult(line))
            {
                continue;
            }
            const auto bar = line.find('|');
            bool hasResult = line.find_first_not_of(' ', bar) != std::string::npos;
            const bool deprecated = line.find("(deprecated)", bar) != std::string::npos;
            bool passed{};
            if (!deprecated)
            {
                if (line.find("Pass", bar) != std::string::npos)
                {
                    passed = true;
                }
                else if (line.find("Failure", bar) == std::string::npos)
                {
                    hasResult = false;
                }
            }
            results.push_back({line, hasResult, deprecated, passed});
        }
    }
}

bool markedDeprecated(const std::string &label)
{
    const std::string prefix = label.substr(0, label.find_first_of("0123456789"));
    const std::vector<TestResult> &results = g_testResults[prefix];
    const auto matchesLabel = [&](const TestResult &result) { return result.line.find(label) != std::string::npos; };
    const auto pos = std::find_if(results.begin(), results.end(), matchesLabel);
    return pos != results.end() && pos->deprecated;
}

void checkResults()
{
    for (const char *testReport : g_testReports)
    {
        const std::vector<std::string> &labels = g_testResultsLabels[testReport];
        auto findLabel = [&](const std::string &label)
        { return std::find(labels.begin(), labels.end(), label) != labels.end(); };
        for (const std::string &deprecated : testCases::getDeprecatedLabels(testReport))
        {
            if (!findLabel(deprecated))
            {
                g_errors.push_back("error: No test results for deprecated test " + deprecated);
            }
        }
        for (const std::string &testCase : testCases::g_testCases[testReport])
        {
            if (testCases::isDeprecatedLabel(testCase) && !markedDeprecated(testCase))
            {
                g_errors.push_back("error: Test results for " + testCase + " not marked deprecated.");
            }
            if (std::find(labels.begin(), labels.end(), testCase) == labels.end())
            {
                g_errors.push_back("error: No test results for " + testCase);
            }
        }
        for (const TestResult &result : g_testResults[testReport])
        {
            const std::string label = result.line.substr(0, result.line.find_first_of(' '));
            if (!result.hasResult)
            {
                g_warnings.push_back("warning: No result for test " + label);
            }
            else if (result.deprecated && !testCases::isDeprecatedLabel(label))
            {
                g_errors.push_back("error: Test result for " + label
                                   + " is marked deprecated, but test case is not deprecated");
            }
        }
    }
}

int reportResults(std::ostream &out)
{
    for (const std::string &warning : g_warnings)
    {
        std::cerr << warning << '\n';
    }
    if (!g_errors.empty())
    {
        for (const std::string &error : g_errors)
        {
            std::cerr << error << '\n';
        }
        return 1;
    }
    return 0;
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
        if (args.size() < 3)
        {
            throw std::runtime_error("Missing directory arguments");
        }

        g_errors = testCases::scanTestDirectory(args[1]);
        scanResultsFile(args[2]);
        checkResults();
        return reportResults(std::cout);
    }
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 2;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 3;
    }
}

}    // namespace testResults

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return testResults::main(args);
}
