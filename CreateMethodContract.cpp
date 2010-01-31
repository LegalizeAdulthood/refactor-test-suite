#include "stdafx.h"

// Inserts code at the beginning of a method to check that all
// parameters have been initializaed and return from the method if one is not.

namespace CreateMethodContractNamespace
{
	void PointerWithDefault(int x, int &y, int *z, char *foo = 0)
	{
		// #TEST#: CMC1 Create method contract for z
	}

	struct S
	{
		void Method1(const S *sibling)
		{
			// #TEST#: CMC8 Create method contract for sibling
		}
	};

	union U
	{
		int i;
		float f;

		void Method1(const U *sibling)
		{
			// #TEST#: CMC7 Create method contract for sibling
		}
	};

	void PointerToUnion(U *z)
	{
		// #TEST#: CMC2 Create method contract for z
	}

	void PointerToFunction(int (*fn)())
	{
		// #TEST#: CMC3 Create method contract for fn
	}

	class Foo
	{
	public:
		int Operation1() { return 1; }
		int Operation2() { return 2; }
		void Operation3() const { }
		void Operation4() const { }

		void Method1(const Foo *sibling)
		{
			// #TEST#: CMC6 Create method contract for sibling
		}
	};

	void PointerToMember(int (Foo::*member)())
	{
		// #TEST#: CMC4 Create method contract for member
	}

	void PointerToConstMember(int (Foo::*member)() const)
	{
		// #TEST#: CMC5 Create method contract for member
	}
}

using namespace CreateMethodContractNamespace;

void TestCreateMethodContract()
{
	int y;
	int z;
	PointerWithDefault(0, y, &z);
	PointerWithDefault(0, y, 0);
	PointerWithDefault(0, y, &y);
}
