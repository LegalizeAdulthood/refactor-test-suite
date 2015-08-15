#include "stdafx.h"
#include "MoveImplementationToSourceFile.h"

void TestMoveImplementationToSourceFile()
{
    using namespace MoveImplementationToSourceFile;

    REQUIRE_EQUAL(1, f());

    Base b;
    REQUIRE_EQUAL(1, b.f());
    b.g();

    Variant v;
    v.i = 1;
    REQUIRE_EQUAL(1, v.getInt());

    Derived d;
    REQUIRE_EQUAL(1, d.h());
    int (VirtualBase::*p)() const = d.GetOperation();
    REQUIRE_EQUAL(1, (d.*p)());

    Nested::Derived nd;
    REQUIRE_EQUAL(1, nd.h());
    int (Nested::VirtualBase::*np)() const = nd.GetOperation();
    REQUIRE_EQUAL(1, (nd.*np)());
}
