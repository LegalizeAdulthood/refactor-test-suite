#include "stdafx.h"

// Reduces the visibility of a method or property to match the highest calling visibility.

namespace ReduceVisibilityNamespace
{
    struct Bar
    {
        // #TEST#: RV1 Reduce visibility of field (should not be available)
        int x;

        // #TEST#: RV2 Reduce visibility of method
        void Method1() { }

    protected:
        // #TEST#: RV3 Reduce visibility of field
        int q;

        // #TEST#: RV4 Reduce visibility of method
        void Method2() { }

    private:
        // #TEST#: RV5 Reduce visibility of field (should not be available)
        int z;

        // #TEST#: RV6 Reduce visibility of method (should not be available)
        void Method3() { }
    };

    class Foo
    {
    public:
        // #TEST#: RV7 Reduce visibility of method (should not be available)
        void Method1() { }

        // #TEST#: RV8 Reduce visibility of method
        void Method2() { }

        // #TEST#: RV9 Reduce visibility of field
        int x;

    protected:
        // #TEST#: RV10 Reduce visibility of method
        void Method3() { }

        // #TEST#: RV11 Reduce visibility of field
        int y;

    private:
        // #TEST#: RV12 Reduce visibility of method (should not be available)
        void Method4() { }

        // #TEST#: RV13 Reduce visibility of field (should not be available)
        int z;
    };

    union Frob
    {
        // #TEST#: RV14 Reduce visibility of field (should not be available)
        int i;
        float f;
        double d;
    };

    static void TestBar()
    {
        Bar b;
        b.x = 0;
    }
    static void TestFoo()
    {
        Foo f;
        f.Method1();
    }
    static void TestFrob()
    {
        Frob f;
        f.i = 1;
    }
    static void Test()
    {
        TestBar();
        TestFoo();
        TestFrob();
    }
}

void TestReduceVisibility()
{
    ReduceVisibilityNamespace::Test();
}
