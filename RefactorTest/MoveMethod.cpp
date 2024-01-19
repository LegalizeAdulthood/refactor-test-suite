#include "MoveMethod.h"

// Inlines a method body into the class declaration (in a header file),
// or inversely moves a method's implementation to a source file leaving
// the declaration in the header file.

// #TEST#: MM21 Move method to header
MoveMethod::MoveMethod()
    : _int(0),
    _text(),
    _bar()
{
}

// #TEST#: MM22 Move method to header
void MoveMethod::MethodDefault(char const *text, int arg1)
{
    _bar = text;
    _int = arg1;
}

// #TEST#: MM23 Move method to header
void MoveMethod::MethodConst(const std::string &text) const
{
}

// #TEST#: MM24 Move method to header
MoveMethod2::~MoveMethod2()
{
}

// #TEST#: MM25 Move method to header
void MoveMethod2::Method(const std::string &text)
{
    _text = text;
}

// #TEST#: MM26 Move method to header
void MoveMethod2::SetProtectedInt(int arg)
{
    SetInt(arg);
}

// #TEST#: MM27 Move method to header
void MoveMethod2::SetInt(int arg)
{
    _int = arg;
}

namespace MoveMethodNamespace
{
// #TEST#: MM28 Move method to header
MoveMethodAbstract::MoveMethodAbstract()
{
}

// #TEST#: MM29 Move method to header
MoveMethodAbstract::~MoveMethodAbstract()
{
}

// #TEST#: MM30 Move method to header
void MoveMethodAbstract::Operation()
{
}

// #TEST#: MM31 Move method to header
void MoveMethodAbstract::OperationConst() const
{
}

// #TEST#: MM32 Move method to header
void MoveMethodAbstract::OperationVirtual()
{
}

// #TEST#: MM33 Move method to header
MoveMethodConcrete::MoveMethodConcrete()
{
}

// #TEST#: MM34 Move method to header
MoveMethodConcrete::~MoveMethodConcrete()
{
}

// #TEST#: MM35 Move method to header
void MoveMethodConcrete::OperationAbstract()
{
}

// #TEST#: MM36 Move method to header
MoveMethodExplicit::MoveMethodExplicit()
{
}

static void TestMoveMethod1()
{
    MoveMethod m;
    std::string const name("John Belushi");
    m.MethodConst(name);
    m.MethodConstInline(name);
    m.MethodDefault("default");
    m.MethodDefault("text", -1);
    m.MethodDefaultInline("inline");
    m.MethodDefaultInline("text", -1);
    m.MethodInline(name);
}

static char *SayFoo()
{
    static char Foo[] = "Foo";
    return &Foo[0];
}

static void TestMoveMethod2()
{
    MoveMethod2 m;
    m.ConstOp1(-1);
    m.ConstOp2(-2);
    std::string const name("John Belushi");
    m.Method(name);
    m.MethodDefault("default");
    m.MethodDefault("text", -1);
    m.MethodDefault2(SayFoo);
    m.MethodDefault2(SayFoo, -2);
    m.MethodDefault3(&MoveMethod2::Operation1);
    m.MethodDefault3(&MoveMethod2::Operation1, -3);
    m.MethodDefault4(&MoveMethod2::ConstOp1);
    m.MethodDefault4(&MoveMethod2::ConstOp1, -4);
    m.Operation1();
    m.Operation2();
}

static void TestMoveMethodNamespace()
{
    MoveMethodConcreteInline c;
    c.Operation();
    c.OperationAbstract();

    MoveMethodConcrete c2;
    c2.Operation();
    c2.OperationAbstract();
}

class MoveMethodAbstractInlineTester : public MoveMethodAbstractInline
{
public:
    virtual void OperationAbstract()
    {
    }
};

static void TestMoveMethodAbstractInline()
{
    MoveMethodAbstractInlineTester m;
    m.Operation();
    m.OperationConst();
    m.OperationVirtual();
    m.OperationAbstract();
}

static void TestMoveMethodConcreteInline()
{
    MoveMethodConcreteInline m;
    m.Operation();
    m.OperationConst();
    m.OperationVirtual();
    m.OperationAbstract();
}

static void TestMoveMethodConcrete()
{
    MoveMethodConcrete m;
    m.Operation();
    m.OperationConst();
    m.OperationVirtual();
    m.OperationAbstract();
}

static void TestMoveMethodExplicit()
{
    MoveMethodExplicit m;
}

static void TestMoveMethodExplicit2()
{
    MoveMethodExplicit2 m;
}

static void Test()
{
    TestMoveMethod1();
    TestMoveMethod2();
    TestMoveMethodNamespace();
    TestMoveMethodAbstractInline();
    TestMoveMethodConcreteInline();
    TestMoveMethodConcrete();
    TestMoveMethodExplicit();
    TestMoveMethodExplicit2();
}

}    // namespace MoveMethodNamespace

void TestMoveMethod()
{
    MoveMethodNamespace::Test();
}
