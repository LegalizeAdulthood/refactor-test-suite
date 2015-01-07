#include "stdafx.h"
#include <iostream>

// Removes all references to the field or a local declaration from the
// method, replacing it with a parameter. Calling code is adjusted to
// now pass in the field or expression of the local declaration as the
// argument for the new parameter.

namespace ExtractParameterNamespace
{
    class ExtractParameterClass
    {
    public:
        ExtractParameterClass() {}
        void Blah();
    };

    void ExtractParameterClass::Blah()
    {
        int g = 5;
        std::cout << g << "\n";
    }


    class Foo
    {
    public:
        int Operation1() { return 1; }
        int Operation2() { return 2; }
    };

    void TestMemberPointer()
    {
        // #TEST#: EP1 Extract Parameter ptr
        int (Foo::*ptr)() = &Foo::Operation1;
        Foo f;
        int j = (f.*ptr)();
        ptr = &Foo::Operation2;
        j += (f.*ptr)();
    }

    void Test()
    {
        ExtractParameterClass test;
        test.Blah();

        TestMemberPointer();
    }
}

void TestExtractParameter()
{
    ExtractParameterNamespace::Test();
}
