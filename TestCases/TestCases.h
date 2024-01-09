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

const std::vector<Test> &getTests();
const std::map<const char *, std::vector<std::string>> &getTestCases();
const std::vector<std::string> &getTestCaseLabels(const char *prefix);
inline std::size_t getNumTestCases(const char *prefix)
{
    return getTestCaseLabels(prefix).size();
}
std::vector<std::string> scanTestDirectory(std::string_view dir);
bool isDeprecatedLabel(const std::string &label);
const std::vector<std::string> &getDeprecatedLabels(const char *prefix);
const char *getPrefixForTestName(std::string_view name);

}    // namespace testCases
