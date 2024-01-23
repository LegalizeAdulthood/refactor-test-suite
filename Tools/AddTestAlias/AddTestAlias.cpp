#include <FileContents.h>
#include <IntList.h>
#include <Main.h>
#include <StringScanner.h>
#include <TestCases.h>
#include <ToolResults.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

class AddTestAlias
{
public:
    AddTestAlias(std::string_view testCaseDir,
                 std::string_view resultsDir,
                 std::string_view prefix,
                 int master,
                 std::vector<int> aliases) :
        m_resultsDir(resultsDir),
        m_prefix(prefix),
        m_test(readTestCases(testCaseDir)),
        m_master(m_prefix + std::to_string(master))
    {
        m_aliases.reserve(aliases.size());
        std::transform(aliases.begin(),
                       aliases.end(),
                       std::back_inserter(m_aliases),
                       [this](int alias) { return m_prefix + std::to_string(alias); });
    }

    void updateSourceFiles();
    void updateResults();

private:
    const testCases::Test &readTestCases(std::string_view testCaseDir);
    void updateFile(const testCases::FileContents &file);

    std::filesystem::path m_resultsDir;
    std::string m_prefix;
    const testCases::Test &m_test;
    std::string m_master;
    std::vector<std::string> m_aliases;
};

const testCases::Test &AddTestAlias::readTestCases(std::string_view testCaseDir)
{
    const std::vector<std::string> errors = testCases::Test::scanTestDirectory(testCaseDir);
    if (!errors.empty())
    {
        for (const std::string &error : errors)
        {
            std::cerr << "error: " << error << '\n';
        }
        throw std::runtime_error("Test cases contain errors");
    }
    return testCases::getTestForPrefix(m_prefix);
}

void AddTestAlias::updateFile(const testCases::FileContents &file)
{
    auto updateLabel = [this](const std::string &line)
    {
        const std::string_view label = testCases::getTestCaseLabel(line);
        if (label.empty() || label == m_master)
            return line;
        if (std::find(m_aliases.begin(), m_aliases.end(), std::string{label}) == m_aliases.end())
            return line;

        std::string result{line};
        testCases::StringScanner scanner(result);
        auto pos = scanner.find(label).find_first_of(' ').find_first_not_of(' ').getPos();
        if (pos != std::string::npos)
        {
            result.insert(pos, "=" + m_master + ' ');
        }
        return result;
    };
    file.transform(updateLabel);
}

void AddTestAlias::updateSourceFiles()
{
    for (const std::filesystem::path &path : m_test.getPaths())
    {
        updateFile(testCases::FileContents(path));
    }
}

void AddTestAlias::updateResults()
{
    for (const testCases::FileContents &diff : testCases::readCaseDiffs(m_resultsDir / "diffs", m_prefix))
    {
        updateFile(diff);
    }
    if (std::filesystem::path fileDiff(m_resultsDir / "file-diffs" / (m_prefix + ".txt")); exists(fileDiff))
    {
        updateFile(testCases::FileContents(fileDiff));
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results> <TestPrefix> <master> <aliases>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 6)
    {
        return usage(args[0]);
    }
    const std::string_view testCaseDir{args[1]};
    const std::string_view resultsDir{args[2]};
    const std::string_view prefix{args[3]};
    const int master = std::stoi(std::string{args[4]});
    const std::vector<int> aliases(testCases::parseIntList(args[5]));
    if (std::find(aliases.begin(), aliases.end(), master) != aliases.end())
    {
        throw std::runtime_error("Master test can't be included in the alias list.");
    }
    AddTestAlias tool(testCaseDir, resultsDir, prefix, master, aliases);
    tool.updateSourceFiles();
    tool.updateResults();
    return 0;
}
