#pragma once

#include <filesystem>
#include <map>
#include <ostream>
#include <string>
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
using ToolTestResults = std::map<std::string, std::vector<TestResult>>;
using ToolTestResultsLabels = std::map<std::string, std::vector<std::string>>;

inline std::string toolNameFromResultsFile(std::filesystem::path path)
{
    const std::string file = path.filename().string();
    const auto pos = file.find("Results.md");
    if (pos == std::string::npos)
        return {};
    return file.substr(0, pos);
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
        m_path(std::move(path)),
        m_name(std::move(toolNameFromResultsFile(path)))
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
    bool markedDeprecated(const std::string &label);
    void checkResults();
    std::vector<TestSummary> getSummary() const;

private:
    void scanResultsFile();

    std::filesystem::path m_path;
    std::string m_name;
    std::vector<std::string> m_warnings;
    std::vector<std::string> m_errors;
    std::vector<std::string> m_diffs;
    std::vector<std::string> m_preamble;
    std::vector<const char *> m_testReports;
    ToolTestResults m_testResults;
    ToolTestResultsLabels m_testResultsLabels;
};

}    // namespace testCases
