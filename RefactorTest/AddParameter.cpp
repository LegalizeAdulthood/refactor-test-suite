#include "AddParameter.h"
#include "Require.h"

// Adds a new parameter to a method declaration and updates all calls accordingly.

namespace
{

void f1();
void f3();

}    // namespace

// #TEST#: AP149 Add parameter, int goink
static AddParameterTester *GetOne();

class AddParameterTester2
{
public:
    // #TEST#: AP24 Add parameter, int goink
    static void AddParameter()
    {
    }
};

struct AddParameterStructTester
{
    // #TEST#: AP26 Add parameter, int goink
    static void AddParameter()
    {
    }
};

static void f2()
{
    // #TEST#: AP86 Add parameter, int *goink
    AddParameterFn();
    // #TEST#: AP87 Add parameter, int goink
    AddParameterFn(1);
    // #TEST#: AP88 Add parameter, int goink
    AddParameterFn(0.0f);
    const float arg = 1.0f;
    // #TEST#: AP89 Add parameter, int goink
    AddParameterFn(arg);
    int data = 2;
    const int &ref = data;
    // #TEST#: AP90 Add parameter, int goink
    AddParameterFnRef(ref);
    // #TEST#: AP91 Add parameter before first, int goink
    AddParameterFnDefault();
    // #TEST#: AP92 Add parameter before first, int goink
    AddParameterFnDefault(1);

    AddParameterTester test;
    // #TEST#: AP93 Add parameter, int *goink
    test.AddParameter();
    // #TEST#: AP94 Add parameter, int goink
    test.AddParameter2<int>();
    // #TEST#: AP95 Add parameter, int *goink
    test.AddParameter(1);
    // #TEST#: AP96 Add parameter, int *goink
    test.AddParameter(ref);
    // #TEST#: AP97 Add parameter, int goink
    test.AddParameterRef(ref);
    // #TEST#: AP98 Add parameter before first, int goink
    test.AddParameterDefault();
    // #TEST#: AP99 Add parameter before first, int goink
    test.AddParameterDefault(1);

    // #TEST#: AP100 Add parameter, int goink
    AddParameterTester::AddParameterStaticInline();
    // #TEST#: AP101 Add parameter before first, int goink
    AddParameterTester::AddParameterStaticDefaultInline();
    // #TEST#: AP102 Add parameter before first, int goink
    AddParameterTester::AddParameterStaticDefaultInline(10);
    // #TEST#: AP103 Add parameter, int goink
    AddParameterTester::Static();
    // #TEST#: AP104 Add parameter before x, int goink
    AddParameterTester::StaticDefault(0);
    // #TEST#: AP105 Add parameter before x, int goink
    AddParameterTester::StaticDefault(1, 2);
    // #TEST#: AP106 Add parameter before x, int goink
    AddParameterTester::StaticTemplate<int>(0);
    // #TEST#: AP107 Add parameter before x, int goink
    AddParameterTester::StaticTemplateDefault<int>();
    // #TEST#: AP108 Add parameter before x, int goink
    AddParameterTester::StaticTemplateDefault<int>(1);
    // #TEST#: AP109 Add parameter, int goink
    AddParameter2<AddParameterTester2>();

    AddParameterStruct s;
    // #TEST#: AP110 Add parameter, int *goink
    s.AddParameter();
    // #TEST#: AP111 Add parameter, int goink
    s.AddParameter(1);
    // #TEST#: AP112 Add parameter, int goink
    s.AddParameter2<int>();
    // #TEST#: AP113 Add parameter, int goink
    s.AddParameterRef(ref);
    // #TEST#: AP114 Add parameter before first, int goink
    // #TEST#: AP115 Add parameter after first, int goink = 1
    s.AddParameterDefault();
    // #TEST#: AP116 Add parameter before first, int goink
    // #TEST#: AP117 Add parameter after first, int goink = 1
    s.AddParameterDefault(1);
    // #TEST#: AP118 Add parameter, int goink
    AddParameterStruct::AddParameterStaticInline();
    // #TEST#: AP119 Add parameter before first, int goink
    // #TEST#: AP120 Add parameter after first, int goink = 1
    AddParameterStruct::AddParameterStaticDefaultInline();
    // #TEST#: AP121 Add parameter before first, int goink
    // #TEST#: AP122 Add parameter after first, int goink = 1
    AddParameterStruct::AddParameterStaticDefaultInline(10);
    // #TEST#: AP123 Add parameter, int goink
    AddParameterStruct::Static();
    // #TEST#: AP124 Add parameter before y, int goink
    // #TEST#: AP125 Add parameter after y, int goink = 3
    AddParameterStruct::StaticDefault(0);
    // #TEST#: AP126 Add parameter before y, int goink
    // #TEST#: AP127 Add parameter after y, int goink = 3
    AddParameterStruct::StaticDefault(1, 2);
    // #TEST#: AP128 Add parameter, int goink
    AddParameterStruct::StaticTemplate<int>(0);
    // #TEST#: AP129 Add parameter before x, int goink
    AddParameterStruct::StaticTemplateDefault<int>();
    // #TEST#: AP130 Add parameter before x, int goink
    AddParameterStruct::StaticTemplateDefault<int>(1);
    // #TEST#: AP131 Add parameter, int goink
    AddParameter2<AddParameterStructTester>();

    AddParameterNamespace::Outer::Inner inner;
    // #TEST#: AP132 Add parameter, int goink
    inner.Operation();
    // #TEST#: AP133 Add parameter, int goink
    AddParameterNamespace::Outer outer = AddParameterNamespace::Outer();
    // #TEST#: AP134 Add parameter, int goink
    outer.Operation();

    using AddParameterNamespace::Outer;
    Outer outer2;
    // #TEST#: AP135 Add parameter, int goink
    outer2.Operation();
    namespace Frob = AddParameterNamespace;
    Frob::Outer::Inner inner2;
    // #TEST#: AP136 Add parameter, int goink
    inner2.Operation();

    // default constructor
    AddParameterTester def1;
    // #TEST#: AP137 Add parameter, int goink
    AddParameterTester def2 = AddParameterTester();
    AddParameterTester *def3 = new AddParameterTester;
    delete def3;
    // #TEST#: AP138 Add parameter, int goink
    def3 = new AddParameterTester();
    delete def3;
    // #TEST#: AP139 Add parameter, int goink
    def3 = GetOne();
    delete def3;

    f1();
}

