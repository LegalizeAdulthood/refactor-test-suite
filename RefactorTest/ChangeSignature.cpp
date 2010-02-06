#include "stdafx.h"
#include "ChangeSignature.h"
#include <cassert>

namespace ChangeSignatureNamespace
{
	int Function2(int a, int b)
	{
		return a + b;
	}

	static void Test()
	{
		assert(7 == Function1(3, 4));
		assert(7 == Function2(3, 4));
	}
}

void TestChangeSignature()
{
	ChangeSignatureNamespace::Test();
}
