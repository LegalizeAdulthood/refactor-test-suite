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
    int passes;
    int failures;
    int numCases;
    int numCasesReported;
};

class ToolResults
{
public:
    explicit ToolResults(std::string name) : m_name(std::move(name))
    {
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
    void scanResultsFile(std::filesystem::path path);
    bool markedDeprecated(const std::string &label);
    void checkResults();
    std::vector<TestSummary> getSummary() const;

private:
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
