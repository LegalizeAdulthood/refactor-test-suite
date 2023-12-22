#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace testNames
{

void scanLine(const std::string &line)
{
    if (line.find("#TEST#") != std::string::npos)
    {
        size_t nonBlank = line.find_first_not_of(" \t");
        std::cout << "    " << line.substr(nonBlank) << '\n';
    }
}

void scanFile(std::filesystem::path path)
{
    std::cout << "File: " << path.string() << '\n';
    std::ifstream file(path.string());
    while (file)
    {
        std::string line;
        std::getline(file, line);
        scanLine(line);
    }
}

void scanDirectory(std::filesystem::path dir)
{
    std::cout << "Directory: " << dir.string() << '\n';
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanDirectory(entry);
        }
        else
        {
            scanFile(entry);
        }
    }
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
        if (args.size() < 2)
        {
            throw std::runtime_error("Missing directory argument");
        }

        scanDirectory(args[1]);
        return 0;
    }
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 2;
    }
}

}    // namespace testNames

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return testNames::main(args);
}
