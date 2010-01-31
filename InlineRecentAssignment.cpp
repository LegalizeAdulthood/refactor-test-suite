#include "stdafx.h"

// Replaces the identifier at the caret with its most-recent assignment.

namespace InlineRecentAssignment
{
	int Function1() { return 1; }
	int Function2() { return 2; }

	void TestFunction()
	{
		int (*fn)() = Function1;

		// #TEST#: IRA1 Inline Recent Assignment for fn
		int j = (*fn)();
	}

	class Foo
	{
	public:
		int Operation1() { return 1; }
		int Method1() const { return 1; }
	};

	void TestMemberPointer()
	{
		int (Foo::*ptr)() = &Foo::Operation1;
		Foo f;
		// #TEST#: IRA2 Inline Recent Assignment for ptr
		int j = (f.*ptr)();
	}
}

void TestInlineRecentAssignment()
{
}
