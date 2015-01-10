#include "stdafx.h"
#include "Require.h"

// Converts a ternary assginment expression into an if/else block.assignment

namespace ReplaceTernaryWithIf
{
    int GetValue()
    {
        static int x = 9;
        return ++x;
    }

    void TestInteger()
    {
        int y = GetValue();

        // #TEST#: RTI1 Replace Ternary Expression With If
        int x = (y == 10) ? y : 1;
        require_equal(10, x);

        int i = 1;
        // #TEST#: RTI2 Replace Ternary Expression With If
        int &r = (y == 10) ? y : i;
        require_equal(10, r);

        int j = 2;
        // #TEST#: RTI3 Replace Ternary Expression With If
        int *p = (y == 10) ? &y : &j;
        require_equal(p, &y);
    }

    void TestFloatDouble()
    {
        float f = 1.0f;

        // #TEST#: RTI4 Replace Ternary Expression With If
        double x = (f == 10.0f) ? -10.0 : 10.0f;
        require_equal(10.0, x);

        float g = 2.0f;
        // #TEST#: RTI5 Replace Ternary Expression With If
        float &r = (g == 10.0f) ? g : f;
        require_equal(1.0f, r);

        // #TEST#: RTI6 Replace Ternary Expression With If
        float *p = (g == 10.0f) ? &f : &g;
        require_equal(&g, p);
    }

    int Operation1() { return 1; }
    int Operation2() { return 2; }

    void TestFunctionPointer()
    {
        int (*fn1)() = Operation1;

        // #TEST#: RTI7 Replace Ternary Expression With If
        int (*fn2)() = (fn1 == Operation1) ? Operation2 : Operation1;
        require_equal(fn2, Operation2);

        // #TEST#: RTI8 Replace Ternary Expression With If
        int (**fn3)() = (fn1 == Operation1) ? &fn1 : &fn2;
        require_equal(fn3, &fn1);

        int (&fn4)() = (fn1 == Operation1) ? Operation2 : Operation1;
        require_equal(fn4, Operation2);
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

        // #TEST#: RTI9 Replace Ternary Expression With If
        int (Foo::*mem2)() = (mem1 == &Foo::Operation1) ? &Foo::Operation2 : &Foo::Operation1;
        Foo f;
        require_equal(2, (f.*mem2)());

        // #TEST#: RTI10 Replace Ternary Expression With If
        typedef int (Foo::*mem_ptr)();
        mem_ptr &mem3 = (mem1 == &Foo::Operation1) ? mem1 : mem2;
        require_equal(1, (f.*mem3)());
    }
}

using namespace ReplaceTernaryWithIf;

void TestReplaceTernaryWithIf()
{
    TestInteger();
    TestFloatDouble();
    TestFunctionPointer();
    TestMemberPointer();
}
