#include "Require.h"

#include <iostream>
#include <string>
#include <vector>

namespace InlineTypeAlias
{

using Int = int;
using StringVec = std::vector<std::string>;

}    // namespace InlineTypeAlias

std::ostream &operator<<(std::ostream &str, InlineTypeAlias::StringVec::const_iterator &it)
{
    if (it == InlineTypeAlias::StringVec::const_iterator())
    {
        return str << "(end)";
    }
    return str << "(iterator)";
}

namespace
{

void f1()
{
    using Int = int;
    // #TEST#: ITA1 Inline type alias Int
    Int x{10};
    REQUIRE_EQUAL(10, x);

    // #TEST#: ITA2 Inline type alias InlineTypeAlias::StringVec
    InlineTypeAlias::StringVec v;
    // #TEST#: ITA3 Inline type alias InlineTypeAlias::StringVec (not available)
    using InlineTypeAlias::StringVec;
    // #TEST#: ITA4 Inline type alias StringVec
    const StringVec::const_iterator begin = v.cbegin();
    // #TEST#: ITA5 Inline type alias StringVec
    using ConstIterator = StringVec::const_iterator;
    // #TEST#: ITA6 Inline type alias ConstIterator
    const ConstIterator end = v.cend();
    REQUIRE_EQUAL(end, begin);
}

}    // namespace

void TestInlineTypeAlias()
{
    f1();
}
