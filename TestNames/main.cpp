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

struct Test
{
    const char *name;
    const char *prefix;
};

constexpr Test g_tests[]{
    {"Add Block Delimiter", "ABD"},
    {"Add Override", "AO"},
    {"Add Parameter", "AP"},
    {"Change Signature", "CS"},
    {"Create Method Stub", "CMS"},
    {"Create Multi-Variable Declaration", "CMVD"},
    {"Create Overload", "CO"},
    {"Create Setter Method", "CSM"},
    {"Extract Constant", "EC"},
    {"Extract Function", "EXF"},
    {"Extract Method", "EM"},
    {"Extract Parameter", "EP"},
    {"Extract Variable", "EXV"},
    {"Flatten Conditional", "FC"},
    {"Inline Macro", "IM"},
    {"Inline Recent Assignment", "IRA"},
    {"Inline Result", "IR"},
    {"Inline Variable", "IV"},
    {"Make Method Static", "MMS"},
    {"Move Implementation to Source File", "MISF"},
    {"Move Method", "MM"},
    {"Optimize Namespace References", "ONR"},
    {"Remove Block Delimiter", "RBD"},
    {"Remove Unused Parameter", "RUP"},
    {"Rename", "R"},
    {"Reorder Parameters", "RP"},
    {"Replace auto with Type", "RAWT"},
    {"Replace auto_ptr With unique_ptr", "RAWU"},
    {"Replace If With Ternary", "RIT"},
    {"Replace Iterative For With Range For", "RIRF"},
    {"Replace NULL/0 With nullptr", "RZNP"},
    {"Replace String Literal With Raw String Literal", "RAW"},
    {"Replace Ternary With If", "RTI"},
    {"Replace Type With auto", "RTWA"},
    {"Reverse Conditional", "RC"},
    {"Simplify Boolean Expression", "SB"},
    {"Split Initialization From Declaration", "SID"},
    {"Split Multi-Variable Declaration", "SMVD"},
};

std::vector<std::string> g_labels;

void checkLabel(std::string_view label)
{
    if (std::find(g_labels.begin(), g_labels.end(), label) != g_labels.end())
    {
        std::cerr << "    ERROR Duplicate test label " << label << '\n';
    }
    const std::string_view prefix = label.substr(0, label.find_first_of("0123456789"));
    const auto pos =
        std::find_if(std::begin(g_tests), std::end(g_tests), [&](const Test &test) { return test.prefix == prefix; });
    if (pos == std::end(g_tests))
    {
        std::cerr << "    ERROR Unknown test prefix " << prefix << '\n';
    }
    g_labels.emplace_back(std::move(label));
}

void scanLine(std::string_view line)
{
    if (size_t pos = line.find("#TEST#"); pos != std::string::npos)
    {
        size_t begin = line.find_first_not_of(" \t", line.find_first_of(' ', pos));
        size_t end = line.find_first_of(' ', begin);
        std::string_view label = line.substr(begin, end - begin);
        checkLabel(label);
        std::cout << "    " << label << '\n';
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
