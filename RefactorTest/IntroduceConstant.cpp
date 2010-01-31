#include "stdafx.h"
#include <string>

// Declares a new constant initialized to the value
// of the string or number under the edit cursor, or caret.

namespace IntroduceConstantNamespace
{
	void Function1() {}
	class Foo
	{
	public:
		int Operation1()
		{
			// #TEST#: IC5 Introduce Constant (class)
			// #TEST#: IC6 Introduce Constant (global)
			// #TEST#: IC7 Introduce Constant (macro)
			return 1;
		}
		int Const1() const
		{
			return 1;
		}
		float Operation2()
		{
			return 1.0f;
		}
		double Operation3()
		{
			// #TEST#: IC8 Introduce Constant
			return 1.0;
		}
		const char *Operation4()
		{
			// #TEST#: IC9 Introduce Constant (class)
			// #TEST#: IC10 Introduce Constant (global)
			// #TEST#: IC11 Introduce Constant (macro)
			// #TEST#: IC12 Introduce Constant (lobal)
			return "Foo";
		}
	};

	struct Bar
	{
		Bar(int x_ = 0) : x(x_)
		{}
		int Operation1()
		{
			return 1;
		}
		int x;
	};

	union Union
	{
		int x;
		float f;

		int Operation1()
		{
			return 1;
		}
	};

	int x;
}

using namespace IntroduceConstantNamespace;

class IntroduceConstant
{
public:
	IntroduceConstant()
		: _a(0),
		_b(0)
	{
	}
	bool Test(int a, int b) const;
	std::string TestString() const;

private:
	int _a;
	int _b;
};

bool IntroduceConstant::Test(int a, int b) const
{
	if (a < b)
	{
		// #TEST#: IC1 Replace all occurrences of 3 with named constant
		if (a < 3)
		{
			// #TEST#: IC2 Replace all occurrences of true with named constant
			return true;
		}
		// #TEST#: IC3 Replace all occurrences of 4 with named constant
		if (b > 4)
		{
			return true;
		}
		// #TEST#: IC4 Replace all occurrences of false with named constant
		return false;
	}
	else if (!(a < b))
	{
		if (a >= 3)
		{
			return false;
		}
		if (b <= 4)
		{
			return false;
		}
		return true;
	}
	else
	{
		if (a >= 4)
		{
			return true;
		}
		if (b <= 3)
		{
			return true;
		}
		return false;
	}
}

std::string IntroduceConstant::TestString() const
{
	return "";
}

void TestIntroduceConstant()
{
	IntroduceConstant test;
	test.Test(1, 2);
	std::string text = test.TestString();
}
