#include "Require.h"

// Moves the selected code to a new method.
// Inserts the appropriate calling code into the source method or property.

namespace ExtractMethodNamespace
{
int Function1() { return 1; }
int Function1(int x) { return x; }
int Function2() { return 2; }

struct Bar
{
    int _x;
    int _y;

    void Method1()
    {
        // #TEST#: EM1 Extract Method on next line, void goink()
        _x = 3;
        _y = 4;
    }

    void ConstOperation() const
    {
        // #TEST#: EM19 Extract Method on next line, void goink(int &x) const
        int x = Function1(_x) + Function2();
        int y = x * 2;
        require_equal(_x + 2, x);
        require_equal((_x + 2) * 2, y);
    }

    int (*Method2(int x))()
    {
        int (*result)();
        if (x < 0)
        {
            // #TEST#: EM2 Extract Method on next line, void goink(int (*&result)())
            result = Function1;
        }
        else
        {
            result = Function2;
        }
        return result;
    }

    void Operation1(int x) {}
    void Operation2(int x) {}
    void Const1(int x) const {}
    void Const2(int x) const {}

    void (Bar::*Method3(int x))(int)
    {
        void (Bar::*member)(int);
        if (x < 0)
        {
            // #TEST#: EM3 Extract Method on next line, void goink(void (Bar::*&member)())
            member = &Bar::Operation1;
        }
        else
        {
            member = &Bar::Operation2;
        }
        return member;
    }

    typedef void (Bar::*MethodPtr)(int);
    MethodPtr Method4(int x)
    {
        MethodPtr member;
        if (x < 0)
        {
            // #TEST#: EM4 Extract Method on next line, void goink(MethodPtr &member)
            // #TEST#: EM20 Extract Method on rhs of assignment, MethodPtr goink()
            member = &Bar::Operation1;
        }
        else
        {
            member = &Bar::Operation2;
        }
        return member;
    }

    void (Bar::*Method5(int x))(int) const
    {
        void (Bar::*member)(int) const;
        if (x < 0)
        {
            // #TEST#: EM5 Extract Method on next line, void goink(void (Bar::*&member)(int) const)
            member = &Bar::Const1;
        }
        else
        {
            member = &Bar::Const2;
        }
        return member;
    }

    typedef void (Bar::*ConstMethodPtr)(int) const;
    ConstMethodPtr Method6(int x)
    {
        ConstMethodPtr member;
        if (x < 0)
        {
            // #TEST#: EM6 Extract Method on next line, void goink(ConstMethodPtr &member)
            member = &Bar::Const1;
        }
        else
        {
            member = &Bar::Const2;
        }
        return member;
    }
};

class Foo
{
public:
    Foo() {}

    void Method1()
    {
        // #TEST#: EM7 Extract Method on next line, void goink()
        _x = 3;
        _y = 4;
    }

    int (*Method2(int x))()
    {
        int (*result)();
        if (x < 0)
        {
            // #TEST#: EM8 Extract Method on next line, void goink(int (*&result)())
            result = Function1;
        }
        else
        {
            result = Function2;
        }
        return result;
    }

    void Operation1(int x) {}
    void Operation2(int x) {}
    void Const1(int x) const {}
    void Const2(int x) const {}

    void (Foo::*member)(int);

    void (Foo::*Method3(int x))(int)
    {
        if (x < 0)
        {
            // #TEST#: EM9 Extract Method on next line, void goink()
            member = &Foo::Operation1;
        }
        else
        {
            member = &Foo::Operation2;
        }
        return member;
    }

    typedef void (Foo::*MethodPtr)(int);
    MethodPtr Method4(int x)
    {
        if (x < 0)
        {
            // #TEST#: EM10 Extract Method on next line, void goink()
            member = &Foo::Operation1;
        }
        else
        {
            member = &Foo::Operation2;
        }
        return member;
    }

    void (Foo::*cmember)(int) const;
    void (Foo::*Method5(int x))(int) const
    {
        if (x < 0)
        {
            // #TEST#: EM11 Extract Method on next line, void goink()
            cmember = &Foo::Const1;
        }
        else
        {
            cmember = &Foo::Const2;
        }
        return cmember;
    }

    typedef void (Foo::*ConstMethodPtr)(int) const;
    ConstMethodPtr Method6(int x)
    {
        ConstMethodPtr member;
        if (x < 0)
        {
            // #TEST#: EM12 Extract Method on next line, void goink(ConstMethodPtr &member)
            member = &Foo::Const1;
        }
        else
        {
            member = &Foo::Const2;
        }
        return member;
    }

private:
    void Method2();

    int _x;
    int _y;
};

void Foo::Method2()
{
    _x = 3;
    _y = 4;
}

union Frob
{
    int i;
    float f;
    double d;

    void Method1()
    {
        // #TEST#: EM13 Extract Method on next line, void goink()
        i = 3;
    }

    int (*fn)();
    int (*Method2(int x))()
    {
        if (x < 0)
        {
            // #TEST#: EM14 Extract Method on next line, void goink()
            fn = Function1;
        }
        else
        {
            fn = Function2;
        }
        return fn;
    }

    void Operation1(int x) {}
    void Operation2(int x) {}
    void Const1(int x) const {}
    void Const2(int x) const {}

    void (Frob::*member)(int);
    void (Frob::*Method3(int x))(int)
    {
        if (x < 0)
        {
            // #TEST#: EM15 Extract Method on next line, void goink()
            member = &Frob::Operation1;
        }
        else
        {
            member = &Frob::Operation2;
        }
        return member;
    }

    typedef void (Frob::*MethodPtr)(int);
    MethodPtr member_ptr;
    MethodPtr Method4(int x)
    {
        if (x < 0)
        {
            // #TEST#: EM16 Extract Method on next line, void goink()
            member_ptr = &Frob::Operation1;
        }
        else
        {
            member_ptr = &Frob::Operation2;
        }
        return member_ptr;
    }

    void (Frob::*cmember)(int) const;
    void (Frob::*Method5(int x))(int) const
    {
        if (x < 0)
        {
            // #TEST#: EM17 Extract Method on next line, void goink()
            cmember = &Frob::Const1;
        }
        else
        {
            cmember = &Frob::Const2;
        }
        return cmember;
    }

    typedef void (Frob::*ConstMethodPtr)(int) const;
    ConstMethodPtr cmember_ptr;
    ConstMethodPtr Method6(int x)
    {
        if (x < 0)
        {
            // #TEST#: EM18 Extract Method on next line, void goink()
            cmember_ptr = &Frob::Const1;
        }
        else
        {
            cmember_ptr = &Frob::Const2;
        }
        return cmember_ptr;
    }
};

class Operator
{
public:
    operator int() { return Internal(); }

    operator float()
    {
        // #TEST#: EM21 Extract return expression, float goink()
        return float(operator int());
    }

private:
    int Internal() { return -1; }
};

}    // namespace ExtractMethodNamespace

using namespace ExtractMethodNamespace;

void TestExtractMethod()
{
    Foo f;
    f.Method1();

    Bar b;
    b.Method1();
    b.ConstOperation();
    require_equal(1, b.Method2(-1)());
    (b.*(b.Method3(-1)))(-1);

    Frob fr;
    fr.Method1();
}
