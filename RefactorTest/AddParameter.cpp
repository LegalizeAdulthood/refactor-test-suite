#include "AddParameter.h"

// Adds a new parameter to a method declaration and updates all calls accordingly.

static AddParameterTester *GetOne();

class AddParameterTester2
{
public:
    // #TEST#: AP24 Add parameter
    static void AddParameter()
    {
    }
};

struct AddParameterStructTester
{
    static void AddParameter()
    {
    }
};

void TestAddParameter()
{
    AddParameterFn();
    AddParameterFn(1);
    AddParameterFn(0.0f);
    const float arg = 1.0f;
    AddParameterFn(arg);
    int data = 2;
    const int &ref = data;
    AddParameterFnRef(ref);
    AddParameterFnDefault();
    AddParameterFnDefault(1);

    AddParameterTester test;
    test.AddParameter();
    test.AddParameter2<int>();
    test.AddParameter(1);
    test.AddParameter(ref);
    test.AddParameterRef(ref);
    test.AddParameterDefault();
    test.AddParameterDefault(1);

    AddParameterTester::AddParameterStaticInline();
    AddParameterTester::AddParameterStaticDefaultInline();
    AddParameterTester::AddParameterStaticDefaultInline(10);
    AddParameterTester::Static();
    AddParameterTester::StaticDefault(0);
    AddParameterTester::StaticDefault(1, 2);
    AddParameterTester::StaticTemplate<int>(0);
    AddParameterTester::StaticTemplateDefault<int>();
    AddParameterTester::StaticTemplateDefault<int>(1);
    AddParameter2<AddParameterTester2>();

    AddParameterStruct s;
    s.AddParameter();
    s.AddParameter(1);
    s.AddParameter2<int>();
    s.AddParameterRef(ref);
    s.AddParameterDefault();
    s.AddParameterDefault(1);
    AddParameterStruct::AddParameterStaticInline();
    AddParameterStruct::AddParameterStaticDefaultInline();
    AddParameterStruct::AddParameterStaticDefaultInline(10);
    AddParameterStruct::Static();
    AddParameterStruct::StaticDefault(0);
    AddParameterStruct::StaticDefault(1, 2);
    AddParameterStruct::StaticTemplate<int>(0);
    AddParameterStruct::StaticTemplateDefault<int>();
    AddParameterStruct::StaticTemplateDefault<int>(1);
    AddParameter2<AddParameterStructTester>();

    AddParameterNamespace::Outer::Inner inner;
    inner.Operation();
    AddParameterNamespace::Outer outer = AddParameterNamespace::Outer();
    outer.Operation();

    using AddParameterNamespace::Outer;
    Outer outer2;
    outer2.Operation();
    namespace Frob = AddParameterNamespace;
    Frob::Outer::Inner inner2;
    inner2.Operation();

    // default constructor
    AddParameterTester def1;
    AddParameterTester def2 = AddParameterTester();
    AddParameterTester *def3 = new AddParameterTester;
    delete def3;
    def3 = new AddParameterTester();
    delete def3;
    def3 = GetOne();
    delete def3;
}

static AddParameterTester *GetOne()
{
    return new AddParameterTester();
}

// #TEST#: AP13 Add parameter
void AddParameterFn()
{
}

// #TEST#: AP14 Add parameter
void AddParameterFn(int first)
{
}

// #TEST#: AP15 Add parameter
void AddParameterFn(float &arg)
{
    arg = 1.0f;
}

// #TEST#: AP16 Add parameter
void AddParameterFn(const float &arg)
{
}

// #TEST#: AP17 Add parameter
void AddParameterFnRef(const int &first)
{
}

// #TEST#: AP18 Add parameter
void AddParameterFnDefault(int first)
{
}

// #TEST#: AP19 Add parameter
void AddParameterTester::AddParameter(int first)
{
}

// #TEST#: AP20 Add parameter
void AddParameterTester::AddParameterRef(const int &first)
{
}

// #TEST#: AP21 Add parameter
void AddParameterTester::AddParameterDefault(int first)
{
}

// #TEST#: AP22 Add parameter
void AddParameterTester::Static()
{
}

// #TEST#: AP23 Add parameter
void AddParameterTester::StaticDefault(int x, int y)
{
}

void AddParameterStruct::AddParameter(int first)
{
}

void AddParameterStruct::AddParameterRef(const int &first)
{
}

void AddParameterStruct::AddParameterDefault(int first)
{
}

void AddParameterStruct::Static()
{
}

void AddParameterStruct::StaticDefault(int x, int y)
{
}
