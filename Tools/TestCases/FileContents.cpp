#include <FileContents.h>

namespace testCases
{

FileContents::FileContents(std::filesystem::path sourceFile) :
    m_path(sourceFile)
{
    std::ifstream str(sourceFile.string());
    while (str)
    {
        std::string line;
        std::getline(str, line);
        if (str)
        {
            m_lines.emplace_back(std::move(line));
        }
    }
}

void FileContents::transform(const std::function<std::string(std::string)> &operation,
    const std::filesystem::path &dest) const
{
    std::ofstream str(dest);
    for (std::string line : m_lines)
    {
        str << operation(line) << '\n';
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

}    // namespace testCases
