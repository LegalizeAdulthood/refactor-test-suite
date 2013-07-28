#include "stdafx.h"
#include <vector>

// Converts a local variable to a field variable.

namespace WidenScopePromoteToFieldNamespace
{
	void Function1() {}
	int Function2() { return 1; }

	class Foo
	{
	public:
		int Operation1()	{ return 1; }
		int Const1() const	{ return 1; }
	};

	struct Bar
	{
		Bar(int x_ = 0) : x(x_)
		{}
		int x;
	};

	int x;
}

using namespace WidenScopePromoteToFieldNamespace;

void TestWidenScopePromoteToField()
{
	// #TEST#: WSPF1 Widen Scope (promote to field)
	int y = 0;

	// #TEST#: WSPF2 Widen Scope (promote to field)
	int &x = y;

	// #TEST#: WSPF3 Widen Scope (promote to field)
	void (*function)() = &Function1;

	// #TEST#: WSPF4 Widen Scope (promote to field)
	int (Foo::*member)() = &Foo::Operation1;

	// #TEST#: WSPF5 Widen Scope (promote to field)
	int (Foo::*cmember)() const = &Foo::Const1;

	// #TEST#: WSPF6 Widen Scope (promote to field)
	Foo *p = new Foo();
	delete p;

	// #TEST#: WSPF7 Widen Scope (promote to field)
	Bar b1;

	// #TEST#: WSPF8 Widen Scope (promote to field)
	Bar *b2 = &b1;

	// #TEST#: WSPF9 Widen Scope (promote to field)
	Bar b3(10);

	// #TEST#: WSPF10 Widen Scope (promote to field)
	std::vector<float> v(10);

	// #TEST#: WSPF11 Widen Scope (promote to field)
	std::vector<int>::size_type size = 0;

	int (*integer)() = Function2;
	// #TEST#: WSPF12 Widen Scope (promote to field)
	int j = (*integer)();

	// #TEST#: WSPF13 Widen Scope (promote to field)
	std::vector<float> v1(10);
	v1.push_back(1.0f);
}
