#include "stdafx.h"

// Allows to relocate a type to a different namespace and update all references.

namespace MoveTypeToNamespaceNamespace
{
	namespace Nested
	{
	};

	// #TEST#: MTN1 Move Type to namespace Nested
	class Foo
	{
	public:
		int Method1() const { return 1; }
	};
};

void TestMoveTypeToNamespace()
{
	MoveTypeToNamespaceNamespace::Foo f;
	int j = f.Method1();
}
