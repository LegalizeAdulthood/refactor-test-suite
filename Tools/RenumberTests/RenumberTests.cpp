#include <FileContents.h>
#include <Main.h>
#include <TestCases.h>
#include <ToolResults.h>

#include <algorithm>
#include <filesystem>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

struct CaseMapping
{
    std::string before;
    std::string after;
};

class Processor
{
public:
    Processor(const std::filesystem::path &resultsDir, std::string_view prefix);

    void renumber();
    void writeResults();

private:
    void scanResultsDir(const std::filesystem::path &dir);
    void readDiffs();
    void readCaseDiffs();
    void readFileDiff();
    std::string findMapping(std::string_view label) const;
    void writeTransformedFileContents(const testCases::FileContents &contents, const std::filesystem::path &dest);
    void writeTransformedFileContentsInPlace(const testCases::FileContents &contents)
    {
        writeTransformedFileContents(contents, contents.getPath());
    }
    void writeSourceFiles();
    const testCases::FileContents &getCaseDiffForLabel(const std::string &label);
    void writeDiffs();
    void writeToolResults();

    const testCases::Test &m_test;
    std::vector<testCases::ToolResults> m_toolResults;
    std::vector<CaseMapping> m_mapping;
    std::vector<testCases::FileContents> m_sourceFiles;
    std::vector<testCases::FileContents> m_caseDiffs;
    testCases::FileContents m_fileDiff;
    std::filesystem::path m_resultsDir;
    std::vector<std::string> m_missingDiffs;
};

Processor::Processor(const std::filesystem::path &resultsDir, std::string_view prefix) :
    m_test(testCases::getTestForPrefix(prefix)),
    m_resultsDir(resultsDir)
{
    m_sourceFiles.reserve(m_test.getPaths().size());
    for (const std::filesystem::path &path : m_test.getPaths())
    {
        m_sourceFiles.emplace_back(path);
    }
    scanResultsDir(m_resultsDir);
    readDiffs();
}

void Processor::scanResultsDir(const std::filesystem::path &dir)
{
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanResultsDir(entry);
        }
        else if (testCases::isResultsFile(entry))
        {
            testCases::ToolResults toolResults(entry);
            if (toolResults.hasResultsForPrefix(m_test.getPrefix()))
            {
                m_toolResults.emplace_back(std::move(toolResults));
            }
        }
    }
}

void Processor::readDiffs()
{
    if (!m_test.hasDiffs())
    {
        return;
    }

    readCaseDiffs();
    readFileDiff();
}

void Processor::readCaseDiffs()
{
    m_caseDiffs = testCases::readCaseDiffs(m_resultsDir / "diffs", m_test.getPrefix());
}

void Processor::readFileDiff()
{
    if (const std::filesystem::path fileDiff(m_resultsDir / "file-diffs" / (m_test.getPrefix() + ".txt"));
        exists(fileDiff))
    {
        m_fileDiff = testCases::FileContents(fileDiff);
    }
}

void Processor::renumber()
{
    int testCaseNum{};
    for (const testCases::FileContents &sourceFile : m_sourceFiles)
    {
        for (const std::string &line : sourceFile.getLines())
        {
            const std::string label{testCases::getTestCaseLabel(line)};
            if (label.empty())
            {
                continue;
            }

            ++testCaseNum;
            m_mapping.push_back({label, m_test.getPrefix() + std::to_string(testCaseNum)});
        }
    }

    for (const CaseMapping &map : m_mapping)
    {
        auto it = std::find_if(m_caseDiffs.begin(),
                               m_caseDiffs.end(),
                               [&](const testCases::FileContents &contents)
                               { return contents.getPath().stem().string() == map.before; });
        if (it == m_caseDiffs.end())
        {
            m_missingDiffs.push_back(map.before);
        }
    }
}

std::string Processor::findMapping(std::string_view label) const
{
    const auto it = std::find_if(
        m_mapping.begin(), m_mapping.end(), [&](const CaseMapping &mapping) { return mapping.before == label; });
    if (it == m_mapping.end())
    {
        throw std::runtime_error("Unknown test case label " + std::string{label});
    }
    return it->after;
}

