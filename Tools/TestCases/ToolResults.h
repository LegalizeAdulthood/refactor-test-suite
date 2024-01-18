#pragma once

#include <filesystem>
#include <map>
#include <ostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace testCases
{

struct TestResult
{
    std::string line;
    bool hasResult;
    bool deprecated;
    bool passed;
};

inline std::string toolNameFromResultsFile(std::filesystem::path path)
{
    const std::string file = path.filename().string();
    const auto pos = file.find("Results.md");
    if (pos == std::string::npos)
        return {};
    return file.substr(0, pos);
}

inline bool isResultsFile(std::filesystem::path path)
{
    return !toolNameFromResultsFile(path).empty();
}

struct TestSummary
{
    std::string name;
    int numPassed;
    int numFailed;
    int numDeprecated;
    int numCases;
    int numCasesReported;
};

class ToolResults
{
public:
    ToolResults(std::filesystem::path path) :
        m_path(path),
        m_name(toolNameFromResultsFile(path))
    {
        scanResultsFile();
    }

    const std::filesystem::path &getPath() const
    {
        return m_path;
    }
    const std::string &getToolName() const
    {
        return m_name;
    }
    const std::vector<std::string> &getWarnings() const
    {
        return m_warnings;
    }
    const std::vector<std::string> &getErrors() const
    {
        return m_errors;
    }
    void checkResults();
    std::vector<TestSummary> getSummary() const;
    bool addTests(const std::string &prefix, const std::vector<std::string> &labels);
    void writeResults();
    bool hasResultsForPrefix(std::string_view prefix) const;
    void renameTestCases(std::string_view prefix,
                         const std::vector<std::string_view> &before,
                         const std::vector<std::string_view> &after);

private:
    struct TestResultCollection
    {
        std::string title;
        std::string prefix;
        std::vector<std::string> preamble;
        std::vector<std::string> tableHeader;
        std::vector<TestResult> results;
        std::vector<std::string> labels;

        bool isMarkedDeprecated(const std::string &label) const;
    };

    void scanResultsFile();
    TestResultCollection &getTestResultsForPrefix(std::string_view prefix);

    std::filesystem::path m_path;
    std::string m_name;
    std::vector<std::string> m_warnings;
    std::vector<std::string> m_errors;
    std::vector<std::string> m_diffs;
    std::vector<std::string> m_preamble;
    std::vector<std::string> m_testPrefixes;
    std::vector<TestResultCollection> m_testResults;
};

}    // namespace testCases
