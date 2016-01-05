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
            // #TEST#: RC2 Reverse Conditional
            if (i != 4)
            {
                // #TEST#: RC3 Reverse Conditional
                if (i != 2)
                {
                    // #TEST#: RC4 Reverse Conditional
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

    int Test2(int i)
    {
        // #TEST#: RC5 Reverse Conditional
        if (i < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int Test3(int i)
    {
        // #TEST#: RC6 Reverse Conditional
        if (i <= 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int Test4(int i)
    {
        // #TEST#: RC7 Reverse Conditional
        if (0 < i)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int Test5(int i)
    {
        // #TEST#: RC8 Reverse Conditional
        if (i == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void TestReverseConditional()
{
    using namespace ReverseConditionalNamespace;

    REQUIRE_EQUAL(2, Test1());
    REQUIRE_EQUAL(3, Test1());
    REQUIRE_EQUAL(7, Test1());
    REQUIRE_EQUAL(5, Test1());
    REQUIRE_EQUAL(7, Test1());
    REQUIRE_EQUAL(0, Test1());
    REQUIRE_EQUAL(7, Test1());

    REQUIRE_EQUAL(1, Test2(-1));
    REQUIRE_EQUAL(0, Test2(0));
    REQUIRE_EQUAL(0, Test2(1));

    REQUIRE_EQUAL(1, Test3(-1));
    REQUIRE_EQUAL(1, Test3(0));
    REQUIRE_EQUAL(0, Test3(1));

    REQUIRE_EQUAL(0, Test4(-1));
    REQUIRE_EQUAL(0, Test4(0));
    REQUIRE_EQUAL(1, Test4(1));

    REQUIRE_EQUAL(0, Test5(-1));
    REQUIRE_EQUAL(1, Test5(0));
    REQUIRE_EQUAL(0, Test5(1));
}
