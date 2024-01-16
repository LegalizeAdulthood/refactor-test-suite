#include <TestCases.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace
{

std::vector<std::string> g_diffs;

void scanDiffDirectory(std::filesystem::path dir)
{
    for (auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (is_directory(entry))
        {
            scanDiffDirectory(entry);
        }
        else
        {
            g_diffs.emplace_back(entry.path().filename().string());
        }
    }
}

void checkDiffs(std::ostream &out)
{
    for (const testCases::Test &test : testCases::getTests())
    {
        if (!test.diffsRequired)
        {
            continue;
        }

        for (const std::string &testCase : testCases::getTestCaseLabels(test.prefix))
        {
            if (std::find(g_diffs.begin(), g_diffs.end(), testCase + ".txt") == g_diffs.end())
            {
                out << "warning: Test case " << testCase << " has no diff.\n";
            }
        }
    }
}

int usage(std::string_view program)
{
    std::cout << "Usage: " << program << " <RefactorTest> <results/diffs>\n";
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

        testCases::scanTestDirectory(args[1]);
        scanDiffDirectory(args[2]);
        checkDiffs(std::cout);
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
