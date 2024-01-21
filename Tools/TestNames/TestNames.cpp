#include <Main.h>
#include <TestCases.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace
{

class TestNames
{
public:
    TestNames(std::string_view testCaseDir, bool renderBorder, std::string &outputFile) :
        m_renderBorder(renderBorder),
        m_outputFile(outputFile),
        m_errors(testCases::Test::scanTestDirectory(testCaseDir)),
        m_allTests(testCases::getTests())
    {
        checkMissingTestCases();
    }

    void checkErrors();
    void writeOutputFile();

private:
    void checkMissingTestCases();
    void printMarkDown(std::ostream &out);

    bool m_renderBorder;
    std::string m_outputFile;
    std::vector<std::string> m_warnings;
    std::vector<std::string> m_errors;
    const std::vector<testCases::Test> &m_allTests ;
};

void TestNames::checkMissingTestCases()
{
    const auto extractCaseNum = [](const std::string &label)
    { return std::stoi(label.substr(label.find_first_of("0123456789"))); };
    for (const testCases::Test &test : m_allTests)
    {
        int num{1};
        for (const std::string &testCase : test.getCases())
        {
            int caseNum = extractCaseNum(testCase);
            do
            {
                if (num != caseNum)
                {
                    m_warnings.emplace_back(std::string{"Missing test case "} + test.getPrefix() + std::to_string(num));
                }
            } while (num++ != caseNum);
        }
    }
}

void TestNames::checkErrors()
{
    if (!m_warnings.empty())
    {
        for (const std::string &warning : m_warnings)
        {
            std::cerr << "warning: " << warning << '\n';
        }
    }
    if (!m_errors.empty())
    {
        for (const std::string &error : m_errors)
        {
            std::cerr << "error: " << error << '\n';
        }
        throw std::runtime_error("Test case errors detected");
    }
    {
        bool nonConsecutiveCases{false};
        for (const testCases::Test &test : m_allTests)
        {
            if (!test.isConsecutive())
            {
                std::cerr << "error: Non-consecutive test cases for " << std::setw(4) << std::left << test.getPrefix()
                          << " " << test.getName() << '\n';
                nonConsecutiveCases = true;
            }
        }
        if (nonConsecutiveCases)
        {
            throw std::runtime_error("Test case errors detected");
        }
    }
}

void TestNames::printMarkDown(std::ostream &out)
{
    out << "# Tool\n\n";
    const char *const borderStart = m_renderBorder ? "| " : "";
    const char *const borderEnd = m_renderBorder ? " |\n" : "\n";
    for (const testCases::Test &test : m_allTests)
    {
        out << "\n## " << test.getName() << '\n'               //
            << borderStart << "Case | Result" << borderEnd     //
            << borderStart << "---- | ------" << borderEnd;    //
        for (const std::string &testCase : test.getCases())
        {
            out << borderStart << testCase << " | " << (test.isDeprecatedCase(testCase) ? "(deprecated)" : "")
                << borderEnd;
        }
    }
}

void TestNames::writeOutputFile()
{
    if (m_outputFile.empty())
    {
        return;
    }

    if (m_outputFile == "-")
    {
        printMarkDown(std::cout);
    }
    else
    {
        std::ofstream str(m_outputFile);
        if (!str)
        {
            throw std::runtime_error("Couldn't open output file " + m_outputFile);
        }
        printMarkDown(str);
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << "[--border] [-o <Tool.md>] <RefactorTest>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    bool renderBorder{};
    std::string outputFile;

    if (args.size() < 2)
    {
        return usage(args[0]);
    }
    if (args[1] == "--border")
    {
        if (args.size() < 3)
        {
            return usage(args[0]);
        }
        renderBorder = true;
        args.erase(args.begin() + 1);
    }
    if (args[1] == "-o")
    {
        if (args.size() < 3)
        {
            return usage(args[0]);
        }
        outputFile = args[2];
        args.erase(args.begin() + 1, args.begin() + 3);
    }
    if (args.size() != 2)
    {
        return usage(args[0]);
    }

    TestNames names(args[1], renderBorder, outputFile);
    names.checkErrors();
    names.writeOutputFile();
    return 0;
}
