#include "stdafx.h"

// Replaces all references to a local variable with a call to a property
// or method that returns the variable's initial value.

namespace ReplaceTemporaryWithQueryNamespace
{
    int Function1() { return 1; }
    int Function2() { return 2; }

    void TestFunction()
    {
        int (*fn)() = Function1;
        // #TEST#: RTQ1 Replace Temporary With Query on j
        int j = (*fn)();
        fn = Function2;
        j += (*fn)();
    }
}

using namespace ReplaceTemporaryWithQueryNamespace;

void TestReplaceTemporaryWithQuery()
{
}
