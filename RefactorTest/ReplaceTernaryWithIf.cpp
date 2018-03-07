#include "Require.h"

// Converts a ternary expression into an if/else block.

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
    REQUIRE_EQUAL(10, x);

    int i = 1;
    // #TEST#: RTI2 Replace Ternary Expression With If (should not be available)
    int &r = (y == 10) ? y : i;
    REQUIRE_EQUAL(10, r);

    int j = 2;
    // #TEST#: RTI3 Replace Ternary Expression With If
    int *p = (y == 10) ? &y : &j;
    REQUIRE_EQUAL(p, &y);
}

void TestFloatDouble()
{
    float f = 1.0f;

    // #TEST#: RTI4 Replace Ternary Expression With If
    double x = (f == 10.0f) ? -10.0 : 10.0f;
    REQUIRE_EQUAL(10.0, x);

    float g = 2.0f;
    // #TEST#: RTI5 Replace Ternary Expression With If (should not be available)
    float &r = (g == 10.0f) ? g : f;
    REQUIRE_EQUAL(1.0f, r);

    // #TEST#: RTI6 Replace Ternary Expression With If
    float *p = (g == 10.0f) ? &f : &g;
    REQUIRE_EQUAL(&g, p);
}

int Operation1() { return 1; }
int Operation2() { return 2; }

void TestFunctionPointer()
{
    int (*fn1)() = Operation1;

    // #TEST#: RTI7 Replace Ternary Expression With If
    int (*fn2)() = (fn1 == Operation1) ? Operation2 : Operation1;
    REQUIRE_EQUAL(fn2, Operation2);

    // #TEST#: RTI8 Replace Ternary Expression With If
    int (**fn3)() = (fn1 == Operation1) ? &fn1 : &fn2;
    REQUIRE_EQUAL(fn3, &fn1);

    // #TEST#: RTI11 Replace Ternary Expression With If (should not be available)
    int (&fn4)() = (fn1 == Operation1) ? Operation2 : Operation1;
    REQUIRE_EQUAL(fn4, Operation2);
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
    REQUIRE_EQUAL(2, (f.*mem2)());

    typedef int (Foo::*mem_ptr)();
    // #TEST#: RTI10 Replace Ternary Expression With If (should not be available)
    mem_ptr &mem3 = (mem1 == &Foo::Operation1) ? mem1 : mem2;
    REQUIRE_EQUAL(1, (f.*mem3)());
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
