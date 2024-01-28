#include <FileContents.h>
#include <Main.h>
#include <TestCases.h>
#include <Tool.h>
#include <ToolResults.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

class AddTests : public testCases::Tool
{
public:
    AddTests(std::string_view testCaseDir, std::string_view resultsDir,
             std::string_view prefix,
             const std::filesystem::path &sourceFile);

    void writeSourceFile();
    void updateResults();
    void writePlaceholderDiffs();

private:
    void updateResultsDir(const std::filesystem::path &dir);
    void updateResultsFile(const std::filesystem::path &file);

    const testCases::Test &m_test;
    testCases::FileContents m_sourceContents;
    std::vector<std::string> m_newLabels;
};

AddTests::AddTests(std::string_view testCaseDir,
                   std::string_view resultsDir,
                   std::string_view prefix,
                   const std::filesystem::path &sourceFile) :
    Tool(testCaseDir, resultsDir),
    m_test(testCases::getTestForPrefix(prefix)),
    m_sourceContents(sourceFile)
{
}

void AddTests::writeSourceFile()
{
    std::string marker{"#GOINK#: "};
    int testNum{static_cast<int>(m_test.getNumTestCases())};
    auto replaceMarkers = [&, this](const std::string &line)
    {
        std::string result{line};
        const auto goink = result.find(marker);
        if (goink != std::string::npos)
        {
            ++testNum;
            const auto markerEnd = result.find_first_of(' ', goink + marker.length());
            m_newLabels.emplace_back(m_test.getPrefix() + std::to_string(testNum));
            result = result.substr(0, goink) + "#TEST#: " + m_newLabels.back() + result.substr(markerEnd);
        }
        return result;
    };
    m_sourceContents.transform(replaceMarkers);
}

void AddTests::updateResults()
{
    updateResultsDir(getResultsDir());
}

void AddTests::updateResultsFile(const std::filesystem::path &file)
{
    testCases::ToolResults results(file);
    if (results.addTests(m_test.getPrefix(), m_newLabels))
    {
        results.writeResults();
    }
}

void AddTests::updateResultsDir(const std::filesystem::path &dir)
{
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        const std::filesystem::path path = entry.path();
        if (is_directory(path))
        {
            updateResultsDir(path);
        }
        else if (testCases::isResultsFile(path))
        {
            updateResultsFile(path);
        }
    }
}

void AddTests::writePlaceholderDiffs()
{
    const std::filesystem::path diffDir(getDiffsDir());
    for (const std::string &label : m_newLabels)
    {
        std::ofstream str(diffDir / (label + ".txt"));
        str << testCases::g_diffPlaceholder << '\n';
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results> <TestPrefix> <SourceFile.cpp>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 5)
    {
        return usage(args[0]);
    }
    const std::string_view testCaseDir{args[1]};
    if (!is_directory(std::filesystem::path(testCaseDir)))
    {
        std::cerr << "Test case directory " << testCaseDir << " does not exist.\n";
        return 1;
    }
    const std::string_view resultsDir{args[2]};
    if (!is_directory(std::filesystem::path(resultsDir)))
    {
        std::cerr << "Results case directory " << resultsDir << " does not exist.\n";
        return 1;
    }
    const std::string_view testPrefix{args[3]};
    const std::filesystem::path sourceFile{args[4]};
    if (!exists(sourceFile))
    {
        std::cerr << "File " << sourceFile << " does not exist.\n";
        return 1;
    }

    AddTests tool(testCaseDir, resultsDir, testPrefix, sourceFile);
    tool.writeSourceFile();
    tool.updateResults();
    tool.writePlaceholderDiffs();
    return 0;
}
