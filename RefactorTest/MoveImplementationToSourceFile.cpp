#include "stdafx.h"
#include "MoveImplementationToSourceFile.h"
#include "Require.h"

void TestMoveImplementationToSourceFile()
{
    using namespace MoveImplementationToSourceFile;

    require_equal(1, f());

    Base b;
    require_equal(1, b.f());
}
