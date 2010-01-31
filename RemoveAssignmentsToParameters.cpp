#include "stdafx.h"
#include <string>
#include <vector>

// Converts an assignment to a parameter, into a new local variable
// and fixes all references to point to the new variable.

namespace RemoveAssignmentsToParametersNamespace
{
	class Foo
	{
	public:
		int Operation1() { return 1; }
		int Operation2() { return 2; }
		void Const1() const {}
		void Const2() const {}
	};

	void Consume(const std::string &text)
	{
	}

	void AssignValue(std::string result)
	{
		// #TEST#: RAP1 Remove assignment to parameters
		result = "Foo";
		Consume(result);
		result = "Bar";
		Consume(result);
	}

	void Assign(std::string &result)
	{
		// #TEST#: RAP2 Attempt remove assignment to parameters (shouldn't apply)
		result = "Foo";
		Consume(result);
		result = "Bar";
		Consume(result);
	}

	void Consume(int x)
	{
	}

	void Assign(int x)
	{
		// #TEST#: RAP3 Remove assignment to parameters
		Consume(x);
		x = 2;
		Consume(x);
	}

	void Consume(std::vector<int>::size_type size)
	{
	}

	void Assign2(std::vector<int>::size_type size)
	{
		Consume(size);
		// #TEST#: RAP4 Remove assignment to parameters
		size = 0;
		Consume(size);
	}

	void Consume(int (Foo::*member)())
	{
	}

	void Assign3(int (Foo::*member)())
	{
		Consume(member);
		// #TEST#: RAP5 Remove assignment to parameters
		member = &Foo::Operation2;
		Consume(member);
	}

	void Consume4(void (Foo::*cmember1)() const)
	{
	}

	void Assign4(void (Foo::*cmember1)() const)
	{
		Consume4(cmember1);
		// #TEST#: RAP6 Remove assignment to parameters
		cmember1 = &Foo::Const2;
		Consume4(cmember1);
	}
}

using namespace RemoveAssignmentsToParametersNamespace;

void TestRemoveAssignmentsToParameters()
{
	std::string text = "Text";
	Assign(text);
	int x = 2;
	Assign(x);
}