// #TEST#: AP140 Add parameter, int goink
static AddParameterTester *GetOne()
{
    // #TEST#: AP141 Add parameter, int goink
    return new AddParameterTester();
}

// #TEST#: AP13 Add parameter, int *goink
void AddParameterFn()
{
}

// #TEST#: AP14 Add parameter, int goink
void AddParameterFn(int first)
{
}

// #TEST#: AP15 Add parameter, int goink
void AddParameterFn(float &arg)
{
    arg = 1.0f;
}

// #TEST#: AP16 Add parameter, int goink
void AddParameterFn(const float &arg)
{
}

// #TEST#: AP17 Add parameter, int goink
void AddParameterFnRef(const int &first)
{
}

// #TEST#: AP18 Add parameter before first, int goink
void AddParameterFnDefault(int first)
{
}

// #TEST#: AP19 Add parameter, int *goink
void AddParameterTester::AddParameter(int first)
{
}

// #TEST#: AP20 Add parameter, int goink
void AddParameterTester::AddParameterRef(const int &first)
{
}

// #TEST#: AP21 Add parameter before first, int goink
void AddParameterTester::AddParameterDefault(int first)
{
}

// #TEST#: AP22 Add parameter, int goink
void AddParameterTester::Static()
{
}

// #TEST#: AP23 Add parameter before x, int goink
void AddParameterTester::StaticDefault(int x, int y)
{
}

// #TEST#: AP142 Add parameter, int goink
void AddParameterStruct::AddParameter(int first)
{
}

// #TEST#: AP143 Add parameter, int goink
void AddParameterStruct::AddParameterRef(const int &first)
{
}

// #TEST#: AP144 Add parameter before first, int goink
// #TEST#: AP145 Add parameter after first, int goink = 1
void AddParameterStruct::AddParameterDefault(int first)
{
}

// #TEST#: AP146 Add parameter, int goink
void AddParameterStruct::Static()
{
}

// #TEST#: AP147 Add parameter before y, int goink
// #TEST#: AP148 Add parameter after y, int goink = 3
void AddParameterStruct::StaticDefault(int x, int y)
{
}

namespace
{

class Interface
{
public:
    virtual ~Interface()
    {
    }

    // #TEST#: AP150 Add parameter, int goink
    virtual int fn() = 0;

    // #TEST#: AP151 Add parameter, int goink
    virtual int fn2(int x) = 0;
};

class Derived : public Interface
{
public:
    ~Derived() override = default;

    // #TEST#: AP152 Add parameter, int goink
    int fn() override;

    // #TEST#: AP153 Add parameter, int goink
    int fn2(int x) override;
};

class OtherDerived : public Interface
{
public:
    ~OtherDerived() override = default;

    // #TEST#: AP154 Add parameter, int goink
    int fn() override
    {
        return 3;
    }

    // #TEST#: AP155 Add parameter, int goink
    int fn2(int x) override
    {
        return x + 2;
    }
};

class MoreDerived : public Derived
{
public:
    ~MoreDerived() override = default;

    // #TEST#: AP156 Add parameter, int goink
    int fn() override;

