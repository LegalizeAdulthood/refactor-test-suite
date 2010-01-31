#include "stdafx.h"
#include <vector>
#include <cmath>

// Replaces final assignments to the temporary variable
// with a statement that immediately returns the value.

namespace IntroduceResultVariableNamespace
{
	struct Foo
	{
		Foo(int x = 0, float f = 0.0f, double d = 0.0) 
			: _x(x), _f(f), _d(d)
		{
		}

		int _x;
		float _f;
		double _d;
	};

	class Bar
	{
	public:
		int Operation1()
		{
			return 0;
		}
		int Operation2()
		{
			return 1;
		}
	};

	int Result1(bool flag, int x)
	{
		if (flag)
		{
			// #TEST#: IRV1 Introduce result variable
			return -10;
		}
		else if (x > 10)
		{
			// #TEST#: IRV2 Introduce result variable
			return -x;
		}
		
		// #TEST#: IRV3 Introduce result variable
		return 0;
	}

	int &Result2(bool flag, int &x, int &y)
	{
		if (flag)
		{
			// #TEST#: IRV4 Introduce result variable
			return y;
		}

		// #TEST#: IRV5 Introduce result variable
		return x;
	}

	Foo Result3(bool flag, int x, float f)
	{
		if (flag)
		{
			// #TEST#: IRV6 Introduce result variable
			return Foo(x, f, -1.0);
		}
		else
		{
			// #TEST#: IRV7 Introduce result variable
			return Foo(-1, f, -2.0);
		}
	}

	std::vector<int>::size_type Result4(bool flag,
		std::vector<int>::size_type x, std::vector<int> &vec)
	{
		if (flag)
		{
			if (x > vec.size())
			{
				// #TEST#: IRV8 Introduce result variable
				return x;
			}
			else
			{
				// #TEST#: IRV9 Introduce result variable
				return vec.size();
			}
		}
		else
		{
			// #TEST#: IRV10 Introduce result variable
			return vec.size() + 1;
		}
	}

	int (Bar::*Result5(bool flag))()
	{
		if (flag)
		{
			// #TEST#: IRV11 Introduce result variable
			return &Bar::Operation2;
		}
		// #TEST#: IRV12 Introduce result variable
		return &Bar::Operation1;
	}

	int Result6(int type, int i, float f, double d)
	{
		switch (type)
		{
		case 0:
			// #TEST#: IRV13 Introduce result variable
			return i;

		case 1:
			{
				// #TEST3: IRV14 Introduce result variable
				return int(std::floor(f));
			}

		case 2:
			// #TEST#: IRV15 Introduce result variable
			return int(std::floor(d));
		}

		// #TEST#: IRV16 Introduce result variable
		return -1;
	}

}

using namespace IntroduceResultVariableNamespace;

void TestIntroduceResultVariable()
{
	int x = Result1(true, 15);
	int y = -1;
	int &r = Result2(true, x, y);
	Foo f = Result3(true, -1, -10.0f);
	std::vector<int> vec(10);
	std::vector<int>::size_type size = Result4(true, vec.size() + 10, vec);
	int (Bar::*operation)() = Result5(true);
	int z = Result6(0, 1, 2.0f, 3.0);
}
