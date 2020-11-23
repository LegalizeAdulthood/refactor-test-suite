#include "Require.h"

#include <vector>

// Splits a single-statement multi-variable declarations into multiple lines,
// with a separate variable declaration on each line.

namespace SplitMultiVariableDeclarationNamespace
{
void Function1() {}

void Function2() {}

class Foo
{
public:
    Foo() {}

    int Operation1() { return 0; }

    int Operation2() { return 1; }

    int Const1() const { return 1; }

    int Const2() const { return 2; }
};

struct Bar
{
};

union Jumble
{
    int _i;
    float _f;
};

}    // namespace SplitMultiVariableDeclarationNamespace

using namespace SplitMultiVariableDeclarationNamespace;

void TestSplitMultiVariableDeclaration()
{
    // #TEST#: SMVD1 Split multi-variable declaration
    int i, *j, **p, &r = i, *&rp = j;
    i = 0;
    j = 0;
    p = 0;
    REQUIRE_EQUAL(i, r);
    REQUIRE_EQUAL(j, rp);

    // #TEST#: SMVD2 Split multi-variable declaration
    static int si, *sj, **sp, *&srp = sj;
    si = 0;
    sj = 0;
    sp = 0;
    REQUIRE_EQUAL(sj, srp);

    // #TEST#: SMVD3 Split multi-variable declaration
    std::vector<int>::size_type sti, stj;
    sti = std::vector<int>::size_type(0);
    stj = sti;

    // #TEST#: SMVD4 Split multi-variable declaration
    std::vector<int> vi, vj;
    vi.resize(2);
    vj.resize(2);

    // #TEST#: SMVD5 Split multi-variable declaration
    void (*fn1)(void), (*fn2)(void);
    fn1 = Function1;
    fn2 = Function2;

    // #TEST#: SMVD6 Split multi-variable declaration
    class Foo f1, f2;

    // #TEST#: SMVD7 Split multi-variable declaration
    Foo *f3 = new Foo(), &f4 = f1;

    // #TEST#: SMVD8 Split multi-variable declaration
    struct Bar s1, *s2 = new Bar();

    // #TEST#: SMVD9 Split multi-variable declaration
    Bar &s3 = s1, **s4;
    s4 = 0;

    // #TEST#: SMVD10 Split multi-variable declaration
    union Jumble j1, j2, j3, *j4;

    // #TEST#: SMVD11 Split multi-variable declaration
    Jumble &j5 = j1, **j6;
    j1._i = -1;
    j2._i = -2;
    j3._i = -3;
    j4 = &j2;
    j6 = &j4;

    // #TEST#: SMVD12 Split multi-variable declaration
    int (Foo::*member1)() = &Foo::Operation1, (Foo::*member2)() = &Foo::Operation2;

    // #TEST#: SMVD13 Split multi-variable declaration
    int (Foo::*cmember1)() const = &Foo::Const1, (Foo::*cmember2)() const = &Foo::Const2;

#define MAX_CHARS 10
    // #TEST#: SMVD14 Split multi-variable declaration
    int a1[10], *a2[10], **a3[10];
    a1[0] = 0;
    a2[0] = 0;
    a3[0] = 0;

    // #TEST#: SMVD15 Split multi-variable declaration
    char c1[MAX_CHARS + 1], c2[MAX_CHARS + 1];
    c1[0] = 0;
    c2[0] = 0;

    // #TEST#: SMVD16 Split multi-variable declaration
    char c3[20], *c4, **c5;
    c3[0] = 0;
    c4 = 0;
    c5 = 0;

    // #TEST#: SMVD17 Split multi-variable declaration
    int (Foo::*am1[10])(), (Foo::*am2[10])();
    am1[0] = 0;
    am2[0] = 0;

    // #TEST#: SMVD18 Split multi-variable declaration
    volatile int vol1, vol2;
    vol1 = 0;
    vol2 = 0;

    // #TEST#: SMVD19 Split multi-variable declaration
    register int reg1, reg2;
    reg1 = 0;
    reg2 = 0;
}
