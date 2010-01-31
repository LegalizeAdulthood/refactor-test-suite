#include "stdafx.h"
#include "CreateOverload.h"

// Creates an overload of a method allowing you to exclude specific parameters.

namespace CreateOverloadNamespace
{
	CreateOverload::CreateOverload()
	{
	}

	// #TEST#: CO57 Create overload for constructor
	CreateOverload::CreateOverload(const char *text, int arg)
	{
	}

	// #TEST#: CO51 Create overload for class method
	void CreateOverload::bar1(const char *text, int arg1)
	{
	}

	// #TEST#: CO52 Create overload for class method, remove default argument
	// #TEST#: CO53 Create overload for class method, remove first argument
	void CreateOverload::bar2(const char *text, int arg1)
	{
	}

	// #TEST#: CO54 Create overload for class const method
	void CreateOverload::bar3(const char *text, int arg1) const
	{
	}

	// #TEST#: CO55 Create overload for class const method, remove default argument
	// #TEST#: CO56 Create overload for class const method, remove first argument
	void CreateOverload::bar4(const char *text, int arg1) const
	{
	}

	CreateOverloadStruct::CreateOverloadStruct()
	{
	}

	// #TEST#: CO58 Create overload for struct constructor
	CreateOverloadStruct::CreateOverloadStruct(const char *text, int arg)
	{
	}

	// #TEST#: CO59 Create overload for struct method
	void CreateOverloadStruct::bar1(const char *text, int arg1)
	{
	}

	// #TEST#: CO60 Create overload for struct method, remove default argument
	// #TEST#: CO61 Create overload for struct method, remove first argument
	void CreateOverloadStruct::bar2(const char *text, int arg1)
	{
	}

	// #TEST#: CO62 Create overload for struct const method
	void CreateOverloadStruct::bar3(const char *text, int arg1) const
	{
	}

	// #TEST#: CO63 Create overload for struct const method, remove default argument
	// #TEST#: CO64 Create overload for struct const method, remove first argument
	void CreateOverloadStruct::bar4(const char *text, int arg1) const
	{
	}

	// #TEST#: CO65 Create overload for union method
	void CreateOverloadUnion::bar1(int x, float y)
	{
	}

	// #TEST#: CO66 Create overload for union method, remove default argument
	// #TEST#: CO67 Create overload for union method, remove first argument
	void CreateOverloadUnion::bar2(int x, float y)
	{
	}

	// #TEST#: CO68 Create overload for union const method
	void CreateOverloadUnion::bar3(int x, float y) const
	{
	}

	// #TEST#: CO69 Create overload for union const method, remove default argument
	// #TEST#: CO70 Create overload for union const method, remove first argument
	void CreateOverloadUnion::bar4(int x, float y) const
	{
	}
}

using namespace CreateOverloadNamespace;

void TestCreateOverload()
{
	CreateOverload foo;
	foo.bar1("text", 0);
	foo.bar2("text", -1);
	foo.bar2("text");
	foo.bar3("text", -2);
	foo.bar4("text", -3);
	foo.bar4("text");
	foo.inline1("text", -4);
	foo.inline2("text", -5);
	foo.inline2("text");
	foo.inline3("text", -6);
	foo.inline4("text", -7);
	foo.inline4("text");
	CreateOverload foo1("text", -8);
	foo1.inline4("text");

	CreateOverloadStruct s1;
	s1.bar1("text", 0);
	s1.bar2("text", -1);
	s1.bar2("text");
	s1.bar3("text", -2);
	s1.bar4("text", -3);
	s1.bar4("text");
	s1.inline1("text", -4);
	s1.inline2("text", -5);
	s1.inline2("text");
	s1.inline3("text", -6);
	s1.inline4("text", -7);
	s1.inline4("text");
	CreateOverloadStruct s2("args", -4);
	s2.inline4("text");
	s2.inline5("arg1", 10);
	s2.inline5("arg1");
	s2.inline6("arg1", CreateOverloadStruct::function1("This is another test"));
	s2.inline6("arg1");

	CreateOverloadUnion u1;
	u1.bar1(0, -1.0f);
	u1.bar2(-1, -2.0f);
	u1.bar2(-2);
	u1.bar3(-3, -3.0f);
	u1.bar4(-4, -4.0f);
	u1.bar4(-5);
}
