#include <Main.h>
#include <TestCases.h>
#include <Tool.h>
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

std::map<std::string, std::string> g_toolTitles = {{"AppleXcode", "Xcode"},
                                                   {"ClangTidy", "clang-tidy"},
                                                   {"CLion", "CLion"},
                                                   {"EclipseCDT", "Eclipse CDT"},
                                                   {"QtCreator", "Qt Creator"},
                                                   {"ReSharperCpp", "ReSharper for C++"},
                                                   {"VisualAssistX", "Visual AssistX"},
                                                   {"VisualStudio", "Visual Studio"}};

class ToolSummarizer : public testCases::Tool
{
public:
    ToolSummarizer(std::string_view testCaseDir, std::string_view resultDir, bool annotate);

    void generateSummary();
    void generateAnnotatedToolResults();
    void generateReport();

private:
    void scanResultsDirectory(std::filesystem::path dir);

    std::vector<testCases::ToolResults> m_toolResults;
    bool m_annotate;
};

ToolSummarizer::ToolSummarizer(std::string_view testCaseDir, std::string_view resultDir, bool annotate) :
    Tool(testCaseDir, resultDir),
    m_annotate(annotate)
{
    scanResultsDirectory(resultDir);
}

void ToolSummarizer::scanResultsDirectory(std::filesystem::path dir)
{
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry) || !testCases::isResultsFile(entry))
        {
            continue;
        }
        m_toolResults.emplace_back(entry);
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

void ToolSummarizer::generateSummary()
{
    std::vector<ToolSummary> summary;
    for (testCases::ToolResults &toolResult : m_toolResults)
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
        const std::string &toolTitle = it->second;
        std::cout << " | [" << toolTitle << "](results/" << (m_annotate ? "annotated/" : "") << tool.name
                  << "Results.md)";
        separator += " | " + std::string(toolTitle.length(), '-');
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

void ToolSummarizer::generateAnnotatedToolResults()
{
    for (testCases::ToolResults &toolResult : m_toolResults)
    {
        toolResult.writeAnnotatedResults(getResultsDir() / "annotated" / toolResult.getPath().filename());
    }
}

void ToolSummarizer::generateReport()
{
    if (m_annotate)
    {
        generateAnnotatedToolResults();
    }
    generateSummary();
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " [--annotate] <RefactorTest> <results>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    bool annotate{};
    if (args.size() == 4)
    {
        if (args[1] == "--annotate")
        {
            annotate = true;
            args.erase(args.begin() + 1);
        }
        else
        {
            return usage(args[0]);
        }
    }
    if (args.size() != 3)
    {
        return usage(args[0]);
    }

    const std::string_view testCaseDir{args[1]};
    const std::string_view resultDir{args[2]};
    ToolSummarizer(testCaseDir, resultDir, annotate).generateReport();
    return 0;
}
