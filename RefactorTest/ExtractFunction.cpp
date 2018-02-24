#include "Require.h"

extern void TestExtractFunctionCFile();

// Moves selected code into a new function within the enclosing namespace.

namespace ExtractFunction
{
    int TestInteger()
    {
        // #TEST#: EXF1 Extract function on statement
        int x = 3;
        REQUIRE_EQUAL(3, x);
        // #TEST#: EXF2 Extract function on statement
        x *= 3;
        REQUIRE_EQUAL(9, x);
        // #TEST#: EXF3 Extract function on statement
        x /= 3;
        REQUIRE_EQUAL(3, x);
        // #TEST#: EXF4 Extract function on statement
        x += 3;
        REQUIRE_EQUAL(6, x);
        // #TEST#: EXF5 Extract function on statement
        x -= 3;
        REQUIRE_EQUAL(3, x);
        // #TEST#: EXF6 Extract function on statement
        x %= 3;
        REQUIRE_EQUAL(0, x);
        x = 8;
        // #TEST#: EXF7 Extract function on statement
        x >>= 3U;
        REQUIRE_EQUAL(1, x);
        // #TEST#: EXF8 Extract function on statement
        x <<= 3U;
        REQUIRE_EQUAL(8, x);
        // #TEST#: EXF9 Extract function on statement
        x |= 3;
        REQUIRE_EQUAL(11, x);
        // #TEST#: EXF10 Extract function on statement
        x &= 3;
        REQUIRE_EQUAL(3, x);
        // #TEST#: EXF11 Extract function on expression
        return x + 3;
    }

    int Function1(int x) { return x; }
    int Function2(int x) { return x; }

    int (*TestFunction(int x))(int)
    {
        int (*function)(int);
        if (x > 0)
        {
            // #TEST#: EXF12 Extract function on statement
            function = Function1;
        }
        else
        {
            function = Function2;
        }
        return function;
    }

    typedef int Function(int);
    Function *TestFunction2(int x)
    {
        Function *function;
        if (x > 0)
        {
            // #TEST#: EXF13 Extract function on statement
            function = Function1;
        }
        else
        {
            function = Function2;
        }
        return function;
    }

    class Foo
    {
    public:
        int Operation1(int x) { return x; }
        int Operation2(int x) { return x*2; }

        int Method1() const { return 1; }
        int Method2() const { return 2; }
    };

    int (Foo::*TestMember(int x))(int)
    {
        int (Foo::*member)(int);
        if (x > 0)
        {
            // #TEST#: EXF14 Extract function on statement
            member = &Foo::Operation1;
        }
        else
        {
            member = &Foo::Operation2;
        }
        return member;
    }

    typedef int (Foo::*PtrMemberT)(int);
    PtrMemberT TestMember2(int x)
    {
        PtrMemberT member;
        if (x > 0)
        {
            // #TEST#: EXF15 Extract function on statement
            member = &Foo::Operation1;
        }
        else
        {
            member = &Foo::Operation2;
        }
        return member;
    }

    int (Foo::*TestConstMember(int x))() const
    {
        int (Foo::*member)() const;
        if (x > 0)
        {
            // #TEST#: EXF16 Extract function on statement
            member = &Foo::Method1;
        }
        else
        {
            member = &Foo::Method2;
        }
        return member;
    }

    typedef int (Foo::*PtrConstMemberT)() const;
    PtrConstMemberT TestConstMember2(int x)
    {
        PtrConstMemberT member;
        if (x > 0)
        {
            // #TEST#: EXF17 Extract function on statement
            member = &Foo::Method1;
        }
        else
        {
            member = &Foo::Method2;
        }
        return member;
    }

    int Function1() { return 1; }
    int Function2() { return 2; }

    struct Bar
    {
        int _x;
        int _y;

        void ConstOperation() const
        {
            // #TEST#: EXF18 Extract Function on next line
            int x = Function1() + Function2();
            int y = x*2;
        }
    };
}

using namespace ExtractFunction;

void TestExtractFunction()
{
    int x = TestInteger();
    REQUIRE_EQUAL(6, x);
    int (*function)(int) = TestFunction(x);
    function = TestFunction2(x);
    int (Foo::*member)(int) = TestMember(x);
    member = TestMember2(x);
    int (Foo::*cmember)() const = TestConstMember(x);
    cmember = TestConstMember2(x);
}
