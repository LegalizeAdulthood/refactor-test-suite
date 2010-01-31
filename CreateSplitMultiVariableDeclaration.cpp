#include "stdafx.h"
#include <vector>

// Converts neighboring variable declarations of the same type into a single declaration.
// Splits a single-line multi-variable declarations into multiple lines,
// with a separate variable declaration on each line.

namespace CreateSplitMultiVariableDeclarationNamespace
{
	void Function1()
	{
	}

	void Function2()
	{
	}

	class Foo
	{
	public:
		Foo()
		{
		}

		int Operation1()
		{
			return 0;
		}

		int Operation2()
		{
			return 1;
		}

		int Const1() const
		{
			return 1;
		}

		int Const2() const
		{
			return 2;
		}
	};

	struct Bar
	{
	};

	union Jumble
	{
		int _i;
		float _f;
	};

	void TestCreateMultiVariableDeclaration()
	{
		// #TEST#: MVD13 Create multi-variable declaration
		int i;
		int j;
		i = -1;
		j = -2;

		// #TEST#: MVD14 Create multi-variable declaration
		static int si;
		static int sj;
		si = -3;
		sj = -4;

		// #TEST#: MVD15 Create multi-variable declaration
		std::vector<int>::size_type sti;
		std::vector<int>::size_type stj;
		sti = 0;
		stj = sti;

		// #TEST#: MVD16 Create multi-variable declaration
		std::vector<float> vi(3);
		std::vector<float> vj(4);
		vi = vj;

		// #TEST#: MVD17 Create multi-variable declaration
		void (*fn1)(void);
		void (*fn2)(void);
		fn1 = Function1;
		fn2 = Function2;

		// #TEST#: MVD18 Create multi-variable declaration
		class Foo f1;
		class Foo f2;
		Foo *f3;
		Foo &f4 = f1;
		f3 = new Foo();
		delete f3;
		f4 = f2;

		// #TEST#: MVD19 Create multi-variable declaration
		int (Foo::*member1)() = &Foo::Operation1;
		int (Foo::*member2)() = &Foo::Operation2;

		// #TEST#: MVD31 Create multi-variable declaration
		int (Foo::*cmember1)() const = &Foo::Const1;
		int (Foo::*cmember2)() const = &Foo::Const2;

		// #TEST#: MVD20 Create multi-variable declaration
		struct Bar s1;
		struct Bar *s2 = new Bar();

		// #TEST#: MVD21 Create multi-variable declaration
		Bar &s3 = s1;
		Bar **s4;
		s4 = &s2;

		// #TEST#: MVD22 Create multi-variable declaration
		union Jumble j1;
		union Jumble j2;
		union Jumble j3;
		union Jumble *j4;
		j1._i = -1;
		j2._i = -2;
		j3._i = -3;
		j4 = &j1;

		// #TEST#: MVD23 Create multi-variable declaration
		Jumble &j5 = j1;
		Jumble **j6;
		j6 = &j4;
	}

	void TestSplitMultiVariableDeclaration()
	{
		// #TEST#: MVD1 Split multi-variable declaration
		int i, *j, **p, &r = i, *&rp = j;
		i = 0;
		j = 0;
		p = 0;

		// #TEST#: MVD2 Split multi-variable declaration
		static int si, *sj, **sp, *&srp = sj;
		si = 0;
		sj = 0;
		sp = 0;

		// #TEST#: MVD3 Split multi-variable declaration
		std::vector<int>::size_type sti, stj;
		sti = std::vector<int>::size_type(0);
		stj = sti;

		// #TEST#: MVD4 Split multi-variable declaration
		std::vector<int> vi, vj;
		vi.resize(2);
		vj.resize(2);

		// #TEST#: MVD5 Split multi-variable declaration
		void (*fn1)(void), (*fn2)(void);
		fn1 = Function1;
		fn2 = Function2;

		// #TEST#: MVD6 Split multi-variable declaration
		class Foo f1, f2;

		// #TEST#: MVD7 Split multi-variable declaration
		Foo *f3 = new Foo(), &f4 = f1;

		// #TEST#: MVD8 Split multi-variable declaration
		struct Bar s1, *s2 = new Bar();

		// #TEST#: MVD9 Split multi-variable declaration
		Bar &s3 = s1, **s4;
		s4 = 0;

		// #TEST#: MVD10 Split multi-variable declaration
		union Jumble j1, j2, j3, *j4;

		// #TEST#: MVD11 Split multi-variable declaration
		Jumble &j5 = j1, **j6;
		j1._i = -1;
		j2._i = -2;
		j3._i = -3;
		j4 = &j2;
		j6 = &j4;

		// #TEST#: MVD12 Split multi-variable declaration
		int (Foo::*member1)() = &Foo::Operation1, (Foo::*member2)() = &Foo::Operation2;

		// #TEST#: MVD24 Split multi-variable declaration
		int (Foo::*cmember1)() const = &Foo::Const1, (Foo::*cmember2)() const = &Foo::Const2;

#define MAX_CHARS 10
		// #TEST#: MVD25 Split multi-variable declaration
		int a1[10], *a2[10], **a3[10];
		a1[0] = 0;
		a2[0] = 0;
		a3[0] = 0;

		// #TEST#: MVD26 Split multi-variable declaration
		char c1[MAX_CHARS+1], c2[MAX_CHARS+1];
		c1[0] = 0;
		c2[0] = 0;

		// #TEST#: MVD27 Split multi-variable declaration
		char c3[20], *c4, **c5;
		c3[0] = 0;
		c4 = 0;
		c5 = 0;

		// #TEST#: MVD28 Split multi-variable declaration
		int (Foo::*am1[10])(), (Foo::*am2[10])();
		am1[0] = 0;
		am2[0] = 0;

		// #TEST#: MVD29 Split multi-variable declaration
		volatile int vol1, vol2;
		vol1 = 0;
		vol2 = 0;

		// #TEST#: MVD30 Split multi-variable declaration
		register int reg1, reg2;
		reg1 = 0;
		reg2 = 0;
	}
}

using namespace CreateSplitMultiVariableDeclarationNamespace;

void TestCreateSplitMultiVariableDeclaration()
{
	TestCreateMultiVariableDeclaration();
	TestSplitMultiVariableDeclaration();
}
