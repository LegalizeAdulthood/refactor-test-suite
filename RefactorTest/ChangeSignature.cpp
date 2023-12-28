#include "ChangeSignature.h"
#include "Require.h"

// Changes the signature of a function or method in both a header and source file;

namespace ChangeSignatureNamespace
{

// #TEST#: CS21 Rename first parameter to operand1
// #TEST#: CS22 Rename second parameter to operand2
// #TEST#: CS23 Rename function to Primitive
// #TEST#: CS24 Add const qualifier to first parameter
// #TEST#: CS25 Add const qualifier to second parameter
int Function2(int a, int b)
{
    return a + b;
}

// #TEST#: CS26 Rename first parameter to goink
// #TEST#: CS27 Rename second parameter to goink
// #TEST#: CS28 Rename method to Primitive
// #TEST#: CS29 Change type of first parameter to float
// #TEST#: CS30 Change return type to float
int ChangeSignature::Method2(int a, int b)
{
    return a + b;
}

namespace
{

void f1()
{
    // #TEST#: CS31 Rename first parameter to operand1
    // #TEST#: CS32 Rename second parameter to operand2
    // #TEST#: CS33 Rename function to Primitive
    // #TEST#: CS34 Add const qualifier to first parameter
    // #TEST#: CS35 Add const qualifier to second parameter
    REQUIRE_EQUAL(7, Function1(3, 4));
}

void f2()
{
    // #TEST#: CS36 Rename first parameter to operand1
    // #TEST#: CS37 Rename second parameter to operand2
    // #TEST#: CS38 Rename function to Primitive
    // #TEST#: CS39 Add const qualifier to first parameter
    // #TEST#: CS40 Add const qualifier to second parameter
    REQUIRE_EQUAL(7, Function2(3, 4));
}

void f4()
{
    ChangeSignature cs;
    REQUIRE_EQUAL(3, cs.Method1(1, 2));
}

}    // namespace
}    // namespace ChangeSignatureNamespace

namespace
{

void f3()
{
    // #TEST#: CS41 Rename first parameter to operand1
    // #TEST#: CS42 Rename second parameter to operand2
    // #TEST#: CS43 Rename function to Primitive
    // #TEST#: CS44 Add const qualifier to first parameter
    // #TEST#: CS45 Add const qualifier to second parameter
    REQUIRE_EQUAL(7, ChangeSignatureNamespace::Function1(3, 4));
}

}    // namespace

void TestChangeSignature()
{
    using namespace ChangeSignatureNamespace;
    f1();
    f2();
    f3();
}
