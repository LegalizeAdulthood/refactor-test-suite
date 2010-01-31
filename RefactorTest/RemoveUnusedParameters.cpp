#include "stdafx.h"
#include <iostream>
#include "RemoveUnusedParameters.h"

namespace RemoveUnusedParametersNamespace
{
	// #TEST#: RUP1 Remove Unused Parameter (should not be available)
	void TestFunction(int (*fn)(int), int i)
	{
		int j;
		if (i < 0)
		{
			j = (*fn)(i);
		}
		else
		{
			j = (*fn)(i*2);
		}
		(*fn)(j);
	}

	class Foo
	{
	public:
		int Method1(int x) { return 2; }
	};
	typedef int (Foo::*FooMemberPtr)(int);
	// #TEST#: RUP2 Remove Unused Parameter (should not be available)
	void TestMemberPointer2(Foo &f, FooMemberPtr member, int i)
	{
		int j;
		if (i < 0)
		{
			j = (f.*member)(i);
		}
		else
		{
			j = (f.*member)(i*2);
		}
		j = (f.*member)(j);
	}
}

using namespace RemoveUnusedParametersNamespace;

static void goop(int a, int b);

// #TEST#: RUP3 Remove Unused Parameter b
static void goop(int a, int b)
{
	std::cout << a << "\n";
}