void Processor::writeTransformedFileContents(const testCases::FileContents &contents, const std::filesystem::path &dest)
{
    auto renumberLabel = [this](const std::string &line)
    {
        std::string result{line};
        if (line.find("#TEST#") != std::string::npos)
        {
            const std::string before{testCases::getTestCaseLabel(line)};
            const std::string after = findMapping(before);
            result.replace(line.find(before), before.length(), after);
            if (const std::string alias{testCases::getTestCaseAlias(line)}; !alias.empty())
            {
                const std::string afterAlias = findMapping(alias);
                result.replace(line.find(alias), alias.length(), afterAlias);
            }
        }
        return result;
    };
    contents.transform(renumberLabel, dest);
}

void Processor::writeSourceFiles()
{
    std::cout << "Updating " << m_sourceFiles.size() << " test case source files..." << std::flush;
    for (const testCases::FileContents &sourceFile : m_sourceFiles)
    {
        writeTransformedFileContentsInPlace(sourceFile);
    }
    std::cout << '\n';
}

const testCases::FileContents &Processor::getCaseDiffForLabel(const std::string &label)
{
    auto it = std::find_if(m_caseDiffs.begin(),
                           m_caseDiffs.end(),
                           [&](const testCases::FileContents &caseDiff) { return caseDiff.getPath().stem() == label; });
    if (it == m_caseDiffs.end())
    {
        throw std::runtime_error("Unknown label " + label);
    }
    return *it;
}

void Processor::writeDiffs()
{
    if (!m_test.hasDiffs())
    {
        return;
    }

    // update contents of all existing diffs to new labels; skip diffs that don't exist
    // write updated contents of before case diff to after case diff
    std::cout << "Updating " << m_test.getNumTestCases() << " diffs..." << std::flush;
    for (const std::string &before : m_test.getCases())
    {
        if (std::find(m_missingDiffs.begin(), m_missingDiffs.end(), before) != m_missingDiffs.end())
        {
            if (const std::filesystem::path path = m_resultsDir / "diffs" / (findMapping(before) + ".txt");
                exists(path))
            {
                remove(path);
            }
            continue;
        }

        const testCases::FileContents &caseDiff = getCaseDiffForLabel(before);
        const std::string after = findMapping(before);
        const std::filesystem::path afterPath = caseDiff.getPath().parent_path() / (after + ".txt");
        writeTransformedFileContents(caseDiff, afterPath);
    }
    std::cout << '\n';

    if (m_fileDiff.getPath().empty())
    {
        return;
    }

    writeTransformedFileContentsInPlace(m_fileDiff);
}

void Processor::writeToolResults()
{
    std::cout << "Updating " << m_toolResults.size() << " tool results..." << std::flush;
    std::vector<std::string_view> before;
    std::vector<std::string_view> after;
    before.reserve(m_test.getNumTestCases());
    after.reserve(m_test.getNumTestCases());
    for (const CaseMapping &map : m_mapping)
    {
        before.push_back(map.before);
        after.push_back(map.after);
    }
    for (testCases::ToolResults &result : m_toolResults)
    {
        result.renameTestCases(m_test.getPrefix(), before, after);
        result.writeResults();
        std::cout << '.' << std::flush;
    }
    std::cout << '\n';
}

void Processor::writeResults()
{
    writeSourceFiles();
    writeDiffs();
    writeToolResults();
}

bool readTestCases(std::filesystem::path testCaseDirectory)
{
    std::vector<std::string> errors = testCases::Test::scanTestDirectory(testCaseDirectory);
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

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results> <TestPrefix>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 4)
    {
        return usage(args[0]);
    }
    const std::filesystem::path testCaseDir(args[1]);
    if (!readTestCases(testCaseDir))
    {
        return 1;
    }
    const std::filesystem::path resultsDir{args[2]};
    const std::string_view prefix{args[3]};
    Processor processor(resultsDir, prefix);
    processor.renumber();
    processor.writeResults();
    return 0;
}
