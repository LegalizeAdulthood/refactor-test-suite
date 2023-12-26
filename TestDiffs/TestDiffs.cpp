#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
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
    bool required{true};    // true if diffs are required for this test case.
};

// Refactorings not requiring diffs are those that are not widely supported across tools and
// therefore specific to only one or two tools.
constexpr Test g_tests[]{
    {"Add Block Delimiter", "ABD"},
    {"Add Override", "AO"},
    {"Add Parameter", "AP"},
    {"Change Signature", "CS"},
    {"Create Method Stub", "CMS"},
    {"Create Multi-Variable Declaration", "CMVD"},
    {"Create Overload", "CO", false},
    {"Create Setter Method", "CSM", false},
    {"Extract Constant", "EC", false},
    {"Extract Function", "EXF"},
    {"Extract Method", "EM"},
    {"Extract Parameter", "EP", false},
    {"Extract Variable", "EXV"},
    {"Flatten Conditional", "FC"},
    {"Inline Macro", "IM"},
    {"Inline Recent Assignment", "IRA", false},
    {"Inline Result", "IR", false},
    {"Inline Variable", "IV"},
    {"Make Method Static", "MMS"},
    {"Move Implementation to Source File", "MISF"},
    {"Move Method", "MM", false},
    {"Optimize Namespace References", "ONR", false},
    {"Remove Block Delimiter", "RBD"},
    {"Remove Unused Parameter", "RUP"},
    {"Rename", "R"},
    {"Reorder Parameters", "RP"},
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

std::map<const char *, std::vector<std::string>> g_testCases;
std::vector<std::string> g_testLabels;
std::string g_currentFile;
int g_currentLine{};
std::vector<std::string> g_diffs;

void checkLabel(std::string_view label)
{
    if (std::find(g_testLabels.begin(), g_testLabels.end(), label) != g_testLabels.end())
    {
        throw std::runtime_error(g_currentFile + "(" + std::to_string(g_currentLine) + "): Duplicate test label "
                                 + std::string{label});
    }
    const std::string_view prefix = label.substr(0, label.find_first_of("0123456789"));
    const auto pos =
        std::find_if(std::begin(g_tests), std::end(g_tests), [&](const Test &test) { return test.prefix == prefix; });
    if (pos == std::end(g_tests))
    {
        throw std::runtime_error(g_currentFile + "(" + std::to_string(g_currentLine) + "): Unknown test prefix "
                                 + std::string{prefix});
    }
    g_testCases[pos->prefix].emplace_back(label);
    g_testLabels.emplace_back(label);
}

void scanLine(std::string_view line)
{
    if (size_t pos = line.find("#TEST#"); pos != std::string::npos)
    {
        size_t begin = line.find_first_not_of(" \t", line.find_first_of(' ', pos));
        size_t end = line.find_first_of(' ', begin);
        std::string_view label = line.substr(begin, end - begin);
        checkLabel(label);
    }
}

void scanTestFile(std::filesystem::path path)
{
    std::ifstream file(path.string());
    g_currentFile = path.string();
    g_currentLine = 0;
    while (file)
    {
        std::string line;
        std::getline(file, line);
        ++g_currentLine;
        scanLine(line);
    }
}

void scanTestDirectory(std::filesystem::path dir)
{
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanTestDirectory(entry);
        }
        else
        {
            scanTestFile(entry);
        }
    }
}

void sortTestCases()
{
    const auto extractCaseNum = [](const std::string &label)
    { return std::stoi(label.substr(label.find_first_of("0123456789"))); };
    for (const Test &test : g_tests)
    {
        std::vector<std::string> &testCases = g_testCases.find(test.prefix)->second;
        std::sort(testCases.begin(),
                  testCases.end(),
                  [&](const std::string &lhs, const std::string &rhs)
                  { return extractCaseNum(lhs) < extractCaseNum(rhs); });
    }
}

void scanDiffDirectory(std::filesystem::path dir)
{
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanDiffDirectory(entry);
        }
        else
        {
            g_diffs.emplace_back(entry.path().filename().string());
        }
    }
}

void checkDiffs(std::ostream &out)
{
    for (const Test &test : g_tests)
    {
        if (!test.required)
        {
            continue;
        }

        for (const std::string &testCase : g_testCases[test.prefix])
        {
            if (std::find(g_diffs.begin(), g_diffs.end(), testCase + ".txt") == g_diffs.end())
            {
                out << "Test case " << testCase << " has no diff.\n";
            }
        }
    }
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
        if (args.size() < 3)
        {
            throw std::runtime_error("Missing directory arguments");
        }

        scanTestDirectory(args[1]);
        sortTestCases();
        scanDiffDirectory(args[2]);
        checkDiffs(std::cout);
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
