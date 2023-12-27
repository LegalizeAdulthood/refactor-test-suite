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

namespace testDiffs
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

bool checkDiffs(std::ostream &out)
{
    bool result{};
    for (const testCases::Test &test : testCases::g_tests)
    {
        if (!test.diffsRequired)
        {
            continue;
        }

        for (const std::string &testCase : testCases::g_testCases[test.prefix])
        {
            if (std::find(g_diffs.begin(), g_diffs.end(), testCase + ".txt") == g_diffs.end())
            {
                out << "error: Test case " << testCase << " has no diff.\n";
                result = true;
            }
        }
    }
    return result;
}

int main(const std::vector<std::string_view> &args)
{
    try
    {
        if (args.size() < 3)
        {
            throw std::runtime_error("Missing directory arguments");
        }

        testCases::scanTestDirectory(args[1]);
        scanDiffDirectory(args[2]);
        return checkDiffs(std::cout) ? 1 : 0;
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

}    // namespace testDiffs

int main(int argc, char *argv[])
{
    std::vector<std::string_view> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return testDiffs::main(args);
}
