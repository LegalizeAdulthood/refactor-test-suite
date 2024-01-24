#include <FileContents.h>
#include <Main.h>
#include <TestCases.h>
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

const testCases::Test &getTestCase(const std::filesystem::path &testCaseDir, std::string_view prefix)
{
    const std::vector<std::string> errors = testCases::Test::scanTestDirectory(testCaseDir);
    if (!errors.empty())
    {
        for (const std::string &error : errors)
        {
            std::cerr << "error: " << error << '\n';
        }
        throw std::runtime_error("Test cases contain errors:");
    }

    return testCases::getTestForPrefix(prefix);
}

class AddTests
{
public:
    AddTests(const std::filesystem::path &testCaseDir,
             std::string_view prefix,
             const std::filesystem::path &sourceFile,
             const std::filesystem::path &resultsDir);

    bool readSourceFile(std::string_view sourceFile);
    void writeSourceFile();
    void updateResultsFile(const std::filesystem::path &file);
    void updateResultsDir(const std::filesystem::path &dir);
    void writePlaceholderDiffs(const std::filesystem::path &diffDir);

    const testCases::Test &m_test;
    testCases::FileContents m_sourceContents;
    std::vector<std::string> m_newLabels;
};

AddTests::AddTests(const std::filesystem::path &testCaseDir,
                   std::string_view prefix,
                   const std::filesystem::path &sourceFile,
                   const std::filesystem::path &resultsDir) :
    m_test(getTestCase(testCaseDir, prefix)),
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

void AddTests::writePlaceholderDiffs(const std::filesystem::path &diffDir)
{
    for (const std::string &label : m_newLabels)
    {
        std::ofstream str(diffDir / (label + ".txt"));
        str << testCases::g_diffPlaceholder << '\n';
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <TestPrefix> <SourceFile.cpp> <ResultsDir>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 5)
    {
        return usage(args[0]);
    }
    const std::filesystem::path testCaseDir{args[1]};
    if (!is_directory(testCaseDir))
    {
        std::cerr << "Test case directory " << testCaseDir << " does not exist.\n";
        return 1;
    }
    const std::string_view testPrefix{args[2]};
    const std::filesystem::path sourceFile{args[3]};
    if (!exists(sourceFile))
    {
        std::cerr << "File " << sourceFile << " does not exist.\n";
        return 1;
    }
    const std::filesystem::path resultsDir{args[4]};
    if (!is_directory(resultsDir))
    {
        std::cerr << "Results case directory " << resultsDir << " does not exist.\n";
        return 1;
    }

    AddTests tool(testCaseDir, testPrefix, sourceFile, resultsDir);
    tool.writeSourceFile();
    tool.updateResultsDir(resultsDir);
    tool.writePlaceholderDiffs(resultsDir / "diffs");
    return 0;
}
