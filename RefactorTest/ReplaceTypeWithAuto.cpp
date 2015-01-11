#include "stdafx.h"

#include <cassert>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

static void TestReplaceTypeWithAutoDeque()
{
    std::deque<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RTWA1 Replace type with auto
    for (std::deque<int>::const_iterator it = c.cbegin(), end = c.cend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA2 Replace type with auto
    for (std::deque<int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA3 Replace type with auto
    for (std::deque<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    assert(3 + 2 == sum);

    sum = 0;
    // #TEST#: RTWA4 Replace type with auto
    for (std::deque<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoList()
{
    std::list<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RTWA5 Replace type with auto
    for (std::list<int>::const_iterator it = c.cbegin(), end = c.cend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA6 Replace type with auto
    for (std::list<int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA7 Replace type with auto
    for (std::list<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    assert(3 + 2 == sum);

    sum = 0;
    // #TEST#: RTWA8 Replace type with auto
    for (std::list<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoMap()
{
    std::map<int, int> c;
    c[1] = 1;
    c[2] = 2;
    int sum = 0;
    // #TEST#: RTWA9 Replace type with auto
    for (std::map<int, int>::const_iterator it = c.cbegin(), end = c.cend();
        it != end; ++it)
    {
        sum += it->second;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA10 Replace type with auto
    for (std::map<int, int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += it->second;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA11 Replace type with auto
    for (std::map<int, int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    assert(3 + 2 == sum);

    sum = 0;
    // #TEST#: RTWA12 Replace type with auto
    for (std::map<int, int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --it->second;
        sum += it->second;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoMultimap()
{
    std::multimap<int, int> c;
    c.insert(std::make_pair(1, 1));
    c.insert(std::make_pair(2, 2));
    int sum = 0;
    // #TEST#: RTWA13 Replace type with auto
    for (std::multimap<int, int>::const_iterator it = c.cbegin(), end = c.cend();
        it != end; ++it)
    {
        sum += it->second;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA14 Replace type with auto
    for (std::multimap<int, int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += it->second;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA15 Replace type with auto
    for (std::multimap<int, int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    assert(3 + 2 == sum);

    sum = 0;
    // #TEST#: RTWA16 Replace type with auto
    for (std::multimap<int, int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --it->second;
        sum += it->second;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoSet()
{
    std::set<int> c;
    c.insert(1);
    c.insert(2);
    int sum = 0;
    // #TEST#: RTWA17 Replace type with auto
    for (std::set<int>::const_iterator it = c.cbegin(), end = c.cend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA18 Replace type with auto
    for (std::set<int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA19 Replace type with auto
    for (std::set<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA20 Replace type with auto
    for (std::set<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoUnorderedMap()
{
    std::unordered_map<int, int> c;
    c[1] = 1;
    c[2] = 2;
    int sum = 0;
    // #TEST#: RTWA21 Replace type with auto
    for (std::unordered_map<int, int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += it->second;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA23 Replace type with auto
    for (std::unordered_map<int, int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++it->second;
        sum += it->second;
    }
    assert(3 + 2 == sum);
}

static void TestReplaceTypeWithAutoUnorderedSet()
{
    std::unordered_set<int> c;
    c.insert(1);
    c.insert(2);
    int sum = 0;
    // #TEST#: RTWA25 Replace type with auto
    for (std::unordered_set<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA27 Replace type with auto
    for (std::unordered_set<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);
}

static void TestReplaceTypeWithAutoVector()
{
    std::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    int sum = 0;
    // #TEST#: RTWA29 Replace type with auto
    for (std::vector<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA30 Replace type with auto
    for (std::vector<int>::const_reverse_iterator it = c.crbegin(), end = c.crend();
        it != end; ++it)
    {
        sum += *it;
    }
    assert(2 + 1 == sum);

    sum = 0;
    // #TEST#: RTWA31 Replace type with auto
    for (std::vector<int>::iterator it = c.begin(), end = c.end();
        it != end; ++it)
    {
        ++*it;
        sum += *it;
    }
    assert(3 + 2 == sum);

    sum = 0;
    // #TEST#: RTWA32 Replace type with auto
    for (std::vector<int>::reverse_iterator it = c.rbegin(), end = c.rend();
        it != end; ++it)
    {
        --*it;
        sum += *it;
    }
    assert(2 + 1 == sum);
}

void TestReplaceTypeWithAuto()
{
    TestReplaceTypeWithAutoDeque();
    TestReplaceTypeWithAutoList();
    TestReplaceTypeWithAutoMap();
    TestReplaceTypeWithAutoMultimap();
    TestReplaceTypeWithAutoSet();
    TestReplaceTypeWithAutoUnorderedMap();
    TestReplaceTypeWithAutoUnorderedSet();
    TestReplaceTypeWithAutoVector();
}
