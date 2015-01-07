#include "stdafx.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

// Replaces all references to a variable with its value.

namespace InlineTemporaryNamespace
{
    int Function1() { return 1; }
    int Function2() { return 2; }

template <typename T>
void require_equal(T expected, T actual)
{
    if (expected != actual)
    {
        std::ostringstream message;
        message << "expected " << expected << ", got " << actual;
        throw std::runtime_error(message.str().c_str());
    }
}


    void TestInteger()
    {
        // #TEST#: IV1 Inline Temporary i
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
        // #TEST#: IV2 Inline Temporary fn
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
        // #TEST#: IV10 Inline Temporary fn
        int j = (*fn)();
        require_equal(1, j);
        int (*fn2)() = Function2;
        // #TEST#: IV11 Inline Temporary fn2
        j += (*fn2)();
        require_equal(3, j);
    }

    void TestString()
    {
        std::string temp = "This is a temp string.";

        // #TEST#: IV3 Inline Temporary temp
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
        // #TEST#: IV4 Inline Temporary member
        int (Foo::*member)() = &Foo::Operation1;
        Foo f;
        int j = (f.*member)();
        member = &Foo::Operation2;
        j += (f.*member)();
    }

    void TestConstMemberPointer()
    {
        // #TEST#: IV5 Inline Temporary member
        int (Foo::*member)() const = &Foo::Method1;
        Foo f;
        int j = (f.*member)();
        member = &Foo::Method2;
        j += (f.*member)();
    }

    void TestMemberPointer2()
    {
        int (Foo::*member)() = &Foo::Operation1;
        Foo f;
        // #TEST#: IV6 Inline Temporary member
        int j = (f.*member)();
        int (Foo::*member2)() = &Foo::Operation2;
        // #TEST#: IV7 Inline Temporary member2
        j += (f.*member2)();
    }

    void TestConstMemberPointer2()
    {
        int (Foo::*member)() const = &Foo::Method1;
        Foo f;
        // #TEST#: IV8 Inline Temporary member
        int j = (f.*member)();
        int (Foo::*member2)() const = &Foo::Method2;
        // #TEST#: IV9 Inline Temporary member2
        j += (f.*member2)();
    }
}

using namespace InlineTemporaryNamespace;

void TestInlineTemporary()
{
    TestInteger();
    TestFunction();
    TestFunction2();
    TestString();
    TestMemberPointer();
    TestConstMemberPointer();
    TestMemberPointer2();
    TestConstMemberPointer2();
}
