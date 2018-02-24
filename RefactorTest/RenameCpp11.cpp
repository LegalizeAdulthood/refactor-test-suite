#include "stdafx.h"
#include "RenameCpp11.h"
#include "Require.h"

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

}

void TestRenameCpp11()
{
    f1();
    f2();
    f3<int>();
    f4();
    f5();
}
