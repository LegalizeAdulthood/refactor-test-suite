#include <Main.h>
#include <TestCases.h>
#include <ToolResults.h>

#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace
{

bool reportResults(const testCases::ToolResults &result, std::ostream &out)
{
    for (const std::string &warning : result.getWarnings())
    {
        out << warning << '\n';
    }
    const std::vector<std::string> &errors = result.getErrors();
    if (errors.empty())
    {
        return false;
    }

    for (const std::string &error : errors)
    {
        out << error << '\n';
    }
    return true;
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results/ToolResults.md>\n";
    return 1;
}

}    // namespace

int toolMain(std::vector<std::string_view> args)
{
    if (args.size() < 3)
    {
        return usage(args[0]);
    }

    testCases::Test::scanTestDirectory(args[1]);
    testCases::ToolResults results(args[2]);
    results.checkResults();
    return reportResults(results, std::cout) ? 1 : 0;
}
