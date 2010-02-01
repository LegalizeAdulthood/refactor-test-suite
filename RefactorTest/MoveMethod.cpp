#include "stdafx.h"
#include "MoveMethod.h"

// Inlines a method body into the class declaration (in a header file),
// or inversely moves a method's implementation to a source file leaving
// the declaration in the header file.

// #TEST#: MM6 Move method to header
MoveMethod::MoveMethod()
	: _int(0),
	_text(),
	_bar()
{
}

// #TEST#: MM7 Move method to header
void MoveMethod::MethodDefault(char *text, int arg1)
{
    _bar = text;
    _int = arg1;
}

// #TEST#: MM14 Move method to header
void MoveMethod::MethodConst(const std::string &text) const
{
}

// #TEST#: MM8 Move method to header
MoveMethod2::~MoveMethod2()
{
}

// #TEST#: MM10 Move method to header
void MoveMethod2::Method(const std::string &text)
{
	_text = text;
}

// #TEST#: MM11 Move method to header
void MoveMethod2::SetProtectedInt(int arg)
{
	SetInt(arg);
}

// #TEST#: MM12 Move method to header
void MoveMethod2::SetInt(int arg)
{
	_int = arg;
}

namespace MoveMethodNamespace
{
	// #TEST#: MM23 Move method to header
	MoveMethodAbstract::MoveMethodAbstract()
	{
	}

	// #TEST#: MM24 Move method to header
	MoveMethodAbstract::~MoveMethodAbstract()
	{
	}

	// #TEST#: MM25 Move method to header
	void MoveMethodAbstract::Operation()
	{
	}

	// #TEST#: MM26 Move method to header
	void MoveMethodAbstract::OperationConst() const
	{
	}

	// #TEST#: MM27 Move method to header
	void MoveMethodAbstract::OperationVirtual()
	{
	}

	// #TEST#: MM28 Move method to header
	MoveMethodConcrete::MoveMethodConcrete()
	{
	}

	// #TEST#: MM29 Move method to header
	MoveMethodConcrete::~MoveMethodConcrete()
	{
	}

	// #TEST#: MM30 Move method to header
	void MoveMethodConcrete::OperationAbstract()
	{
	}

	// #TEST#: MM35 Move method to header
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

	static void TestMoveMethod2()
	{
		MoveMethod2 m;
		m.ConstOp1(-1);
		m.ConstOp2(-2);
		std::string const name("John Belushi");
		m.Method(name);
		m.MethodDefault("default");
		m.MethodDefault("text", -1);
		m.MethodDefault2(0);
		m.MethodDefault2(0, -2);
		m.MethodDefault3(0);
		m.MethodDefault3(0, -3);
		m.MethodDefault4(0);
		m.MethodDefault4(0, -4);
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

	static void Test()
	{
		TestMoveMethod1();
		TestMoveMethod2();
		TestMoveMethodNamespace();
		TestMoveMethodAbstractInline();
	}
}

void TestMoveMethod()
{
	MoveMethodNamespace::Test();
}
