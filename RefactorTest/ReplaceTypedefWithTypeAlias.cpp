#include "Require.h"

#include <iostream>
#include <string>
#include <vector>

namespace ReplaceTypedefWithTypeAlias
{

struct Foo
{
    void f()
    {
        m_x = 2;
    }
    int g(int x)
    {
        return x;
    }

    int m_x{1};
};

// #TEST#: RTDTA1 Replace typedef with type alias
typedef int IntT;
// #TEST#: RTDTA2 Replace typedef with type alias
typedef std::string StringT;
// #TEST#: RTDTA3 Replace typedef with type alias
typedef std::vector<StringT> StringVecT;
// #TEST#: RTDTA4 Replace typedef with type alias
typedef void (Foo::*FooFn)();
// #TEST#: RTDTA5 Replace typedef with type alias
typedef int (Foo::*FooGn)(int x);

}    // namespace ReplaceTypedefWithTypeAlias

static std::ostream &operator<<(std::ostream &str, ReplaceTypedefWithTypeAlias::StringVecT::const_iterator &it)
{
    if (it == ReplaceTypedefWithTypeAlias::StringVecT::const_iterator())
    {
        return str << "(end)";
    }
    return str << "(iterator)";
}

namespace
{

void f1()
{
    // #TEST#: RTDTA6 Replace typedef with type alias
    typedef int IntT;
    IntT x{10};
    REQUIRE_EQUAL(10, x);

    ReplaceTypedefWithTypeAlias::StringVecT v;
    using ReplaceTypedefWithTypeAlias::StringVecT;
    const StringVecT::const_iterator begin = v.cbegin();
    // #TEST#: RTDTA7 Replace typedef with type alias
    typedef StringVecT::const_iterator ConstIteratorT;
    const ConstIteratorT end = v.cend();
    REQUIRE_EQUAL(end, begin);

    ReplaceTypedefWithTypeAlias::Foo f;
    ReplaceTypedefWithTypeAlias::FooFn fn = &ReplaceTypedefWithTypeAlias::Foo::f;
    (f.*fn)();
    REQUIRE_EQUAL(2, f.m_x);
    ReplaceTypedefWithTypeAlias::FooGn gn = &ReplaceTypedefWithTypeAlias::Foo::g;
    const int x2 = (f.*gn)(1);
    REQUIRE_EQUAL(1, x2);
}

}    // namespace

void TestReplaceTypedefWithTypeAlias()
{
    f1();
}
