#include <FileContents.h>
#include <Main.h>
#include <TestCases.h>

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

class TestDiffs
{
public:
    TestDiffs(std::filesystem::path testCaseDir, std::filesystem::path diffDir);
    void checkDiffs();

private:
    void scanDiffDirectory();

    std::filesystem::path m_diffDir;
    std::vector<std::string> m_diffNames;
};

TestDiffs::TestDiffs(std::filesystem::path testCaseDir, std::filesystem::path diffDir) :
    m_diffDir(diffDir)
{
    if (const std::vector<std::string> errors = testCases::Test::scanTestDirectory(testCaseDir); !errors.empty())
    {
        for (const std::string &message : errors)
        {
            std::cerr << "error: " << message << '\n';
        }
        throw std::runtime_error("Test cases have errors");
    }
    scanDiffDirectory();
}

void TestDiffs::scanDiffDirectory()
{
    const auto isTestCaseDiff = [](const std::filesystem::path &path)
    {
        if (path.extension().string() != ".txt")
        {
            return false;
        }
        const std::string text{path.stem().string()};
        std::size_t pos = text.find_first_of("0123456789");
        return pos != std::string::npos;
    };
    for (auto &entry : std::filesystem::directory_iterator(m_diffDir))
    {
        if (!isTestCaseDiff(entry))
        {
            continue;
        }
        m_diffNames.emplace_back(entry.path().stem().string());
    }
}

bool diffsEqual(const testCases::FileContents &master, const testCases::FileContents &alias)
{
    if (master.getLines().size() != alias.getLines().size())
    {
        return false;
    }

    for (std::size_t line = 0; line < master.getLines().size(); ++line)
    {
        if (master.getLines()[line] != alias.getLines()[line])
        {
            return false;
        }
    }
    return true;
}

void TestDiffs::checkDiffs()
{
    for (const testCases::Test &test : testCases::getTests())
    {
        if (!test.hasDiffs())
        {
            continue;
        }

        for (const std::string &testCase : test.getCases())
        {
            if (std::find(m_diffNames.begin(), m_diffNames.end(), testCase) == m_diffNames.end())
            {
                std::cout << "warning: Test case " << testCase << " has no diff.\n";
            }
            else
            {
                std::ifstream str(m_diffDir / (testCase + ".txt"));
                std::string line;
                std::getline(str, line);
                if (line == testCases::g_diffPlaceholder)
                {
                    std::cout << "warning: Test case " << testCase << " has a placeholder diff.\n";
                }
            }
        }

        for (const testCases::TestCaseAlias &alias : test.getCaseAliases())
        {
            testCases::FileContents masterContents(m_diffDir / (alias.master + ".txt"));

            for (const std::string &aliasName : alias.aliases)
            {
                testCases::FileContents aliasContents(m_diffDir / (aliasName + ".txt"));
                if (!diffsEqual(masterContents, aliasContents))
                {
                    std::cout << "warning: Test case " << aliasName << " is marked as an alias of " << alias.master
                              << ", but has a different diff.\n";
                }
            }
        }
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results/diffs>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 3)
    {
        return usage(args[0]);
    }

    const std::string_view testCaseDir{args[1]};
    const std::string_view diffDir{args[2]};
    TestDiffs(testCaseDir, diffDir).checkDiffs();
    return 0;
}