    // #TEST#: AP157 Add parameter, int goink
    int fn2(int x) override;
};

// #TEST#: AP158 Add parameter, int goink
int Derived::fn()
{
    return 1;
}

// #TEST#: AP159 Add parameter, int goink
int Derived::fn2(int x)
{
    return x;
}

// #TEST#: AP160 Add parameter, int goink
int MoreDerived::fn()
{
    return 2;
}

// #TEST#: AP161 Add parameter, int goink
int MoreDerived::fn2(int x)
{
    // #TEST#: AP162 Add parameter, int goink
    return 1 + Derived::fn2(x);
}

void f1()
{
    Derived d;
    // #TEST#: AP163 Add parameter, int goink
    REQUIRE_EQUAL(1, d.fn());
    // #TEST#: AP164 Add parameter, int goink
    int res = d.fn2(2);
    REQUIRE_EQUAL(2, res);

    MoreDerived md;
    // #TEST#: AP165 Add parameter, int goink
    res = md.fn();
    REQUIRE_EQUAL(2, res);
    // #TEST#: AP166 Add parameter, int goink
    res = md.fn2(2);
    REQUIRE_EQUAL(3, res);

    OtherDerived od;
    // #TEST#: AP167 Add parameter, int goink
    res = od.fn();
    REQUIRE_EQUAL(3, res);
    // #TEST#: AP168 Add parameter, int goink
    res = od.fn2(2);
    REQUIRE_EQUAL(4, res);
}

void f3()
{
    AddParameterUnion u;
    // #TEST#: AP169 Add parameter, int *goink
    u.AddParameter();
    // #TEST#: AP170 Add parameter, int goink
    u.AddParameter2<int>();
    // #TEST#: AP171 Add parameter, int goink
    u.AddParameter(0);
    const int j2{3};
    // #TEST#: AP172 Add parameter, int goink
    u.AddParameterRef(j2);
    // #TEST#: AP173 Add parameter before first, int goink
    u.AddParameterDefault(4);
    // #TEST#: AP174 Add parameter, int goink
    AddParameterUnion::AddParameterStaticInline();
    // #TEST#: AP175 Add parameter before first, int goink
    AddParameterUnion::AddParameterStaticDefaultInline(5);
    // #TEST#: AP176 Add parameter, int goink
    AddParameterUnion::Static();
    // #TEST#: AP177 Add parameter before y, int goink
    AddParameterUnion::StaticDefault(6);
    // #TEST#: AP178 Add parameter, int goink
    AddParameterUnion::StaticTemplate<int>(7);
    // #TEST#: AP179 Add parameter before x, int goink
    AddParameterUnion::StaticTemplateDefault<int>(8);

    AddParameterUnionTemplate<int> u2;
    // #TEST#: AP180 Add parameter, int *goink
    u2.AddParameter();
    // #TEST#: AP181 Add parameter, int goink
    u2.AddParameter2<int>();
    // #TEST#: AP182 Add parameter, int goink
    u2.AddParameter(1);
    const int j{3};
    // #TEST#: AP183 Add parameter, int goink
    u2.AddParameterRef(j);
    // #TEST#: AP184 Add parameter before first, int goink
    u2.AddParameterDefault();
    // #TEST#: AP185 Add parameter, int goink
    AddParameterUnionTemplate<const char *>::AddParameterStaticInline();
    // #TEST#: AP186 Add parameter before first, int goink
    AddParameterUnionTemplate<float>::AddParameterStaticDefaultInline();
    // #TEST#: AP187 Add parameter, int goink
    AddParameterUnionTemplate<double>::Static();
    // #TEST#: AP188 Add parameter before y, int goink
    AddParameterUnionTemplate<double>::StaticDefault(2);
    // #TEST#: AP202 Add parameter, int goink
    AddParameterUnionTemplate<double>::StaticTemplate<int>(3);
    // #TEST#: AP189 Add parameter before x, int goink
    AddParameterUnionTemplate<double>::StaticTemplateDefault<int>();
    // #TEST#: AP190 Add parameter, int goink
    const double k = AddParameterUnionTemplate<double>::OtherStaticTemplate();
    REQUIRE_EQUAL(0.0, k);
    // #TEST#: AP191 Add parameter, int goink
    const double k2 = u2.OtherTemplate();
    REQUIRE_EQUAL(0.0, k2);
}

}    // namespace

// #TEST#: AP192 Add parameter, int goink
void AddParameterUnion::AddParameter(int first)
{
}

// #TEST#: AP193 Add parameter, int goink
void AddParameterUnion::AddParameterRef(const int &first)
{
}

// #TEST#: AP194 Add parameter before first, int goink
void AddParameterUnion::AddParameterDefault(int first)
{
}

// #TEST#: AP195 Add parameter, int goink
void AddParameterUnion::Static()
{
}

// #TEST#: AP196 Add parameter before y, int goink
void AddParameterUnion::StaticDefault(int x, int y)
{
}

void TestAddParameter()
{
    f1();
    f2();
    f3();
}
