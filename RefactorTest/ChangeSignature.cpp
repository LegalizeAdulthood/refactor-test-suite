#include "ChangeSignature.h"
#include "Require.h"

// Changes the signature of a function or method in both a header and source file;

namespace ChangeSignatureNamespace
{
int Function2(int a, int b)
{
    return a + b;
}

static void Test()
{
    REQUIRE_EQUAL(7, Function1(3, 4));
    REQUIRE_EQUAL(7, Function2(3, 4));
}
}    // namespace ChangeSignatureNamespace

void TestChangeSignature()
{
    ChangeSignatureNamespace::Test();
}
