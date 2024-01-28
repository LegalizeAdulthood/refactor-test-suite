#include "Require.h"

// Change the order of parameters.

namespace ReorderParametersNamespace
{
int Function1(int x)
{
    return x * 2;
}

int Function2(int x)
{
    return x * 4;
}

// #TEST#: RP1 Reorder parameters
int TestFunction(int (*fn)(int), int i)
{
    int j;
    if (i < 0)
    {
        j = (*fn)(i);
    }
    else
    {
        j = (*fn)(i * 2);
    }
    return (*fn)(j);
}

class Foo
{
public:
    int Operation1(int x)
    {
        return 1 - x;
    }
    int Operation2(int x)
    {
        return 2 * x;
    }
    int Const1(int x) const
    {
        return x + 2;
    }
    int Const2(int x) const
    {
        return x + 4;
    }

    void ConstOperation3(int &x) const;
};

void Foo::ConstOperation3(int &x) const
{
    x = 2;
}

// #TEST#: RP2 Reorder parameters move parameter i to first parameter
int TestMemberPointer(Foo &f, int (Foo::*member)(int), int i)
{
    int j;
    if (i < 0)
    {
        j = (f.*member)(i);
    }
    else
    {
        j = (f.*member)(i * 2);
    }
    return (f.*member)(j);
}

// #TEST#: RP3 Reorder parameters move parameter i to first parameter
int TestConstMemberPointer(Foo &f, int (Foo::*member)(int) const, int i)
{
    int j;
    if (i < 0)
    {
        j = (f.*member)(i);
    }
    else
    {
        j = (f.*member)(i * 2);
    }
    return (f.*member)(j);
}

typedef int (Foo::*FooMemberPtr)(int);

// #TEST#: RP4 Reorder parameters move parameter i to first parameter
int TestMemberPointer2(Foo &f, FooMemberPtr member, int i)
{
    int j;
    if (i < 0)
    {
        j = (f.*member)(i);
    }
    else
    {
        j = (f.*member)(i * 2);
    }
    return (f.*member)(j);
}

typedef int (Foo::*FooConstMemberPtr)(int) const;

// #TEST#: RP5 Reorder parameters move parameter i to first parameter
int TestConstMemberPointer2(Foo &f, FooConstMemberPtr member, int i)
{
    int j;
    if (i < 0)
    {
        j = (f.*member)(i);
    }
    else
    {
        j = (f.*member)(i * 2);
    }
    return (f.*member)(j);
}

}    // namespace ReorderParametersNamespace

static int Function3(int x)
{
    return x * 4;
}

using namespace ReorderParametersNamespace;

void TestReorderParameters()
{
    REQUIRE_EQUAL(-4, TestFunction(Function1, -1));
    int result = TestFunction(Function1, 1);
    REQUIRE_EQUAL(8, result);
    Foo f;
    result = TestMemberPointer(f, &Foo::Operation1, Function2(1));
    REQUIRE_EQUAL(8, result);
    result = TestConstMemberPointer(f, &Foo::Const1, 6);
    REQUIRE_EQUAL(16, result);
    result = TestMemberPointer2(f, &Foo::Operation1, Function3(1));
    REQUIRE_EQUAL(8, result);
    result = TestConstMemberPointer2(f, &Foo::Const1, 6);
    REQUIRE_EQUAL(16, result);
}
