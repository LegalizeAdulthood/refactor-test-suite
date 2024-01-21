#include <FileContents.h>
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
    Processor(std::string_view prefix);

    void scanResultsDir(std::filesystem::path resultsDir);
    void readDiffs(std::filesystem::path resultsDir);
    void renumber();
    void writeResults();

private:
    void readCaseDiffs(std::filesystem::path caseDiffsDir);
    void readFileDiff(std::filesystem::path fileDiffDir);
    std::string findMapping(std::string_view label) const;
    void writeTransformedFileContents(const testCases::FileContents &contents, std::filesystem::path destPath);
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
};

Processor::Processor(std::string_view prefix) :
    m_test(testCases::getTestForPrefix(prefix))
{
    m_sourceFiles.reserve(m_test.getPaths().size());
    for (const std::filesystem::path &path : m_test.getPaths())
    {
        m_sourceFiles.emplace_back(path);
    }
}

void Processor::scanResultsDir(std::filesystem::path resultsDir)
{
    for (const auto &entry : std::filesystem::directory_iterator(resultsDir))
    {
        if (entry.is_directory())
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

void Processor::readDiffs(std::filesystem::path resultsDir)
{
    if (!m_test.getDiffsRequired())
    {
        return;
    }

    readCaseDiffs(resultsDir / "diffs");
    readFileDiff(resultsDir / "file-diffs");
}

void Processor::readCaseDiffs(std::filesystem::path caseDiffsDir)
{
    m_caseDiffs = testCases::readCaseDiffs(caseDiffsDir, m_test.getPrefix());
}

void Processor::readFileDiff(std::filesystem::path fileDiffDir)
{
    const std::filesystem::path fileDiff(fileDiffDir / (m_test.getPrefix() + ".txt"));
    if (exists(fileDiff))
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

void Processor::writeTransformedFileContents(const testCases::FileContents &contents,
                                             const std::filesystem::path destPath)
{
    auto renumberLabel = [this](const std::string &line)
    {
        std::string result{line};
        if (line.find("#TEST#") != std::string::npos)
        {
            const std::string label{testCases::getTestCaseLabel(line)};
            const std::string replacement = findMapping(label);
            result.replace(line.find(label), label.length(), replacement);
        }
        return result;
    };
    contents.transform(renumberLabel);
}

void Processor::writeSourceFiles()
{
    std::cout << "Updating " << m_sourceFiles.size() << " test case source files..." << std::flush;
    for (const testCases::FileContents &sourceFile : m_sourceFiles)
    {
        writeTransformedFileContents(sourceFile, sourceFile.getPath());
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
    if (!m_test.getDiffsRequired())
    {
        return;
    }

    // update contents of all diffs to new labels
    // write updated contents of before case diff to after case diff
    std::cout << "Updating " << m_test.getNumTestCases() << " diffs..." << std::flush;
    for (const std::string &label : m_test.getCases())
    {
        const testCases::FileContents &caseDiff = getCaseDiffForLabel(label);
        const std::string before = caseDiff.getPath().stem().string();
        const std::string after = findMapping(before);
        const std::filesystem::path afterPath = caseDiff.getPath().parent_path() / (after + ".txt");
        writeTransformedFileContents(caseDiff, afterPath);
    }
    std::cout << '\n';

    if (m_fileDiff.getPath().empty())
    {
        return;
    }

    writeTransformedFileContents(m_fileDiff, m_fileDiff.getPath());
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
    std::cout << "Usage: " << program << " <RefactorTest> <TestPrefix> <results>\n";
    return 1;
}

int main(std::vector<std::string_view> args)
{
    try
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
        const std::string_view prefix{args[2]};
        Processor processor(prefix);
        const std::filesystem::path resultsDir{args[3]};
        processor.scanResultsDir(resultsDir);
        processor.readDiffs(resultsDir);
        processor.renumber();
        processor.writeResults();
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
