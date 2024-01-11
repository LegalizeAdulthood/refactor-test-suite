#include <ToolResults.h>

#include <TestCases.h>

#include <algorithm>
#include <fstream>
#include <stdexcept>

namespace testCases
{

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

void ToolResults::scanResultsFile(std::filesystem::path path)
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
        m_preamble.push_back(line);
    }
    while (file && line.find("##") == 0)
    {
        const std::string title = line.substr(line.find_first_not_of(' ', line.find_first_of(' ')));
        const char *prefix = testCases::getPrefixForTestName(title);
        if (prefix == nullptr)
        {
            m_errors.push_back(path.string() + '(' + std::to_string(lineNum) + "): test title '" + std::string{title}
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

        m_testReports.push_back(prefix);
        const std::string test = prefix;
        std::vector<TestResult> &results = m_testResults[test];
        std::vector<std::string> &labels = m_testResultsLabels[test];
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

bool ToolResults::markedDeprecated(const std::string &label)
{
    const std::string prefix = label.substr(0, label.find_first_of("0123456789"));
    const std::vector<TestResult> &results = m_testResults[prefix];
    const auto matchesLabel = [&](const TestResult &result) { return result.line.find(label) != std::string::npos; };
    const auto pos = std::find_if(results.begin(), results.end(), matchesLabel);
    return pos != results.end() && pos->deprecated;
}

void ToolResults::checkResults()
{
    for (const char *testReport : m_testReports)
    {
        const std::vector<std::string> &labels = m_testResultsLabels[testReport];
        auto findLabel = [&](const std::string &label)
        { return std::find(labels.begin(), labels.end(), label) != labels.end(); };
        for (const std::string &deprecated : testCases::getDeprecatedLabels(testReport))
        {
            if (!findLabel(deprecated))
            {
                m_errors.push_back("error: No test results for deprecated test " + deprecated);
            }
        }
        for (const std::string &testCase : getTestCaseLabels(testReport))
        {
            if (testCases::isDeprecatedLabel(testCase) && !markedDeprecated(testCase))
            {
                m_errors.push_back("error: Test results for " + testCase + " not marked deprecated.");
            }
            if (std::find(labels.begin(), labels.end(), testCase) == labels.end())
            {
                m_errors.push_back("error: No test results for " + testCase);
            }
        }
        for (const TestResult &result : m_testResults[testReport])
        {
            const std::string label = result.line.substr(0, result.line.find_first_of(' '));
            if (!result.hasResult)
            {
                m_warnings.push_back("warning: No result for test " + label);
            }
            else if (result.deprecated && !testCases::isDeprecatedLabel(label))
            {
                m_errors.push_back("error: Test result for " + label
                                   + " is marked deprecated, but test case is not deprecated");
            }
        }
    }
}

std::vector<TestSummary> ToolResults::getSummary() const
{
    std::vector<TestSummary> toolSummary;
    for (std::string test : m_testReports)
    {
        const auto &testResults = m_testResults.find(test);
        if (testResults == m_testResults.end())
        {
            throw std::runtime_error("No test results available for " + test);
        }
        TestSummary summary{};
        summary.name = test;
        for (const TestResult &result : testResults->second)
        {
            ++summary.numCases;
            if (!result.hasResult)
            {
                continue;
            }
            ++summary.numCasesReported;
            if (result.passed)
            {
                ++summary.passes;
            }
            else
            {
                ++summary.failures;
            }
        }
        toolSummary.push_back(summary);
    }
    return toolSummary;
}

}    // namespace testCases
