#include "stdafx.h"
#include "RenameCpp11.h"
#include "Require.h"

#include <string>
#include <sstream>

namespace
{

// #TEST#: R104 Rename flag used in static_assert
constexpr bool flag = true;
// #TEST#: R105 Rename flag used in static_assert
constexpr bool flag2 = false;
// #TEST#: R106 Rename flag used in noexcept specification
constexpr bool flag3 = true;
// #TEST#: R107 Rename flag used in noexcept specification
constexpr bool flag4 = false;

// #TEST#: R100 Rename flag in static_assert
static_assert(flag, "Flag is false");
// #TEST#: R101 Rename flag2 in static_assert
static_assert(!flag2, "Flag2 is true");

// #TEST#: R102 Rename flag3 in noexcept specifier
void f1() noexcept(flag3)
{
}

// #TEST#: R103 Rename flag4 in noexcept specifier
void f2() noexcept(!flag4)
{
}

// #TEST#: R108 Rename T used in noexcept expression
template <typename T>
// #TEST#: R109 Rename T in noexcept expression
void f3() noexcept(noexcept(T()))
{
    // #TEST#: R110 Rename T used in noexcept expression
    T x = T();
}

void f4()
{
    // #TEST#: R111 Rename c16
    char16_t c16 = u'x';
    // #TEST#: R112 Rename c32
    char32_t c32 = U'x';

    std::ostringstream s;
    // #TEST#: R113 Rename c16
    s << static_cast<int>(c16);
    // #TEST#: R114 Rename c32
    s << static_cast<int>(c32);
}

void f5()
{
    // #TEST#: R115 Rename X used in alignof operator expression
    struct alignas(4) X
    {
        int x;
        char b;
    };
    // #TEST#: R116 Rename X
    require_equal(4U, alignof(X));
}

void f6()
{
    // #TEST#: R117 Rename X used in alignas specifier
    struct alignas(int) X
    {
        float y;
        char b;
    };
    // #TEST#: R118 Rename X in alignas specifier
    struct alignas(X) Y
    {
        float y;
        char b;
    };
    // #TEST#: R119 Rename X used in alignas specifier
    require_equal(alignof(int), alignof(X));
    // #TEST#: R120 Rename X used in alignas specifier
    require_equal(alignof(X), alignof(Y));
}

void f7()
{
    // #TEST#: R121 Rename X
    struct X
    {
        // #TEST#: R122 Rename X via default c'tor
        X() = default;
        // #TEST#: R123 Rename X via default copy c'tor
        // #TEST#: R124 Rename X via default copy c'tor argument
        X(const X &rhs) = default;
        // #TEST#: R125 Rename X via default move c'tor
        // #TEST#: R126 Rename X via default move c'tor argument
        X(X &&rhs) = default;
        // #TEST#: R127 Rename X via default d'tor
        ~X() = default;
        // #TEST#: R128 Rename X via default copy assignment return type
        // #TEST#: R129 Rename X via default copy assignment argument
        X &operator=(const X &rhs) = default;
        // #TEST#: R130 Rename X via default move assignment return type
        // #TEST#: R131 Rename X via default move assignment argument
        X &operator=(X &&rhs) = default;

        int x = 1;
        int y = 2;
        std::string s = "foo";
    };
    const auto check = [](const X &x)
    {
        require_equal(1, x.x);
        require_equal(2, x.y);
        require_equal(std::string("foo"), x.s);
    };
    const X x1;
    check(x1);
    const X x2(x1);
    check(x2);
    X x3;
    x3.x = -1;
    x3.y = -2;
    x3 = x1;
    check(x3);
    const X x4{X()};
    check(x4);
    X x5;
    x5 = X();
    check(x5);
}

}

void TestRenameCpp11()
{
    f1();
    f2();
    f3<int>();
    f4();
    f5();
    f6();
    f7();
}
