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

std::string g_testPrefix;
int g_numTestCases{};
std::string g_sourceFile;
std::vector<std::string> g_sourceLines;
std::vector<std::string> g_newLabels;

bool readTestCases(std::string_view testCaseDirectory)
{
    std::vector<std::string> errors = testCases::scanTestDirectory(testCaseDirectory);
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

bool setTestCasePrefix(std::string_view prefix)
{
    const std::vector<testCases::Test> &tests = testCases::getTests();
    auto it =
        std::find_if(tests.begin(), tests.end(), [&](const testCases::Test &test) { return test.prefix == prefix; });
    if (it == tests.end())
    {
        std::cerr << "Unknown test prefix '" << prefix << "'\n";
        return false;
    }
    g_testPrefix = it->prefix;
    g_numTestCases = static_cast<int>(testCases::getNumTestCases(it->prefix));
    return true;
}

bool readSourceFile(std::string_view sourceFile)
{
    if (!std::filesystem::exists(sourceFile))
    {
        std::cerr << "File " << sourceFile << " does not exist.";
        return false;
    }
    {
        std::ifstream str(sourceFile.data());
        while (str)
        {
            std::string line;
            std::getline(str, line);
            g_sourceLines.emplace_back(std::move(line));
        }
    }
    copy_file(sourceFile, std::string{sourceFile} + ".bak", std::filesystem::copy_options::overwrite_existing);
    g_sourceFile = sourceFile;
    return true;
}

void writeSourceFile()
{
    std::string marker{"#GOINK#: "};
    int testNum{g_numTestCases};
    std::ofstream str(g_sourceFile);
    for (std::string line : g_sourceLines)
    {
        const auto goink = line.find(marker);
        if (goink != std::string::npos)
        {
            ++testNum;
            auto markerEnd = line.find_first_of(' ', goink + marker.length());
            g_newLabels.emplace_back(g_testPrefix + std::to_string(testNum));
            line = line.substr(0, goink) + "#TEST#: " + g_newLabels.back() + line.substr(markerEnd);
        }
        str << line << '\n';
    }
}

void updateResultsFile(std::filesystem::path file)
{
    testCases::ToolResults results(file);
    if (results.addTests(g_testPrefix, g_newLabels))
    {
        results.writeResults();
    }
}

void updateResultsDir(std::filesystem::path dir)
{
    const auto endsWith = [](const std::string &text, const std::string &suffix)
    { return text.length() > suffix.length() && text.substr(text.length() - suffix.length()) == suffix; };
    const auto isResultsFile = [&](const std::filesystem::path &path)
    { return endsWith(path.filename().string(), "Results.md"); };

    for (auto entry : std::filesystem::directory_iterator(dir))
    {
        const std::filesystem::path path = entry.path();
        if (is_directory(path))
        {
            updateResultsDir(path);
        }
        else if (isResultsFile(path))
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
        if (!readTestCases(args[1]) || !setTestCasePrefix(args[2]) || !readSourceFile(args[3]))
        {
            return 1;
        }
        writeSourceFile();
        updateResultsDir(args[4]);
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
