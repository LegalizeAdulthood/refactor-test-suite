#pragma once

#include <filesystem>
#include <functional>
#include <string>
#include <string_view>
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

    void transform(const std::function<std::string(std::string)> &operation, const std::filesystem::path &dest) const;
    void transform(const std::function<std::string(std::string)> &operation) const
    {
        transform(operation, m_path);
    }
    void deleteIf(const std::function<bool(const std::string &line)> &predicate);
    void write();

private:
    std::filesystem::path m_path;
    std::vector<std::string> m_lines;
};

std::vector<FileContents> readCaseDiffs(const std::filesystem::path &caseDiffsDir, std::string_view prefix);

}    // namespace testCases
