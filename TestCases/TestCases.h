#pragma once

#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace testCases
{

struct Test
{
    const char *name;
    const char *prefix;
    bool diffsRequired{true};
};

extern std::vector<Test> g_tests;
extern std::map<const char *, std::vector<std::string>> g_testCases;

std::vector<std::string> scanTestDirectory(std::string_view dir);
bool isDeprecatedLabel(const std::string &label);
const char *getPrefixForTestName(std::string_view name);

}    // namespace testCases
