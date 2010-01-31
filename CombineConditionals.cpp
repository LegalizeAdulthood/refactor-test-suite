#include "stdafx.h"

// Combines two or more neighboring conditionals with identical bodies into
// a single conditional statement where each conditional expression is
// logically OR'd.

namespace CombineConditionalsNamespace
{
	int Tester()
	{
		int i = 3;
		int j = 4;

		// #TEST#: CC1 Combine conditionals
		if (i < j)
		{
			return i + j;
		}
		else
		{
			return i - j;
		}
		// #TEST#: CC2 Combine conditionals
		if (j > i)
		{
			return i + j;
		}
		else
		{
			return i - j;
		}

		i++;

		// #TEST#: CC3 Combine conditionals; should not work
		if (i < j)
		{
			return i + j;
		}
		else
		{
			return i - j;
		}
		// #TEST#: CC4 Combine conditionals; should not work
		if (j > i)
		{
			return i + j;
		}
		else
		{
			return j - i;
		}
	}

	void CombineNested1()
	{
		int x = 10;
		int y = 20;
		int z = 30;
		if (x > 5)
		{
			if (y > 5)
			{
				if (z > 10)
				{
					x = 20;
				}
				else
				{
					x = 30;
				}
			}
			else
			{
				x = 40;
			}
		}
		else if (x < 0)
		{
			if (y > 5)
			{
				if (z > 10)
				{
					x = 20;
				}
				else
				{
					x = 30;
				}
			}
			else
			{
				x = 40;
			}
		}
		else
		{
			x = 50;
		}
		//y = 30;
		//z = 50;
		//x += Tester();
	}

	void CombineNested2()
	{
		int x = 10;
		int y = 20;
		int z = 30;
		if (x > 5)
		{
			if (y > 5)
			{
				if (z > 10)
				{
					x = 20;
				}
				else
				{
					x = 30;
				}
			}
			else
			{
				x = 40;
			}
		}
		else if (x < 0)
		{
			if (y > 5)
			{
				if (z > 10)
				{
					x = 20;
				}
				else
				{
					x = 30;
				}
			}
			else
			{
				x = 40;
			}
		}
		else
		{
			x = 50;
		}
	}
}

using namespace CombineConditionalsNamespace;

void TestCombineConditionals()
{
	int i = Tester();
}
