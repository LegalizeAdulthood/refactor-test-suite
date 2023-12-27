#include "Require.h"

#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

static void TestReplaceAutoWithTypeDeque()
{
    std::deque<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RAWT1 Replace auto with type
    for (auto it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT2 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT3 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    REQUIRE_EQUAL(3 + 2, sum);

    sum = 0;
    // #TEST#: RAWT4 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeList()
{
    std::list<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RAWT5 Replace auto with type
    for (auto it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT6 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT7 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    REQUIRE_EQUAL(3 + 2, sum);

    sum = 0;
    // #TEST#: RAWT8 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeMap()
{
    std::map<int, int> c;
    c[1] = 1;
    c[2] = 2;
    int sum = 0;
    // #TEST#: RAWT9 Replace auto with type
    for (auto it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT10 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT11 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    REQUIRE_EQUAL(3 + 2, sum);

    sum = 0;
    // #TEST#: RAWT12 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --it->second;
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeMultimap()
{
    std::multimap<int, int> c;
    c.insert(std::make_pair(1, 1));
    c.insert(std::make_pair(2, 2));
    int sum = 0;
    // #TEST#: RAWT13 Replace auto with type
    for (auto it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT14 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT15 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    REQUIRE_EQUAL(3 + 2, sum);

    sum = 0;
    // #TEST#: RAWT16 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --it->second;
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeSet()
{
    std::set<int> c;
    c.insert(1);
    c.insert(2);
    int sum = 0;
    // #TEST#: RAWT17 Replace auto with type
    for (auto it = c.cbegin(), end = c.cend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT18 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT19 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT20 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeUnorderedMap()
{
    std::unordered_map<int, int> c;
    c[1] = 1;
    c[2] = 2;
    int sum = 0;
    // #TEST#: RAWT21 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        sum += it->second;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT22 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    REQUIRE_EQUAL(3 + 2, sum);
}

static void TestReplaceAutoWithTypeUnorderedSet()
{
    std::unordered_set<int> c;
    c.insert(1);
    c.insert(2);
    int sum = 0;
    // #TEST#: RAWT23 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT24 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

static void TestReplaceAutoWithTypeVector()
{
    std::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RAWT25 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT26 Replace auto with type
    for (auto it = c.crbegin(), end = c.crend(); it != end; ++it)
    {
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);

    sum = 0;
    // #TEST#: RAWT27 Replace auto with type
    for (auto it = c.begin(), end = c.end(); it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    REQUIRE_EQUAL(3 + 2, sum);

    sum = 0;
    // #TEST#: RAWT28 Replace auto with type
    for (auto it = c.rbegin(), end = c.rend(); it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    REQUIRE_EQUAL(2 + 1, sum);
}

namespace
{

#define REQUIRE_TYPE_EQUAL(expected_, actual_) REQUIRE_EQUAL(true, (std::is_same<expected_, decltype(actual_)>::value))

void f1()
{
    // #TEST#: RAWT29 Replace auto with type
    auto i{3};
    REQUIRE_EQUAL(3, i);
    REQUIRE_TYPE_EQUAL(int, i);
    using namespace std::string_literals;
    // #TEST#: RAWT30 Replace auto with type
    auto s{"Text"s};
    REQUIRE_EQUAL(std::string{"Text"}, s);
    REQUIRE_TYPE_EQUAL(std::string, s);
}

}    // namespace

void TestReplaceAutoWithType()
{
    TestReplaceAutoWithTypeDeque();
    TestReplaceAutoWithTypeList();
    TestReplaceAutoWithTypeMap();
    TestReplaceAutoWithTypeMultimap();
    TestReplaceAutoWithTypeSet();
    TestReplaceAutoWithTypeUnorderedMap();
    TestReplaceAutoWithTypeUnorderedSet();
    TestReplaceAutoWithTypeVector();
    f1();
}
