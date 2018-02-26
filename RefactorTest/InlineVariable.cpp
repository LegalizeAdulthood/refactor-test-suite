#include "Require.h"

#include <string>
#include <stdexcept>

// Replaces all references to a variable with its value.

namespace InlineVariableNamespace
{

int Function1() { return 1; }
int Function2() { return 2; }

void TestInteger()
{
    // #TEST#: IV1 Inline Variable i
    int i = 4;
    int j = i*4 + 6;
    require_equal(22, j);
    j += 10;
    require_equal(32, j);
    j /= 15;
    require_equal(2, j);
    j &= 7 + i;
    require_equal(2, j);
}

void TestFunction()
{
    // #TEST#: IV2 Inline Variable fn
    int (*fn)() = Function1;
    int j = (*fn)();
    require_equal(1, j);
    fn = Function2;
    j += (*fn)();
    require_equal(3, j);
}

void TestFunction2()
{
    int (*fn)() = Function1;
    // #TEST#: IV10 Inline Variable fn
    int j = (*fn)();
    require_equal(1, j);
    int (*fn2)() = Function2;
    // #TEST#: IV11 Inline Variable fn2
    j += (*fn2)();
    require_equal(3, j);
}

void TestString()
{
    std::string temp = "This is a temp string.";

    // #TEST#: IV3 Inline Variable temp
    std::string foo = temp;
    require_equal(foo, std::string{"This is a temp string."});
    foo += "  This is more text.";
    foo += temp;
    require_equal(foo, std::string{"This is a temp string." "  This is more text." "This is a temp string."});
}

class Foo
{
public:
    int Operation1() { return 1; }
    int Operation2() { return 2; }

    int Method1() const { return 1; }
    int Method2() const { return 2; }
};

void TestMemberPointer()
{
    // #TEST#: IV4 Inline Variable member
    int (Foo::*member)() = &Foo::Operation1;
    Foo f;
    int j = (f.*member)();
    require_equal(1, j);
    member = &Foo::Operation2;
    j += (f.*member)();
    require_equal(3, j);
}

void TestConstMemberPointer()
{
    // #TEST#: IV5 Inline Variable member
    int (Foo::*member)() const = &Foo::Method1;
    Foo f;
    int j = (f.*member)();
    require_equal(1, j);
    member = &Foo::Method2;
    j += (f.*member)();
    require_equal(3, j);
}

void TestMemberPointer2()
{
    int (Foo::*member)() = &Foo::Operation1;
    Foo f;
    // #TEST#: IV6 Inline Variable member
    int j = (f.*member)();
    require_equal(1, j);
    int (Foo::*member2)() = &Foo::Operation2;
    // #TEST#: IV7 Inline Variable member2
    j += (f.*member2)();
    require_equal(3, j);
}

void TestConstMemberPointer2()
{
    int (Foo::*member)() const = &Foo::Method1;
    Foo f;
    // #TEST#: IV8 Inline Variable member
    int j = (f.*member)();
    require_equal(1, j);
    int (Foo::*member2)() const = &Foo::Method2;
    // #TEST#: IV9 Inline Variable member2
    j += (f.*member2)();
    require_equal(3, j);
}

int boolParam(bool &param)
{
    static int i = 0;
    param = (++i % 2) != 0;
    return i;
}

bool globalBool = true;

void TestReference()
{
    globalBool = false;
    bool &r = globalBool;
    // #TEST#: IV12 Inline Variable r
    int value = boolParam(r);
    require_equal(1, value);
    require_equal(true, globalBool);
}

}

using namespace InlineVariableNamespace;

void TestInlineVariable()
{
    TestInteger();
    TestFunction();
    TestFunction2();
    TestString();
    TestMemberPointer();
    TestConstMemberPointer();
    TestMemberPointer2();
    TestConstMemberPointer2();
    TestReference();
}
