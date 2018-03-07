// Breaks an initialized declaration for a local variable into a
// declaration and a separate initialization statement.

namespace SplitInitializationFromDeclarationNamespace
{

void Function1() {}
class Foo
{
public:
    int Operation1()    { return 1; }
    int Const1() const  { return 1; }
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

    // #TEST#: SID2 Split initialization from declaration (should not be available)
    int &x = y;

    // #TEST#: SID3 Split initialization from declaration
    void (*function)() = &Function1;

    // #TEST#: SID4 Split initialization from declaration
    int (Foo::*member)() = &Foo::Operation1;

    // #TEST#: SID5 Split initialization from declaration
    int (Foo::*cmember)() const = &Foo::Const1;

    // #TEST#: SID6 Split initialization from declaration
    Foo *p = new Foo();
    delete p;

    Bar b1;
    // #TEST#: SID7 Split initialization from declaration
    Bar *b2 = &b1;

    // #TEST#: SID8 Split initialization from declaration
    volatile int volatile1 = 3;

    // #TEST#: SID9 Split initialization from declaration (should not be available)
    int const const1 = 4;

    // #TEST#: SID10 Split initialization from declaration (should not be available)
    int array[] = { 1, 2, 3 };

    // #TEST#: SID11 Split initialization from declaration
    Bar b3 = { 1, 2 };
}

}

void TestSplitInitializationFromDeclaration()
{
    SplitInitializationFromDeclarationNamespace::Test();
}
