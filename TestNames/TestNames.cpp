#include <TestCases.h>

#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace testNames
{

std::vector<std::string> g_errors;
std::vector<std::string> g_warnings;

void checkMissingTestCases()
{
    const auto extractCaseNum = [](const std::string &label)
    { return std::stoi(label.substr(label.find_first_of("0123456789"))); };
    for (const testCases::Test &test : testCases::g_tests)
    {
        int num{1};
        for (const std::string &testCase : testCases::g_testCases[test.prefix])
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

    for (const testCases::Test &test : testCases::g_tests)
    {
        out << "\n## " << test.name
            << "\nCase | Result\n"
               "---- | ------\n";
        for (const std::string &testCase : testCases::g_testCases[test.prefix])
        {
            if (testCases::isDeprecatedLabel(testCase))
            {
                continue;
            }
            out << testCase << " | \n";
        }
    }
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
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

}    // namespace testNames

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return testNames::main(args);
}
