#include <TestCases.h>

#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace
{

std::vector<std::string> g_errors;
std::vector<std::string> g_warnings;
bool g_renderTableBorder{};

void checkMissingTestCases()
{
    const auto extractCaseNum = [](const std::string &label)
    { return std::stoi(label.substr(label.find_first_of("0123456789"))); };
    for (const testCases::Test &test : testCases::getTests())
    {
        int num{1};
        for (const std::string &testCase : testCases::getTestCaseLabels(test.prefix))
        {
            int caseNum = extractCaseNum(testCase);
            do
            {
                if (num != caseNum)
                {
                    g_warnings.emplace_back(std::string{"Missing test case "} + test.prefix + std::to_string(num));
                }
            } while (num++ != caseNum);
        }
    }
}

void printMarkDown(std::ostream &out)
{
    if (!g_warnings.empty())
    {
        for (const std::string &warning : g_warnings)
        {
            std::cerr << "warning: " << warning << '\n';
        }
    }
    if (!g_errors.empty())
    {
        for (const std::string &error : g_errors)
        {
            std::cerr << "error: " << error << '\n';
        }
        throw std::runtime_error("Test case errors detected");
    }

    out << "# Tool\n\n";
    const char *const borderStart = g_renderTableBorder ? "| " : "";
    const char *const borderEnd = g_renderTableBorder ? " |\n" : "\n";
    for (const testCases::Test &test : testCases::getTests())
    {
        out << "\n## " << test.name << '\n'                    //
            << borderStart << "Case | Result" << borderEnd     //
            << borderStart << "---- | ------" << borderEnd;    //
        for (const std::string &testCase : testCases::getTestCaseLabels(test.prefix))
        {
            out << borderStart << testCase << " | " << (testCases::isDeprecatedLabel(testCase) ? "(deprecated)" : "")
                << borderEnd;
        }
    }
}

int main(std::vector<std::string_view> args)
{
    try
    {
        if (args.size() == 3 && args[1] == "--border")
        {
            g_renderTableBorder = true;
            args.erase(args.begin() + 1);
        }
        if (args.size() < 2)
        {
            throw std::runtime_error("Missing directory argument");
        }

        g_errors = testCases::scanTestDirectory(args[1]);
        checkMissingTestCases();
        printMarkDown(std::cout);
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
