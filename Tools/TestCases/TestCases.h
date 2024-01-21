#pragma once

#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

namespace testCases
{

std::string_view getTestCaseLabel(std::string_view line);
std::string_view getTestCaseAlias(std::string_view line);

struct TestCaseAlias
{
    std::string master;
    std::vector<std::string> aliases;
};

struct TestCaseLocation
{
    std::string label;
    std::filesystem::path sourceFile;
    int line;
};

class Test
{
public:
    static std::vector<std::string> scanTestDirectory(const std::filesystem::path &dir);
    static const std::string &getPrefixForTestName(const std::string &name);

    Test(const char *name, const char *prefix) :
        Test(name, prefix, true)
    {
    }
    Test(const char *name, const char *prefix, bool diffsRequired) :
        m_name(name),
        m_prefix(prefix),
        m_diffsRequired(diffsRequired)
    {
    }

    const std::string &getName() const
    {
        return m_name;
    }
    const std::string &getPrefix() const
    {
        return m_prefix;
    }
    bool hasDiffs() const
    {
        return m_diffsRequired;
    }
    const std::vector<std::string> &getCases() const
    {
        return m_cases;
    }
    const std::vector<TestCaseAlias> &getCaseAliases() const
    {
        return m_aliases;
    }
    const std::vector<std::string> &getDeprecatedCases() const
    {
        return m_deprecatedCases;
    }
    const std::vector<std::filesystem::path> &getPaths() const
    {
        return m_paths;
    }
    std::size_t getNumTestCases() const
    {
        return m_cases.size();
    }
    const std::vector<TestCaseLocation> &getCaseLocations() const
    {
        return m_locations;
    }
    bool isDeprecatedCase(const std::string &label) const;
    bool isConsecutive() const
    {
        return m_casesConsecutive;
    }

private:
    static void scanTestCaseDirectory(const std::filesystem::path &dir);
    static void scanTestCaseFile(const std::filesystem::path &path);
    static void scanTestCaseLine(std::string_view line);
    static void checkLabel(std::string_view label, std::string_view desc);
    static void sortTestCases();
    static void sortTestPaths();

    std::string m_name;
    std::string m_prefix;
    bool m_diffsRequired;
    bool m_casesConsecutive{true};
    std::vector<std::string> m_cases;
    std::vector<TestCaseAlias> m_aliases;
    std::vector<std::string> m_deprecatedCases;
    std::vector<std::filesystem::path> m_paths;
    std::vector<TestCaseLocation> m_locations;
};

const std::vector<Test> &getTests();
const Test &getTestForPrefix(std::string_view prefix);

extern const char *const g_diffPlaceholder;

}    // namespace testCases
