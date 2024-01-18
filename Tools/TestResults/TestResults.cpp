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

int main(const std::vector<std::string_view> &args)
{
    try
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
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 2;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 3;
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
