#include "stdafx.h"
#include <string>
#include <vector>

// Encapsulates a field into a read-write property and replaces occurances
// of this this field throughout the class with the newly declared property.
//
// Encapsulates a field into a read-only property and replaces all occurrences
// of this field throughout the class with the newly declared property.

namespace EncapsulateFieldNamespace
{
	struct S
	{
		// #TEST#: EF1 Encapsulate field
		int i;
		// #TEST#: EF2 Encapsulate field
		float f;
		// #TEST#: EF3 Encapsulate field
		double d;
		// #TEST#: EF4 Encapsulate field
		char *c;
		// #TEST#: EF5 Encapsulate field
		std::string s;
		// #TEST#: EF6 Encapsulate field
		std::vector<int> v;
		// #TEST#: EF7 Encapsulate field
		std::vector<int>::size_type st;
	};

	class C
	{
	public:
		// #TEST#: EF8 Encapsulate field
		int i;
		// #TEST#: EF9 Encapsulate field
		float f;
		// #TEST#: EF10 Encapsulate field
		double d;
		// #TEST#: EF11 Encapsulate field
		char *c;
		// #TEST#: EF12 Encapsulate field
		std::string s;
		// #TEST#: EF13 Encapsulate field
		std::vector<int> v;
		// #TEST#: EF14 Encapsulate field
		std::vector<int> &r;
		// #TEST#: EF15 Encapsulate field
		std::vector<int>::size_type st;
	};

	union U
	{
		// #TEST#: EF16 Encapsulate field
		int i;
		// #TEST#: EF17 Encapsulate field
		float f;
		// #TEST#: EF18 Encapsulate field
		double d;
		// #TEST#: EF19 Encapsulate field
		char *c;
		// #TEST#: EF20 Encapsulate field
		std::string *s;
		// #TEST#: EF21 Encapsulate field
		std::vector<int> *v;
		// #TEST#: EF22 Encapsulate field
		std::vector<int> &r;
		// #TEST#: EF23 Encapsulate field
		std::vector<int>::size_type st;
	};

	struct S2
	{
		// #TEST#: EF24 Encapsulate field
		int type;
		union
		{
			// #TEST#: EF25 Encapsulate field
			int i;
			// #TEST#: EF26 Encapsulate field
			float f;
			// #TEST#: EF27 Encapsulate field
			double d;
			// #TEST#: EF28 Encapsulate field
			char *c;
			// #TEST#: EF29 Encapsulate field
			std::string *s;
			// #TEST#: EF30 Encapsulate field
			std::vector<int> *v;
			// #TEST#: EF31 Encapsulate field
			std::vector<int> &r;
			// #TEST#: EF32 Encapsulate field
			std::vector<int>::size_type st;
		};
	};
}

using namespace EncapsulateFieldNamespace;

void TestEncapsulateField()
{
}
