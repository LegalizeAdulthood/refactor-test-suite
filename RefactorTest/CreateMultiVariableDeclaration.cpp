#include <vector>

// Converts neighboring variable declarations of the same type into a single declaration.

namespace CreateMultiVariableDeclarationNamespace
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

}    // namespace CreateMultiVariableDeclarationNamespace

using namespace CreateMultiVariableDeclarationNamespace;

void TestCreateMultiVariableDeclaration()
{
    // #TEST#: CMVD1 Create multi-variable declaration from next two lines
    int i;
    int j;
    i = -1;
    j = -2;

    // #TEST#: CMVD2 Create multi-variable declaration from next two lines
    static int si;
    static int sj;
    si = -3;
    sj = -4;

    // #TEST#: CMVD3 Create multi-variable declaration from next two lines
    std::vector<int>::size_type sti;
    std::vector<int>::size_type stj;
    sti = 0;
    stj = sti;

    // #TEST#: CMVD4 Create multi-variable declaration from next two lines
    std::vector<float> vi(3);
    std::vector<float> vj(4);
    vi = vj;

    // #TEST#: CMVD5 Create multi-variable declaration from next two lines
    void (*fn1)(void);
    void (*fn2)(void);
    fn1 = Function1;
    fn2 = Function2;

    // #TEST#: CMVD6 Create multi-variable declaration from next four lines
    class Foo f1;
    class Foo f2;
    Foo *f3;
    Foo &f4 = f1;
    f3 = new Foo();
    delete f3;
    f4 = f2;

    // #TEST#: CMVD7 Create multi-variable declaration from next two lines
    int (Foo::*member1)() = &Foo::Operation1;
    int (Foo::*member2)() = &Foo::Operation2;

    // #TEST#: CMVD8 Create multi-variable declaration from next two lines
    int (Foo::*cmember1)() const = &Foo::Const1;
    int (Foo::*cmember2)() const = &Foo::Const2;

    // #TEST#: CMVD9 Create multi-variable declaration from next two lines
    struct Bar s1;
    struct Bar *s2 = new Bar();

    // #TEST#: CMVD10 Create multi-variable declaration from next two lines
    Bar &s3 = s1;
    Bar **s4;
    s4 = &s2;

    // #TEST#: CMVD11 Create multi-variable declaration from next four lines
    union Jumble j1;
    union Jumble j2;
    union Jumble j3;
    union Jumble *j4;
    j1._i = -1;
    j2._i = -2;
    j3._i = -3;
    j4 = &j1;

    // #TEST#: CMVD12 Create multi-variable declaration from next two lines
    Jumble &j5 = j1;
    Jumble **j6;
    j6 = &j4;
}
