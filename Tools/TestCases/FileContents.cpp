#include <FileContents.h>

namespace testCases
{

FileContents::FileContents(std::filesystem::path sourceFile) :
    path(sourceFile)
{
    std::ifstream str(sourceFile.string());
    while (str)
    {
        std::string line;
        std::getline(str, line);
        if (str)
        {
            lines.emplace_back(std::move(line));
        }
    }
}

void FileContents::transform(std::filesystem::path destPath, std::function<std::string(std::string)> transform) const
{
    std::ofstream str(destPath);
    for (std::string line : lines)
    {
        str << transform(line) << '\n';
    }
}

std::vector<FileContents> readCaseDiffs(const std::filesystem::path &caseDiffsDir, const std::string &prefix)
{
    std::vector<FileContents> caseDiffs;
    const auto startsWith = [](const std::string &text, const std::string &prefix)
    { return text.substr(0, prefix.length()) == prefix; };
    const auto isTestCaseDiff = [startsWith, prefix](const std::filesystem::path &path)
    { return path.extension().string() == ".txt" && startsWith(path.stem().string(), prefix); };
    for (const auto &entry : std::filesystem::directory_iterator(caseDiffsDir))
    {
        if (entry.is_directory())
        {
            continue;
        }
        if (!isTestCaseDiff(entry))
        {
            continue;
        }
        caseDiffs.emplace_back(entry);
    }
    return caseDiffs;
}

}    // namespace testTool
