#pragma once

#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

namespace testTool
{

struct FileContents
{
    FileContents() = default;
    explicit FileContents(std::filesystem::path sourceFile);

    const std::filesystem::path &getPath() const
    {
        return path;
    }
    const std::vector<std::string> &getLines() const
    {
        return lines;
    }

    void transform(std::filesystem::path destPath, std::function<std::string(std::string)> transform) const;

private:
    std::filesystem::path path;
    std::vector<std::string> lines;
};

}    // namespace testTool
