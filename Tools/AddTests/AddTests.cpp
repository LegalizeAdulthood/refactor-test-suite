#include <FileContents.h>
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

class AddTests
{
public:
    bool readTestCases(std::string_view testCaseDirectory);
    bool setTestCasePrefix(std::string_view prefix);
    bool readSourceFile(std::string_view sourceFile);
    void writeSourceFile();
    void updateResultsFile(std::filesystem::path file);
    void updateResultsDir(std::filesystem::path dir);

    std::string m_testPrefix;
    int m_numTestCases{};
    std::string m_sourceFile;
    testCases::FileContents m_sourceContents;
    std::vector<std::string> m_newLabels;
};

bool AddTests::readTestCases(std::string_view testCaseDirectory)
{
    const std::vector<std::string> errors = testCases::Test::scanTestDirectory(testCaseDirectory);
    if (!errors.empty())
    {
        std::cerr << "Test cases contain errors:\n";
        for (const std::string &error : errors)
        {
            std::cerr << error << '\n';
        }
        return false;
    }
    return true;
}

bool AddTests::setTestCasePrefix(std::string_view prefix)
{
    const testCases::Test &test = testCases::getTestForPrefix(prefix);
    m_testPrefix = test.getPrefix();
    m_numTestCases = static_cast<int>(test.getNumTestCases());
    return true;
}

bool AddTests::readSourceFile(std::string_view sourceFile)
{
    if (!std::filesystem::exists(sourceFile))
    {
        std::cerr << "File " << sourceFile << " does not exist.";
        return false;
    }
    m_sourceContents = testCases::FileContents(sourceFile);
    copy_file(sourceFile, std::string{sourceFile} + ".bak", std::filesystem::copy_options::overwrite_existing);
    m_sourceFile = sourceFile;
    return true;
}

void AddTests::writeSourceFile()
{
    std::string marker{"#GOINK#: "};
    int testNum{m_numTestCases};
    std::ofstream str(m_sourceFile);
    auto replaceMarkers = [&](const std::string &line)
    {
        std::string result{line};
        const auto goink = result.find(marker);
        if (goink != std::string::npos)
        {
            ++testNum;
            auto markerEnd = result.find_first_of(' ', goink + marker.length());
            m_newLabels.emplace_back(m_testPrefix + std::to_string(testNum));
            result = result.substr(0, goink) + "#TEST#: " + m_newLabels.back() + result.substr(markerEnd);
        }
        return result;
    };
    m_sourceContents.transform(replaceMarkers);
}

void AddTests::updateResultsFile(std::filesystem::path file)
{
    testCases::ToolResults results(file);
    if (results.addTests(m_testPrefix, m_newLabels))
    {
        results.writeResults();
    }
}

void AddTests::updateResultsDir(std::filesystem::path dir)
{
    for (auto entry : std::filesystem::directory_iterator(dir))
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

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <TestPrefix> <SourceFile.cpp> <ResultsDir>\n";
    return 1;
}

int main(std::vector<std::string_view> args)
{
    try
    {
        if (args.size() < 5)
        {
            return usage(args[0]);
        }
        AddTests tool;
        if (!tool.readTestCases(args[1]) || !tool.setTestCasePrefix(args[2]) || !tool.readSourceFile(args[3]))
        {
            return 1;
        }
        tool.writeSourceFile();
        tool.updateResultsDir(args[4]);
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
