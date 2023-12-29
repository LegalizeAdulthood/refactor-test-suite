#include <TestCases.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace testCases
{

// Refactorings not requiring diffs are those that are not widely supported across tools and
// therefore specific to only one or two tools.
std::vector<Test> g_tests{
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
    {"Inline Type Alias", "ITA"},
    {"Inline Variable", "IV"},
    {"Make Method Static", "MMS"},
    {"Move Implementation to Source File", "MISF"},
    {"Move Method", "MM", false},
    {"Optimize Namespace References", "ONR", false},
    {"Remove Block Delimiter", "RBD"},
    {"Remove Unused Parameter", "RUP"},
    {"Rename", "R"},
    {"Reorder Parameters", "RP"},
    {"Replace auto With Type", "RAWT"},
    {"Replace auto_ptr With unique_ptr", "RAWU"},
    {"Replace If With Ternary", "RIT"},
    {"Replace Iterative For With Range For", "RIRF"},
    {"Replace NULL/0 With nullptr", "RZNP"},
    {"Replace String Literal With Raw String Literal", "RAW"},
    {"Replace Ternary With If", "RTI"},
    {"Replace typedef With Type Alias", "RTDTA"},
    {"Replace Type With auto", "RTWA"},
    {"Reverse Conditional", "RC"},
    {"Simplify Boolean Expression", "SB"},
    {"Split Initialization From Declaration", "SID"},
    {"Split Multi-Variable Declaration", "SMVD"},
};

std::map<const char *, std::vector<std::string>> g_testCases;
std::vector<std::string> g_labels;
std::vector<std::string> g_deprecatedLabels;
std::string g_currentFile;
int g_currentLine{};
std::vector<std::string> g_errors;
std::vector<std::string> g_warnings;

void checkLabel(std::string_view label, std::string_view desc)
{
    if (std::find(g_labels.begin(), g_labels.end(), label) != g_labels.end())
    {
        g_errors.emplace_back(g_currentFile + "(" + std::to_string(g_currentLine) + "): Duplicate test label "
                              + std::string{label});
        return;
    }
    const std::string_view prefix = label.substr(0, label.find_first_of("0123456789"));
    const auto pos =
        std::find_if(std::begin(g_tests), std::end(g_tests), [&](const Test &test) { return test.prefix == prefix; });
    if (pos == std::end(g_tests))
    {
        g_errors.emplace_back(g_currentFile + "(" + std::to_string(g_currentLine) + "): Unknown test prefix "
                              + std::string{prefix});
        return;
    }
    g_testCases[pos->prefix].emplace_back(label);
    g_labels.emplace_back(label);
    if (desc == "(deprecated)")
    {
        g_deprecatedLabels.emplace_back(label);
    }
}

void scanLine(std::string_view line)
{
    if (size_t pos = line.find("#TEST#"); pos != std::string::npos)
    {
        const size_t begin = line.find_first_not_of(" \t", line.find_first_of(' ', pos));
        const size_t end = line.find_first_of(' ', begin);
        const std::string_view label = line.substr(begin, end - begin);
        const std::string_view desc =
            end != std::string_view::npos ? line.substr(line.find_first_not_of(' ', end)) : "";
        checkLabel(label, desc);
    }
}

void scanFile(std::filesystem::path path)
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

void scanTestCaseDirectory(std::filesystem::path dir)
{
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanTestCaseDirectory(entry);
        }
        else
        {
            scanFile(entry);
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

std::vector<std::string> scanTestDirectory(std::string_view dir)
{
    scanTestCaseDirectory(dir);
    sortTestCases();
    return g_errors;
}

bool isDeprecatedLabel(const std::string &label)
{
    return std::find(g_deprecatedLabels.begin(), g_deprecatedLabels.end(), label) != g_deprecatedLabels.end();
}

const char *getPrefixForTestName(std::string_view name)
{
    auto pos =
        std::find_if(std::begin(g_tests), std::end(g_tests), [name](const Test &test) { return test.name == name; });
    return pos != std::end(g_tests) ? pos->prefix : nullptr;
}

}    // namespace testCases
