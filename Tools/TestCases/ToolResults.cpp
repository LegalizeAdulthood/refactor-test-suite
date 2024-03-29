#include <ToolResults.h>

#include <TestCases.h>

#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>

namespace testCases
{

struct TableRow
{
    TableRow(const std::string &line);

    bool valid{};
    std::string first;
    std::string second;
};

TableRow::TableRow(const std::string &line)
{
    if (line.empty())
    {
        return;
    }
    const auto beginFirstWord = line.find_first_not_of(' ', line[0] == '|' ? 1 : 0);
    const auto separatingBar = line.find_first_of('|', 1);
    const auto endFirstWord = line.find_last_not_of(" |", separatingBar);
    first = line.substr(beginFirstWord, endFirstWord - beginFirstWord + 1);
    if (first.empty())
    {
        return;
    }
    const auto beginSecondWord = line.find_first_not_of(" |", separatingBar + 1);
    if (beginSecondWord == std::string::npos)
    {
        // Test label with no result reported
        valid = true;
        return;
    }
    auto endSecondWord = line.find_first_of(" |", beginSecondWord);
    if (endSecondWord == std::string::npos)
    {
        endSecondWord = line.length();
    }
    second = line.substr(beginSecondWord, endSecondWord - beginSecondWord);
    valid = true;
    ;
}

bool isTableHeader(const TableRow &row)
{
    return row.valid
        && ((row.first == "Case" && row.second == "Result")
            || (row.first.find_first_not_of('-') == std::string::npos
                && row.second.find_first_not_of('-') == std::string::npos));
}

bool isTableHeader(const std::string &line)
{
    return isTableHeader(TableRow(line));
}

bool isTestCaseResult(const std::string &line)
{
    const TableRow row(line);
    return row.valid && !isTableHeader(row);
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

bool ToolResults::TestResultCollection::isMarkedDeprecated(const std::string &label) const
{
    const auto matchesLabel = [&](const TestResult &result) { return result.line.find(label) != std::string::npos; };
    const auto pos = std::find_if(results.begin(), results.end(), matchesLabel);
    return pos != results.end() && pos->deprecated;
}

void ToolResults::scanResultsFile()
{
    if (!is_regular_file(m_path))
    {
        throw std::runtime_error(m_path.string() + " is not a plain file.");
    }

    std::ifstream file(m_path);
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
        const std::string prefix = Test::getPrefixForTestName(title);
        if (prefix.empty())
        {
            m_errors.push_back(m_path.string() + '(' + std::to_string(lineNum) + "): test title '" + std::string{title}
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

        m_testPrefixes.push_back(prefix);
        TestResultCollection results;
        results.title = title;
        results.prefix = prefix;
        bool resultsTableSeen{};
        while (file)
        {
            getLine();
            if (!file || line.find("##") == 0)
            {
                break;
            }
            if (isTableHeader(line))
            {
                results.tableHeader.push_back(line);
                resultsTableSeen = true;
                continue;
            }
            if (!resultsTableSeen)
            {
                results.preamble.push_back(line);
                continue;
            }
            if (!isTestCaseResult(line))
            {
                continue;
            }
            const std::string label = getTestLabel(line, results.prefix);
            if (!label.empty())
            {
                results.labels.push_back(label);
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
            results.results.push_back({line, hasResult, deprecated, passed});
        }
        m_testResults.emplace_back(std::move(results));
    }
}

ToolResults::TestResultCollection &ToolResults::getTestResultsForPrefix(std::string_view prefix)
{
    auto it = std::find_if(m_testResults.begin(),
                           m_testResults.end(),
                           [&](const TestResultCollection &results) { return results.prefix == prefix; });
    if (it == m_testResults.end())
    {
        throw std::runtime_error("No test results available for " + std::string{prefix});
    }
    return *it;
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
    for (const std::string &testPrefix : m_testPrefixes)
    {
        TestResultCollection &results = getTestResultsForPrefix(testPrefix);
        const std::vector<std::string> &labels = results.labels;
        auto findLabel = [&](const std::string &label)
        { return std::find(labels.begin(), labels.end(), label) != labels.end(); };
        const Test &test = getTestForPrefix(testPrefix);
        for (const std::string &deprecated : test.getDeprecatedCases())
        {
            if (!findLabel(deprecated))
            {
                m_errors.push_back("error: No test results for deprecated test " + deprecated);
            }
        }
        for (const std::string &testCase : test.getCases())
        {
            if (test.isDeprecatedCase(testCase) && !results.isMarkedDeprecated(testCase))
            {
                m_errors.push_back("error: Test results for " + testCase + " not marked deprecated.");
            }
            if (std::find(labels.begin(), labels.end(), testCase) == labels.end())
            {
                m_errors.push_back("error: No test results for " + testCase);
            }
        }
        for (const TestResult &result : results.results)
        {
            const std::string label = getLabel(result);
            if (!result.hasResult)
            {
                m_warnings.push_back("warning: No result for test " + label);
            }
            else if (result.deprecated && !test.isDeprecatedCase(label))
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
    for (std::string test : m_testPrefixes)
    {
        auto getTestResults = [this](const std::string &test)
        {
            return std::find_if(m_testResults.begin(),
                                m_testResults.end(),
                                [&](const TestResultCollection &results) { return results.prefix == test; });
        };
        auto testResults = getTestResults(test);
        if (testResults == m_testResults.end())
        {
            throw std::runtime_error("No test results available for " + test);
        }
        TestSummary summary{};
        summary.name = test;
        for (const TestResult &result : testResults->results)
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

bool ToolResults::addTests(const std::string &prefix, const std::vector<std::string> &labels)
{
    if (std::find(m_testPrefixes.begin(), m_testPrefixes.end(), prefix) == m_testPrefixes.end())
    {
        return false;
    }
    TestResultCollection &results = getTestResultsForPrefix(prefix);
    std::copy(labels.begin(), labels.end(), std::back_inserter(results.labels));
    std::transform(labels.begin(),
                   labels.end(),
                   std::back_inserter(results.results),
                   [](const std::string &label) { return TestResult{label + " |"}; });
    return true;
}

void ToolResults::writeResults()
{
    std::ofstream str(m_path);
    auto copyLines = [&](const std::vector<std::string> &preamble)
    { std::copy(preamble.begin(), preamble.end(), std::ostream_iterator<std::string>(str, "\n")); };
    copyLines(m_preamble);
    bool insertSeparator{!m_preamble.back().empty()};
    for (const TestResultCollection &results : m_testResults)
    {
        if (insertSeparator)
        {
            str << '\n';
        }
        str << "## " << results.title << "\n";
        copyLines(results.preamble);
        copyLines(results.tableHeader);
        for (const TestResult &result : results.results)
        {
            str << result.line << '\n';
        }
        insertSeparator = true;
    }
}

bool ToolResults::hasResultsForPrefix(std::string_view prefix) const
{
    return std::find(m_testPrefixes.begin(), m_testPrefixes.end(), prefix) != m_testPrefixes.end();
}

void ToolResults::renameTestCases(std::string_view prefix,
                                  const std::vector<std::string_view> &before,
                                  const std::vector<std::string_view> &after)
{
    TestResultCollection &results = getTestResultsForPrefix(prefix);
    std::vector<std::string> newLabels;
    newLabels.reserve(results.labels.size());
    for (const std::string &label : results.labels)
    {
        const auto it = std::find(before.begin(), before.end(), label);
        if (it == before.end())
        {
            throw std::runtime_error("Unknown label " + label);
        }
        newLabels.emplace_back(after[std::distance(before.begin(), it)]);
    };
    const auto getLabelNum = [len = prefix.length()](const std::string &label) { return std::stoi(label.substr(len)); };
    std::sort(newLabels.begin(),
              newLabels.end(),
              [getLabelNum](const std::string &lhs, const std::string &rhs)
              { return getLabelNum(lhs) < getLabelNum(rhs); });

    std::vector<TestResult> newResults;
    newResults.reserve(results.results.size());
    for (const TestResult &result : results.results)
    {
        TestResult newResult(result);
        const std::string label = getLabel(result);
        const auto it = std::find(before.begin(), before.end(), label);
        if (it == before.end())
        {
            throw std::runtime_error("Unknown label " + label);
        }
        newResult.line.replace(
            newResult.line.find(label), label.length(), std::string{after[std::distance(before.begin(), it)]});
        newResults.emplace_back(std::move(newResult));
    }
    const auto getCaseNum = [getLabelNum](const TestResult &text) { return getLabelNum(getLabel(text)); };
    std::sort(newResults.begin(),
              newResults.end(),
              [getCaseNum](const TestResult &lhs, const TestResult &rhs) { return getCaseNum(lhs) < getCaseNum(rhs); });

    std::swap(results.labels, newLabels);
    std::swap(results.results, newResults);
}

void ToolResults::writeAnnotatedResults(const std::filesystem::path &outputFile)
{
    std::ofstream str(outputFile);
    auto copyStrings = [&](const std::vector<std::string> &strings)
    { std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(str, "\n")); };
    copyStrings(m_preamble);
    bool first{true};
    for (const TestResultCollection &results : m_testResults)
    {
        const Test &test = getTestForPrefix(results.prefix);
        if (!first)
        {
            str << '\n';
        }
        str << "## " << results.title << '\n';
        if (!results.preamble.empty())
        {
            copyStrings(results.preamble);
        }
        for (const std::string &line : results.tableHeader)
        {
            str << line;
            if (line.find('|') != std::string::npos)
            {
                if (line.find("Case") != std::string::npos)
                {
                    str << " | Location";
                    if (test.hasDiffs())
                    {
                        str << " | Expected Diff";
                    }
                }
                else if (line.find('-') != std::string::npos)
                {
                    str << " | --------";
                    if (test.hasDiffs())
                    {
                        str << " | -------------";
                    }
                }
            }
            str << '\n';
        }
        const std::vector<TestCaseLocation> &locations = test.getCaseLocations();
        auto it = locations.begin();
        for (const TestResult &testResult : results.results)
        {
            if (it->label != getLabel(testResult))
            {
                throw std::runtime_error("Mismatched test case label " + it->label + " != " + getLabel(testResult));
            }
            const std::string file{it->sourceFile.filename().string()};
            const int line{it->line};
            str << testResult.line;
            if (testResult.deprecated)
            {
                str << " | |";
            }
            else
            {
                str << " | [`" << file << "`, line " << line
                    << "](https://github.com/LegalizeAdulthood/refactor-test-suite/blob/master/RefactorTest/" << file
                    << "#L" << line << ")";
                if (test.hasDiffs())
                {
                    str << " | [" << it->label
                        << ".txt](https://github.com/LegalizeAdulthood/refactor-test-suite/blob/master/results/diffs/"
                        << it->label << ".txt)";
                }
            }
            str << '\n';
            ++it;
        }
        first = false;
    }
}

}    // namespace testCases
