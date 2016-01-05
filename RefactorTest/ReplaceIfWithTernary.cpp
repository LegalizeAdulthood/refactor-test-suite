#include "stdafx.h"
#include "Require.h"

// Converts an if/else conditional with assignments in each branch into
// a ternary expression.

namespace ReplaceIfWithTernary
{
    int GetValue()
    {
        static int x = 9;
        return ++x;
    }

    void TestInteger()
    {
        int y = GetValue();
        int x;
        // #TEST#: RIT1 Replace If With Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else
        {
            x = 1;
        }
        REQUIRE_EQUAL(10, x);

        // #TEST#: RIT2 Replace If With Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else if (y != 10)
        {
            x = 1;
        }
        REQUIRE_EQUAL(10, x);

        // #TEST#: RIT3 Replace If With Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else if (y != 10)
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        REQUIRE_EQUAL(10, x);

        // #TEST#: RIT4 Replace If With Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else
        {
            if (y != 10)
            {
                x = 1;
            }
        }
        REQUIRE_EQUAL(10, x);
    }

    void TestFloatDouble()
    {
        float f = 1.0f;
        double x = 1.0;

        // #TEST#: RIT5 Replace If With Ternary Expression
        if (f == 10.0f)
        {
            x = -10.0;
        }
        else
        {
            x = 10.0f;
        }

        float g = 2.0f;
        float &r = f;
        // #TEST#: RIT6 Replace If With Ternary Expression
        if (g == 10.0f)
        {
            r = g;
        }
        else
        {
            r = f;
        }

        float *p;
        // #TEST#: RIT7 Replace If With Ternary Expression
        if (g == 10.0f)
        {
            p = &f;
        }
        else
        {
            p = &g;
        }
    }

    int Operation1() { return 1; }
    int Operation2() { return 2; }

    void TestFunctionPointer()
    {
        int (*fn1)() = Operation1;
        int (*fn2)();

        // #TEST#: RIT8 Replace If With Ternary Expression
        if (fn1 == Operation1)
        {
            fn2 = Operation2;
        }
        else
        {
            fn2 = Operation1;
        }
        REQUIRE_EQUAL(2, fn2());
    }

    class Foo
    {
    public:
        int Operation1() { return 1; }
        int Operation2() { return 2; }
    };

    void TestMemberPointer()
    {
        int (Foo::*mem1)() = &Foo::Operation1;
        int (Foo::*mem2)();

        // #TEST#: RIT9 Replace If With Ternary Expression
        if (mem1 == &Foo::Operation1)
        {
            mem2 = &Foo::Operation2;
        }
        else
        {
            mem2 = &Foo::Operation1;
        }
        Foo f;
        REQUIRE_EQUAL(2, (f.*mem2)());
    }
}

using namespace ReplaceIfWithTernary;

void TestReplaceIfWithTernary()
{
    TestInteger();
    TestFloatDouble();
    TestFunctionPointer();
    TestMemberPointer();
}
