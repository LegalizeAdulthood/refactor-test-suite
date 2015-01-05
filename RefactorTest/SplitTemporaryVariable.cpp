#include "stdafx.h"

// Introduces a new local variable instead of multiple assignments to the same variable.

namespace SplitTemporaryVariableNamespace
{
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
        int (Foo::*member)() = &Foo::Operation1;
        Foo f;
        int j = (f.*member)();
        // #TEST#: ST1 Split Temporary Variable member
        member = &Foo::Operation2;
        j += (f.*member)();
    }
}

void TestSplitTemporaryVariable()
{
}
