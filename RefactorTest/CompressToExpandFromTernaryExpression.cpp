#include "stdafx.h"

// Converts an if/else conditional with assignments in each branch into
// a ternary expression.
// Converts a ternary expression into an if/else block.

namespace CompressToTernaryExpressionNamespace
{
    void TestInteger()
    {
        int y = 10;
        int x;
        // #TEST#: CTE1 Compress to Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else
        {
            x = 1;
        }

        // #TEST#: CTE2 Compress to Ternary Expression
        if (y == 10)
        {
            x = y;
        }
        else if (y != 10)
        {
            x = 1;
        }

        // #TEST#: CTE3 Compress to Ternary Expression
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

        // #TEST#: CTE4 Compress to Ternary Expression
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

        // #TEST#: CTE5 Expand Ternary Expression
        x = (y == 10) ? y : 1;
    }

    void TestFloatDouble()
    {
        float f = 1.0f;
        double x = 1.0;

        // #TEST#: CTE6 Compress to Ternary Expression
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
        // #TEST#: CTE7 Compress to Ternary Expression
        if (g == 10.0f)
        {
            r = g;
        }
        else
        {
            r = f;
        }

        float *p;
        // #TEST#: CTE8 Compress to Ternary Expression
        if (g == 10.0f)
        {
            p = &f;
        }
        else
        {
            p = &g;
        }

        // #TEST#: CTE13 Expand Ternary Expression
        p = (g == 10.0f) ? &f : &g;
    }

    int Operation1() { return 1; }
    int Operation2() { return 2; }
    void Operation3() {}
    void Operation4() {}

    void TestFunctionPointer()
    {
        int (*fn1)() = Operation1;
        int (*fn2)();
        // #TEST#: CTE9 Compress to Ternary Expression
        if (fn1 == Operation1)
        {
            fn2 = Operation2;
        }
        else
        {
            fn2 = Operation1;
        }

        // #TEST#: CTE12 Expand Ternary Expression
        fn2 = (fn1 == Operation1) ? Operation2 : Operation1;
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
        // #TEST#: CTE10 Compress to Ternary Expression
        if (mem1 == &Foo::Operation1)
        {
            mem2 = &Foo::Operation2;
        }
        else
        {
            mem2 = &Foo::Operation1;
        }

        // #TEST#: CTE11 Expand Ternary Expression
        mem2 = (mem1 == &Foo::Operation1) ? &Foo::Operation2 : &Foo::Operation1;
    }
}

using namespace CompressToTernaryExpressionNamespace;

void TestCompressToExpandFromTernaryExpression()
{
    TestInteger();
    TestFloatDouble();
    TestFunctionPointer();
}
