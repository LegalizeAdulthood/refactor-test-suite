#include "stdafx.h"
#include "RenameCpp11.h"

namespace
{

constexpr bool flag = true;
constexpr bool flag2 = false;
constexpr bool flag3 = true;
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

}

void TestRenameCpp11()
{
    f1();
    f2();
}
