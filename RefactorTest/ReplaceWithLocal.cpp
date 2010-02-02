#include "stdafx.h"
#include <string>

// Replaces the selected expression with a reference to a local variable
// which was previously assigned this value.

namespace ReplaceWithLocalNamespace
{
	void Test1()
	{
		std::string temp = "This is a temp string.";

		std::string foo = temp;
		foo += "  This is more text.";
		std::string bar = temp + "  Yet even more!";
		// #TEST#: RWL1 Replace With Local on rhs expression
		foo += temp + "  Yet even more!";
	}

	void Test()
	{
		Test1();
	}
}

void TestReplaceWithLocal()
{
	ReplaceWithLocalNamespace::Test();
}
