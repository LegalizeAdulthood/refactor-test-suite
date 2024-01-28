#include <FileContents.h>
#include <IntList.h>
#include <Main.h>
#include <StringScanner.h>
#include <TestCases.h>
#include <Tool.h>
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

class DeleteTests : public testCases::Tool
{
public:
    DeleteTests(std::string_view testCaseDir,
                std::string_view resultsDir,
                std::string_view prefix,
                std::vector<int> deletions);

    void updateSourceFiles();
    void updateResults();

private:
    void updateFile(const testCases::FileContents &file);
    void updateToolResults(const std::filesystem::path &dir);
    void updateDiffs();

    std::string m_prefix;
    const testCases::Test &m_test;
    std::vector<std::string> m_deletions;
    bool m_updatingDIffs{};
};

DeleteTests::DeleteTests(std::string_view testCaseDir,
                         std::string_view resultsDir,
                         std::string_view prefix,
                         std::vector<int> deletions) :
    Tool(testCaseDir, resultsDir),
    m_prefix(prefix),
    m_test(testCases::getTestForPrefix(m_prefix))
{
    m_deletions.reserve(deletions.size());
    std::transform(deletions.begin(),
                   deletions.end(),
                   std::back_inserter(m_deletions),
                   [this](int alias) { return m_prefix + std::to_string(alias); });
}

void DeleteTests::updateFile(const testCases::FileContents &file)
{
    const auto removeLabel = [this](const std::string &line)
    {
        const std::string_view label = testCases::getTestCaseLabel(line);
        if (label.empty())
        {
            return line;
        }
        if (std::find(m_deletions.begin(), m_deletions.end(), std::string{label}) != m_deletions.end())
        {
            const auto firstNonSpace = line.find_first_not_of(" \t");
            const auto comment = line.find("//", firstNonSpace);
            if (comment == firstNonSpace)
            {
                // Lines in diffs lead with a change character, space for a context line.
                return m_updatingDIffs ? std::string{" "} : std::string{};
            }
            return line.substr(0, line.find_last_not_of(" \t", comment - 1) + 1);
        }
        const std::string_view alias = testCases::getTestCaseAlias(line);
        if (alias.empty())
        {
            return line;
        }
        if (std::find(m_deletions.begin(), m_deletions.end(), std::string{alias}) == m_deletions.end())
        {
            return line;
        }

        std::string result{line};
        testCases::StringScanner scanner(result);
        const auto aliasBegin = scanner.find_first_of('=').getPos();
        const auto aliasEnd = scanner.find_first_of(' ').find_first_not_of(' ').getPos();
        result.erase(aliasBegin, aliasEnd - aliasBegin);
        return result;
    };
    file.transform(removeLabel);
}

void DeleteTests::updateSourceFiles()
{
    m_updatingDIffs = false;
    for (const std::filesystem::path &path : m_test.getPaths())
    {
        updateFile(testCases::FileContents(path));
    }
}

void DeleteTests::updateDiffs()
{
    for (const testCases::FileContents &diff : getCaseDiffsForPrefix(m_prefix))
    {
        updateFile(diff);
    }

    if (std::filesystem::path fileDiff(getFileDiffForPrefix(m_prefix)); exists(fileDiff))
    {
        updateFile(testCases::FileContents(fileDiff));
    }

    for (const auto &entry : std::filesystem::directory_iterator(getDiffsDir()))
    {
        if (is_directory(entry))
        {
            continue;
        }

        if (std::find(m_deletions.begin(), m_deletions.end(), entry.path().stem()) != m_deletions.end())
        {
            remove(entry);
        }
    }
}

void DeleteTests::updateToolResults(const std::filesystem::path &dir)
{
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            updateToolResults(entry);
        }
        else if (testCases::isResultsFile(entry))
        {
            testCases::FileContents contents(entry);
            contents.deleteIf(
                [this](const std::string &line)
                {
                    testCases::StringScanner scanner(line);
                    auto beginLabel = scanner.find_first_not_of(' ').getPos();
                    auto endLabel = scanner.find_first_of(" |").getPos();
                    if (beginLabel != std::string::npos && endLabel != std::string::npos)
                    {
                        return std::find(m_deletions.begin(),
                                         m_deletions.end(),
                                         line.substr(beginLabel, endLabel - beginLabel))
                            != m_deletions.end();
                    }
                    return false;
                });
            contents.write();
        }
    }
}

void DeleteTests::updateResults()
{
    m_updatingDIffs = false;
    updateToolResults(getResultsDir());
    m_updatingDIffs = true;
    updateDiffs();
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results> <TestPrefix> <deletions>\n";
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
    const std::string_view resultsDir{args[2]};
    const std::string_view prefix{args[3]};
    const std::vector<int> deletions(testCases::parseIntList(args[4]));
    DeleteTests tool(testCaseDir, resultsDir, prefix, deletions);
    tool.updateSourceFiles();
    tool.updateResults();
    return 0;
}
