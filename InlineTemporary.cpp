#include "stdafx.h"
#include <string>
#include <vector>

// Replaces all references to a local variable with its initial value.

namespace InlineTemporaryNamespace
{
	int Function1() { return 1; }
	int Function2() { return 2; }

	void TestInteger()
	{
		// #TEST#: IT1 Inline Temporary i
		int i = 4;
		int j = i*4 + 6;
		j += 10;
		j /= 15;
		j &= 7 + i;
	}

	void TestFunction()
	{
		// #TEST#: IT2 Inline Temporary fn
		int (*fn)() = Function1;
		int j = (*fn)();
		fn = Function2;
		j += (*fn)();
	}

	void TestFunction2()
	{
		int (*fn)() = Function1;
		// #TEST#: IT10 Inline Temporary fn
		int j = (*fn)();
		int (*fn2)() = Function2;
		// #TEST#: IT11 Inline Temporary fn2
		j += (*fn2)();
	}

	void TestString()
	{
		std::string temp = "This is a temp string.";

		// #TEST#: IT3 Inline Temporary temp
		std::string foo = temp;
		foo += "  This is more text.";
		foo += temp;
	}

	class Foo
	{
	public:
		int Operation1() { return 1; }
		int Operation2() { return 2; }

		int Method1() const { return 1; }
		int Method2() const { return 2; }
	};

	void TestMemberPointer()
	{
		// #TEST#: IT4 Inline Temporary member
		int (Foo::*member)() = &Foo::Operation1;
		Foo f;
		int j = (f.*member)();
		member = &Foo::Operation2;
		j += (f.*member)();
	}

	void TestConstMemberPointer()
	{
		// #TEST#: IT5 Inline Temporary member
		int (Foo::*member)() const = &Foo::Method1;
		Foo f;
		int j = (f.*member)();
		member = &Foo::Method2;
		j += (f.*member)();
	}

	void TestMemberPointer2()
	{
		int (Foo::*member)() = &Foo::Operation1;
		Foo f;
		// #TEST#: ITS6 Inline Temporary member
		int j = (f.*member)();
		int (Foo::*member2)() = &Foo::Operation2;
		// #TEST#: ITS7 Inline Temporary member2
		j += (f.*member2)();
	}

	void TestConstMemberPointer2()
	{
		int (Foo::*member)() const = &Foo::Method1;
		Foo f;
		// #TEST#: IT8 Inline Temporary member
		int j = (f.*member)();
		int (Foo::*member2)() const = &Foo::Method2;
		// #TEST#: IT9 Inline Temporary member2
		j += (f.*member2)();
	}
}

using namespace InlineTemporaryNamespace;

void TestInlineTemporary()
{
}
