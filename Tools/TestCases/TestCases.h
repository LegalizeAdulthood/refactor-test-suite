#pragma once

#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace testCases
{

struct Test
{
    std::string name;
    std::string prefix;
    bool diffsRequired{true};
};

const std::vector<Test> &getTests();
const std::map<std::string, std::vector<std::string>> &getTestCases();
const std::vector<std::string> &getTestCaseLabels(const std::string &prefix);
inline std::size_t getNumTestCases(const std::string &prefix)
{
    return getTestCaseLabels(prefix).size();
}
std::vector<std::string> scanTestDirectory(std::string_view dir);
bool isDeprecatedLabel(const std::string &label);
const std::vector<std::string> &getDeprecatedLabels(const std::string &prefix);
std::string getPrefixForTestName(std::string_view name);

}    // namespace testCases
