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
std::map<std::string, std::vector<std::string>> g_testResults;
std::map<std::string, std::vector<std::string>> g_testResultsLabels;

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
        if(prefix == nullptr)
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
        std::vector<std::string> &results = g_testResults[test];
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
            results.emplace_back(std::move(line));
        }
    }
}

void checkResults()
{
    for (const char * testReport : g_testReports)
    {
        const std::vector<std::string> &labels = g_testResultsLabels[testReport];
        for (const std::string &testCase : testCases::g_testCases[testReport])
        {
            if (std::find(labels.begin(), labels.end(), testCase) ==labels.end())
            {
                g_errors.push_back("error: No test results for " + testCase);
            }
        }
    }
}

void reportResults(std::ostream &out)
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
        throw std::runtime_error("errors found");
    }
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
        reportResults(std::cout);
        return 0;
    }
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 2;
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
