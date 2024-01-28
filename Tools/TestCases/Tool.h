#pragma once

#include <FileContents.h>

#include <filesystem>
#include <string_view>

namespace testCases
{

class Tool
{
public:
    Tool(std::string_view testCaseDir, std::string_view resultsDir);

    const std::filesystem::path &getTestCaseDir() const
    {
        return m_testCaseDir;
    }
    const std::filesystem::path &getResultsDir() const
    {
        return m_resultsDir;
    }
    const std::filesystem::path &getDiffsDir() const
    {
        return m_diffsDir;
    }
    std::filesystem::path getFileDiffForPrefix(const std::string &prefix) const;
    std::vector<FileContents> getCaseDiffsForPrefix(std::string_view prefix);

private:
    std::filesystem::path m_testCaseDir;
    std::filesystem::path m_resultsDir;
    std::filesystem::path m_diffsDir;
    std::filesystem::path m_fileDiffsDir;
};

}    // namespace testCases
