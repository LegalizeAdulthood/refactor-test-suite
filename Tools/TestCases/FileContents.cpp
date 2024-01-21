#include <FileContents.h>

namespace testTool
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

}    // namespace testTool
