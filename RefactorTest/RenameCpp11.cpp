#include "stdafx.h"
#include "RenameCpp11.h"

namespace
{

constexpr bool flag = true;
constexpr bool flag2 = false;

// #TEST#: R100 Rename flag in static_assert
static_assert(flag, "Flag is false");
// #TEST#: R101 Rename flag2 in static_assert
static_assert(!flag2, "Flag2 is true");

}

void TestRenameCpp11()
{
}
