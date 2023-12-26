#include "Require.h"

// Breaks an initialized declaration for a local variable into a
// declaration and a separate initialization statement.

namespace SplitInitializationFromDeclarationNamespace
{
void Function1() {}
class Foo
{
public:
    int Operation1() { return 1; }
    int Const1() const { return 1; }
};

struct Bar
{
    int one;
    int two;
};

void Test()
{
    // #TEST#: SID1 Split initialization from declaration
    int y = 0;
    REQUIRE_EQUAL(0, y);

    // #TEST#: SID2 Split initialization from declaration (should not be available)
    int &x = y;
    REQUIRE_EQUAL(0, x);

    // #TEST#: SID3 Split initialization from declaration
    void (*function)() = &Function1;
    REQUIRE_EQUAL(&Function1, function);

    // #TEST#: SID4 Split initialization from declaration
    int (Foo::*member)() = &Foo::Operation1;
    REQUIRE_EQUAL(&Foo::Operation1, member);

    // #TEST#: SID5 Split initialization from declaration
    int (Foo::*cmember)() const = &Foo::Const1;
    REQUIRE_EQUAL(&Foo::Const1, cmember);

    // #TEST#: SID6 Split initialization from declaration
    Foo *p = new Foo();
    REQUIRE_EQUAL(true, nullptr != p);
    delete p;

    Bar b1;
    // #TEST#: SID7 Split initialization from declaration
    Bar *b2 = &b1;
    REQUIRE_EQUAL(&b1, b2);

    // #TEST#: SID8 Split initialization from declaration
    volatile int volatile1 = 3;
    REQUIRE_EQUAL(3, volatile1);

    // #TEST#: SID9 Split initialization from declaration (should not be available)
    int const const1 = 4;
    REQUIRE_EQUAL(4, const1);

    // #TEST#: SID10 Split initialization from declaration (should not be available)
    int array[] = {1, 2, 3};
    REQUIRE_EQUAL(1, array[0]);
    REQUIRE_EQUAL(2, array[1]);
    REQUIRE_EQUAL(3, array[2]);

    // #TEST#: SID11 Split initialization from declaration
    Bar b3 = {1, 2};
    REQUIRE_EQUAL(1, b3.one);
    REQUIRE_EQUAL(2, b3.two);
}

}    // namespace SplitInitializationFromDeclarationNamespace

void TestSplitInitializationFromDeclaration()
{
    SplitInitializationFromDeclarationNamespace::Test();
}
