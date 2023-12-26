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

void scanDirectory(std::filesystem::path dir)
{
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

void checkMissingTestCases()
{
    const auto extractCaseNum = [](const std::string &label)
    { return std::stoi(label.substr(label.find_first_of("0123456789"))); };
    for (const Test &test : g_tests)
    {
        int num{1};
        for (const std::string &testCase : g_testCases[test.prefix])
        {
            int caseNum = extractCaseNum(testCase);
            do
            {
                if (num != caseNum)
                {
                    g_warnings.emplace_back(std::string{"Missing test case "} + test.prefix + std::to_string(num));
                }
            } while (num++ != caseNum);
        }
    }
}

void printMarkDown(std::ostream &out)
{
    if (!g_errors.empty())
    {
        for (const std::string &error : g_errors)
        {
            std::cerr << error << '\n';
        }
        throw std::runtime_error("Test case errors detected");
    }
    if (!g_warnings.empty())
    {
        for (const std::string &warning : g_warnings)
        {
            std::cerr << "WARNING: " << warning << '\n';
        }
    }

    out << "# Tool\n\n";

    for (const Test &test : g_tests)
    {
        out << "\n## " << test.name
            << "\nCase | Result\n"
               "---- | ------\n";
        for (const std::string &testCase : g_testCases[test.prefix])
        {
            if (std::find(g_deprecatedLabels.begin(), g_deprecatedLabels.end(), testCase) != g_deprecatedLabels.end())
            {
                continue;
            }
            out << testCase << " | \n";
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
        sortTestCases();
        checkMissingTestCases();
        printMarkDown(std::cout);
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
