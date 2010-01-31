#include "stdafx.h"

// Creates a new file with the same name as the type at the caret,
// adds the file to the project, and then moves the type to that file,
// along with any leading comments, attributes, and XML doc comments.
// This refactoring is available when the caret is on a type declaration
// and the file contains two or more types.

namespace MoveTypeToFileNamespace
{
	class MoveTypeToFile1
	{
	};

	class MoveTypeToFile2
	{
	};

	struct MoveTypeToFile3
	{
	};

	union MoveTypeToFile4
	{
	};

	// #TEST#: MTF1 Move Type To File
	template <typename T>
	struct MoveTypeToFile5
	{
		T _t;
		static T Zero();
	};

	template <typename T>
	static T MoveTypeToFile5<T>::Zero()
	{
		return T(0);
	}
}

using namespace MoveTypeToFileNamespace;

void TestMoveTypeToFile()
{
}
