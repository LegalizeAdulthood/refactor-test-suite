#include <TestCases.h>

#include "Tool.h"

#include <iostream>
#include <stdexcept>

namespace testCases
{

Tool::Tool(std::string_view testCaseDir, std::string_view resultsDir) :
    m_testCaseDir(testCaseDir),
    m_resultsDir(resultsDir),
    m_diffsDir(m_resultsDir / "diffs"),
    m_fileDiffsDir(m_resultsDir / "file-diffs")
{
    if (const std::vector<std::string> errors = Test::scanTestDirectory(testCaseDir); !errors.empty())
    {
        for (const std::string &message : errors)
        {
            std::cerr << "error: " << message << '\n';
        }
        throw std::runtime_error("Test cases contain errors");
    }
}

std::filesystem::path Tool::getFileDiffForPrefix(const std::string &prefix) const
{
    return m_fileDiffsDir / (prefix + ".txt");
}

std::vector<FileContents> Tool::getCaseDiffsForPrefix(std::string_view prefix)
{
    return readCaseDiffs(m_diffsDir, prefix);
}

}    // namespace testCases
