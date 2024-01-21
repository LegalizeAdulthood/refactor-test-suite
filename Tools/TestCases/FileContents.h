#pragma once

#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

namespace testCases
{

struct FileContents
{
    FileContents() = default;
    explicit FileContents(std::filesystem::path sourceFile);

    const std::filesystem::path &getPath() const
    {
        return m_path;
    }
    const std::vector<std::string> &getLines() const
    {
        return m_lines;
    }

    void transform(const std::function<std::string(std::string)> &operation) const;

private:
    std::filesystem::path m_path;
    std::vector<std::string> m_lines;
};

std::vector<FileContents> readCaseDiffs(const std::filesystem::path &caseDiffsDir, const std::string &prefix);

}    // namespace testCases
