#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace testNames
{

std::vector<std::string> g_labels;

void scanLine(const std::string &line)
{
    if (size_t pos = line.find("#TEST#"); pos != std::string::npos)
    {
        size_t begin = line.find_first_not_of(" \t", line.find_first_of(' ', pos));
        size_t end = line.find_first_of(' ', begin);
        std::string label = line.substr(begin, end - begin);
        if (std::find(g_labels.begin(), g_labels.end(), label) != g_labels.end())
        {
            std::cerr << "    ERROR Duplicate test label " << label << '\n';
        }
        std::cout << "    " << label << '\n';
        g_labels.emplace_back(std::move(label));
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
