#include "Require.h"
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
    // @TEST#: EP2 Extract Parameter f
    Foo f;
    // @TEST#: EP3 Extract Parameter j
    // @TEST#: EP6 Extract Parameter f
    // @TEST#: EP4 Extract Parameter ptr
    int j = (f.*ptr)();
    require_equal(1, j);
    // @TEST#: EP5 Extract Parameter ptr
    ptr = &Foo::Operation2;
    j += (f.*ptr)();
    require_equal(3, j);
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
