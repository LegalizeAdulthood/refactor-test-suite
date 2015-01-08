#include "stdafx.h"

// Inverts the logic in a conditional statement and swaps the if and else blocks.

namespace ReverseConditionalNamespace
{
    int GetSomething()
    {
        static int i = 0;
        return ++i;
    }

    void Test1()
    {
        int i = GetSomething();
        int j;

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

    }
}

void TestReverseConditional()
{
}
