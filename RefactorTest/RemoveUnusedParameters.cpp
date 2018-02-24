#include "RemoveUnusedParameters.h"
#include "Require.h"

namespace RemoveUnusedParametersNamespace
{
    // #TEST#: RUP1 Remove Unused Parameter (should not be available)
    int TestFunction(int (*fn)(int), int i)
    {
        int j;
        if (i < 0)
        {
            j = (*fn)(i);
        }
        else
        {
            j = (*fn)(i*2);
        }
        return (*fn)(j);
    }

    class Foo
    {
    public:
        // #TEST#: RUP4 Remove Unused Parameter x
        int Method1(int x) { return 2; }
        int Method2(int x) { return x; }
    };

    typedef int (Foo::*FooMemberPtr)(int);

    // #TEST#: RUP2 Remove Unused Parameter (should not be available)
    int TestMemberPointer2(Foo &f, FooMemberPtr member, int i)
    {
        int j;
        if (i < 0)
        {
            j = (f.*member)(i);
        }
        else
        {
            j = (f.*member)(i*2);
        }
        j = (f.*member)(j);
        return j;
    }
} // namespace RemoveUnusedParametersNamespace

using namespace RemoveUnusedParametersNamespace;

extern int goop(int a, int b);

// #TEST#: RUP3 Remove Unused Parameter b
extern int goop(int a, int b)
{
    return a;
}

namespace
{

int plus1(int i)
{
    return i + 1;
}

} // namespace

void TestRemoveUnusedParameter()
{
    REQUIRE_EQUAL(1, TestFunction(plus1, -1));
    REQUIRE_EQUAL(4, TestFunction(plus1, 1));
    Foo f;
    REQUIRE_EQUAL(2, f.Method1(0));
    REQUIRE_EQUAL(-1, TestMemberPointer2(f, &Foo::Method2, -1));
    REQUIRE_EQUAL(10, goop(10, 20));
}
