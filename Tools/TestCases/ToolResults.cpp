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
    const auto separatingBar = line.find_first_of('|', 1);
    if (separatingBar == std::string::npos)
    {
        return false;
    }
    const auto beginFirstWord = line.find_first_not_of(' ', line[0] == '|' ? 1 : 0);
    if (beginFirstWord == separatingBar)
    {
        return false;
    }
    const auto endFirstWord = line.find_last_not_of(" |", separatingBar);
    const std::string firstWord = line.substr(beginFirstWord, endFirstWord - beginFirstWord + 1);
    if (firstWord.empty() || firstWord == "Case" || firstWord.find_first_not_of('-') == std::string::npos)
    {
        return false;
    }
    const auto beginSecondWord = line.find_first_not_of(" |", separatingBar + 1);
    if (beginSecondWord == std::string::npos)
    {
        // Test label with no result reported
        return true;
    }
    auto endSecondWord = line.find_first_of(" |", beginSecondWord);
    if (endSecondWord == std::string::npos)
    {
        endSecondWord = line.length();
    }
    const std::string secondWord = line.substr(beginSecondWord, endSecondWord - beginSecondWord);
    return secondWord != "Result" && secondWord.find_first_not_of('-') != std::string::npos;
}

std::string getTestLabel(const std::string &line, const std::string &test)
{
    std::size_t start = line.find_first_not_of(" |");
    if (start != std::string::npos && line.substr(start, test.length()) == test)
    {
        return line.substr(start, line.find_first_of(' ', start) - start);
    }
    return {};
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
        const char *prefix = getPrefixForTestName(title);
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
            const std::string label = getTestLabel(line, test);
            if (!label.empty())
            {
                labels.push_back(label);
            }
            if (!isTestCaseResult(line))
            {
                continue;
            }
            const auto separatingBar = line.find('|', line[0] == '|' ? 1 : 0);
            bool hasResult = line.find_first_not_of(" |", separatingBar) != std::string::npos;
            const bool deprecated = line.find("(deprecated)", separatingBar) != std::string::npos;
            bool passed{};
            if (deprecated)
            {
                // Deprecated tests are considered passing.
                hasResult = true;
                passed = true;
            }
            else
            {
                if (line.find("Pass", separatingBar) != std::string::npos)
                {
                    passed = true;
                }
                else if (line.find("Failure", separatingBar) == std::string::npos)
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

std::string getLabel(const TestResult &result)
{
    const std::string &line = result.line;
    const std::size_t start = line[0] == '|' ? 1 : 0;
    const auto beginLabel = line.find_first_not_of(' ', start);
    const auto endLabel = line.find_first_of(' ', beginLabel);
    return line.substr(beginLabel, endLabel - beginLabel);
}

void ToolResults::checkResults()
{
    for (const char *testReport : m_testReports)
    {
        const std::vector<std::string> &labels = m_testResultsLabels[testReport];
        auto findLabel = [&](const std::string &label)
        { return std::find(labels.begin(), labels.end(), label) != labels.end(); };
        for (const std::string &deprecated : getDeprecatedLabels(testReport))
        {
            if (!findLabel(deprecated))
            {
                m_errors.push_back("error: No test results for deprecated test " + deprecated);
            }
        }
        for (const std::string &testCase : getTestCaseLabels(testReport))
        {
            if (isDeprecatedLabel(testCase) && !markedDeprecated(testCase))
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
            const std::string label = getLabel(result);
            if (!result.hasResult)
            {
                m_warnings.push_back("warning: No result for test " + label);
            }
            else if (result.deprecated && !isDeprecatedLabel(label))
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
            if (result.deprecated)
            {
                ++summary.numDeprecated;
            }
            else if (!result.hasResult)
            {
                continue;
            }
            ++summary.numCasesReported;
            if (result.passed)
            {
                ++summary.numPassed;
            }
            else
            {
                ++summary.numFailed;
            }
        }
        toolSummary.push_back(summary);
    }
    return toolSummary;
}

}    // namespace testCases
