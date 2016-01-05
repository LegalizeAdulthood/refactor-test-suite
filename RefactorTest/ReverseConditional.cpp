#include "stdafx.h"
#include "Require.h"

// Inverts the logic in a conditional statement and swaps the if and else blocks.

namespace ReverseConditionalNamespace
{
    int GetSomething()
    {
        static int i = 0;
        return ++i;
    }

    int Test1()
    {
        int i = GetSomething();
        int j = 0;

        // #TEST#: RC1 Reverse Conditional
        if (i != 6)
        {
            if (i != 4)
            {
                if (i != 2)
                {
                    if (i != 1)
                    {
                        j = 7;
                    }
                    else
                    {
                        j = 2;
                    }
                }
                else
                {
                    j = 3;
                }
            }
            else
            {
                j = 5;
            }
        }
        return j;
    }
}

void TestReverseConditional()
{
    REQUIRE_EQUAL(2, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(3, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(7, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(5, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(7, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(0, ReverseConditionalNamespace::Test1());
    REQUIRE_EQUAL(7, ReverseConditionalNamespace::Test1());
}
