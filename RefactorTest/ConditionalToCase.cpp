#include "stdafx.h"
#include <string>

// Converts nested if-else blocks into a switch statement or vice versa.

namespace ConditionalToCaseNamespace
{
	void TestInteger()
	{
		int i = 10;
		int j;

		// #TEST#: CTC1 Conditional to case
		if (i == 1)
		{
			j = 2;
		}
		else if (i == 2)
		{
			j = 3;
		}
		else if (i == 4)
		{
			j = 5;
		}
		else if (i != 6)
		{
			j = 7;
		}

		// #TEST#: CTC2 Conditional to case
		if (i == 1)
		{
			j = 2;
		}
		else
		{
			if (i == 2)
			{
				j = 3;
			}
			else
			{
				if (i == 4)
				{
					j = 5;
				}
				else
				{
					if (i != 6)
					{
						j = 7;
					}
				}
			}
		}

		// #TEST#: CTC3 Case to conditional
		switch (i)
		{
		case 1:
			j = 2;
			break;

		case 2:
			j = 3;
			break;

		case 4:
			j = 5;
			break;

		case 6:
			break;

		default:
			j = 7;
		}

		// #TEST#: CTC12 Conditional to case
		if (i != 6)
		{
			if (i != 4)
			{
				if (i != 2)
				{
					if (i != 1)
					{
						j = 7;
					}
					else
					{
						j = 2;
					}
				}
				else
				{
					j = 3;
				}
			}
			else
			{
				j = 5;
			}
		}
	}

	void TestFloat()
	{
		float f = 1.0f;
		float p = 0.0f;
		// #TEST#: CTC4 Conditional to case (should not be available)
		if (f == 1.0f)
		{
			p = -1.0f;
		}
		else if (f == 2.0f)
		{
			p = -2.0f;
		}
		else if (f == 3.0f)
		{
			p = -3.0f;
		}
		else if (f == 5.0f)
		{
			p = -5.0f;
		}
		else
		{
			p = 9999.0f;
		}
	}

	void TestDouble()
	{
		double d = 1.0;
		double p = 0.0;
		// #TEST#: CTC5 Conditional to case (should not be available)
		if (d == 1.0)
		{
			p = -1.0;
		}
		else if (d == 2.0)
		{
			p = -2.0;
		}
		else if (d == 3.0)
		{
			p = -3.0;
		}
		else if (d == 5.0)
		{
			p = -5.0;
		}
		else
		{
			p = 9999.0;
		}
	}

	void TestString()
	{
		std::string foo = "foo";
		std::string p = "";

		// #TEST#: CTC6 Conditional to case (should not be available)
		if (foo == "foo")
		{
			p = "-foo";
		}
		else if (foo == "bar")
		{
			p = "-bar";
		}
		else if (foo == "frob")
		{
			p = "-frob";
		}
		else
		{
			p = "ninety-nine";
		}
	}

	void TestChar()
	{
		char c = 'c';
		char p = 'p';

		// #TEST#: CTC7 Conditional to case
		if (c == 'c')
		{
			p = 'C';
		}
		else if (c == 'd')
		{
			p = 'D';
		}
		else if (c == 'f')
		{
			p = 'F';
		}
		else
		{
			p = '!';
		}
	}

	namespace Enum
	{
		enum MetaWords
		{
			Foo,
			Bar,
			Frob,
			Frobozz,
			NegFoo = -Foo,
			NegBar = -Bar,
			NegFrob = -Frob,
			NegFrobozz = -Frobozz
		};
	}

	void TestEnum()
	{
		Enum::MetaWords m = Enum::Foo;
		Enum::MetaWords p = Enum::NegFoo;

		// #TEST#: CTC8 Conditional to case
		if (m == Enum::Foo)
		{
			p = Enum::NegFoo;
		}
		else if (m == Enum::Frob)
		{
			p = Enum::NegFrob;
		}
		else if (m == Enum::Bar)
		{
			p = Enum::NegBar;
		}
		else if (m == Enum::Frobozz)
		{
			p = Enum::NegFrobozz;
		}
		else if (m == Enum::Bar)
		{
			// duplicate case
			p = Enum::NegBar;
		}
	}

	void TestFunctionPointer()
	{
		void (*f)() = TestInteger;
		void (*p)() = 0;

		// #TEST#: CTC9 Conditional to case (should not be available)
		if (f == TestInteger)
		{
			p = TestFloat;
		}
		else if (f == TestFloat)
		{
			p = TestDouble;
		}
		else if (f == TestDouble)
		{
			p = TestString;
		}
		else if (f == TestString)
		{
			p = TestChar;
		}
		else if (f == TestChar)
		{
			p = TestInteger;
		}
		else
		{
			p = TestFunctionPointer;
		}
	}

	class Members
	{
	public:
		void foo() {}
		void bar() {}
		void frob() {}
		void frobozz() {}
	};

	void TestMemberPointer()
	{
		void (Members::*f)() = &Members::foo;
		void (Members::*p)() = &Members::foo;

		// #TEST#: CTC10 Conditional to case (should not be available)
		if (f == &Members::foo)
		{
			p = &Members::bar;
		}
		else if (f == &Members::bar)
		{
			p = &Members::frob;
		}
		else if (f == &Members::frob)
		{
			p = &Members::frobozz;
		}
		else if (f == &Members::frobozz)
		{
			p = &Members::foo;
		}
		else
		{
			p = 0;
		}
	}

	void TestCharPointer()
	{
		const char *foo = "Foo";
		const char *bar = "Bar";
		const char *frobozz = "Frobozz";
		const char *f = foo;
		const char *p = "-Foo";

		// #TEST#: CTC11 Conditional to Case (should not be available)
		if (f == foo)
		{
			p = "-Foo";
		}
		else if (f == bar)
		{
			p = "-Bar";
		}
		else if (f == frobozz)
		{
			p = "-Frobozz";
		}
	}
};

using namespace ConditionalToCaseNamespace;

void TestConditionalToCase()
{
	TestInteger();
	TestFloat();
	TestDouble();
	TestString();
	TestChar();
	TestFunctionPointer();
	TestMemberPointer();
}
