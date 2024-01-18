#include <TestCases.h>
#include <ToolResults.h>

#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace
{

std::vector<testCases::ToolResults> g_toolResults;
std::map<std::string, std::string> g_toolTitles = {{"AppleXcode", "Xcode"},
                                                   {"ClangTidy", "clang-tidy"},
                                                   {"CLion", "CLion"},
                                                   {"EclipseCDT", "Eclipse CDT"},
                                                   {"QtCreator", "Qt Creator"},
                                                   {"ReSharperCpp", "ReSharper for C++"},
                                                   {"VisualAssistX", "Visual AssistX"},
                                                   {"VisualStudio", "Visual Studio"}};

void scanResultsDirectory(std::filesystem::path dir)
{
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            continue;
        }

        const std::string toolName = testCases::toolNameFromResultsFile(entry.path());
        if (toolName.empty())
        {
            continue;
        }
        g_toolResults.emplace_back(entry);
    }
}

struct ToolSummary
{
    std::string name;
    std::vector<testCases::TestSummary> summary;
};

std::string percent(int numerator, int denominator)
{
    std::ostringstream str;
    const double fraction = 100.0 * double(numerator) / double(denominator);
    str << std::setprecision(4) << fraction << '%';
    return str.str();
}

void reportSummary()
{
    std::vector<ToolSummary> summary;
    for (testCases::ToolResults &toolResult : g_toolResults)
    {
        toolResult.checkResults();
        summary.push_back({toolResult.getToolName(), toolResult.getSummary()});
    }

    constexpr std::string_view refactoring{"Refactoring"};
    std::cout << "# Summary Results\n"
                 "\n"
              << refactoring;
    std::string separator(refactoring.length(), '-');
    for (const ToolSummary &tool : summary)
    {
        auto it = g_toolTitles.find(tool.name);
        if (it == g_toolTitles.end())
        {
            throw std::runtime_error("Unknown tool " + tool.name);
        }
        const std::string toolName = it->second;
        std::cout << " | [" << toolName << "](results/" << tool.name << "Results.md)";
        separator += " | " + std::string(toolName.length(), '-');
    }
    std::cout << '\n' << separator << '\n';

    for (const testCases::Test &test : testCases::getTests())
    {
        bool hasResult{};
        std::ostringstream line;
        line << test.getName();
        for (const ToolSummary &tool : summary)
        {
            line << " | ";
            auto it = std::find_if(tool.summary.begin(),
                                   tool.summary.end(),
                                   [prefix = test.getPrefix()](const testCases::TestSummary &testSummary)
                                   { return testSummary.name == prefix; });
            if (it == tool.summary.end())
            {
                line << "(n/a)";
            }
            else
            {
                line << percent(it->numPassed, it->numCasesReported) << " (" << it->numCasesReported << '/'
                     << it->numCases << ')';
                hasResult = true;
            }
        }
        line << '\n';
        if (hasResult)
        {
            std::cout << line.str();
        }
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results>\n";
    return 1;
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
        if (args.size() < 3)
        {
            return usage(args[0]);
        }

        testCases::Test::scanTestDirectory(args[1]);
        scanResultsDirectory(args[2]);
        reportSummary();
        return 0;
    }
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 2;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 3;
    }
}

}    // namespace

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return main(args);
}
