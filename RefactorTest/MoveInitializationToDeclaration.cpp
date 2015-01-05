#include "stdafx.h"
#include <vector>

// Combines the declaration of a local variable with its initialization or first assignment.

namespace MoveInitializationToDeclaration
{
    class Foo
    {
    public:
        int Operation1()    { return 1; }
        int Operation2()    { return 2; }
        int Const1() const  { return 1; }
        int Const2() const  { return 2; }
    };

    void Function1() {}
    void Function2() {}
}

using namespace MoveInitializationToDeclaration;

void TestMoveInitializationToDeclaration()
{
    int x;
    int *y;
    int **z;
    int ***q;
    // #TEST#: MID1 Move initialization to declaration
    y = &x;
    // #TEST#: MID2 Move initialization to declaration
    z = &y;
    // #TEST#: MID3 Move initialization to declaration
    q = &z;

    int (Foo::*member1)();
    // #TEST#: MID4 Move initialization to declaration
    member1 = &Foo::Operation1;

    int (Foo::*cmember1)() const;
    // #TEST#: MID5 Move initialization to declaration
    cmember1 = &Foo::Const1;

    void (*function1)();
    // #TEST#: MID6 Move initialization to declaration
    function1 = Function1;

    std::vector<float>::size_type size;
    // #TEST#: MID7 Move initialization to declaration
    size = 0;

    std::vector<float> v;
    // #TEST#: MID8 Move initialization to declaration
    v = std::vector<float>(3);

    int y2;
    {
        int y2;
        int &x2 = y2;
    }
    // #TEST#: MID9 Move initialization to declaration
    y2 = 0;

    void (*fn1)(void), (*fn2)(void);
    // #TEST#: MID10 Move initialization to declaration
    fn1 = Function1;
    // #TEST#: MID11 Move initialization to declaration
    fn2 = Function2;
}
