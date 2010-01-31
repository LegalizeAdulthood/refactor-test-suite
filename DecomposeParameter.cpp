#include "stdafx.h"
#include "DecomposeParameter.h"

// Replaces a single parameter with one or more new parameters,
// each standing in for a property access on the original parameter.

namespace DecomposeParameterNamespace
{
	Bagger::Bagger() : x(0)
	{
	}

	int Bagger::X() const
	{
		return x;
	}

	void Bagger::X(int val)
	{
		x = val;
	}

	int MunchBagConstReference(const Bag &bag)
	{
		// #TEST#: DP1 Decompose parameter a
		// #TEST#: DP2 Decompose parameter b
		// #TEST#: DP3 Decompose parameter c
		return bag.a + bag.b + bag.c;
	}

	int MunchBagReference(Bag &bag)
	{
		// #TEST#: DP4 Decompose parameter b
		// #TEST#: DP5 Decompose parameter c
		bag.a = bag.b + bag.c;
		return bag.b;
	}

	int MunchBagConstPointer(const Bag *bag)
	{
		// #TEST#: DP6 Decompose parameter a
		// #TEST#: DP7 Decompose parameter b
		// #TEST#: DP8 Decompose parameter c
		return bag->a + bag->b + bag->c;
	}

	int MunchBagPointer(Bag *bag)
	{
		// #TEST#: DP9 Decompose parameter b
		// #TEST#: DP10 Decompose parameter c
		bag->a = bag->b + bag->c;
		return bag->b;
	}

	int MunchBaggerConstReference(const Bagger &bagger)
	{
		// #TEST#: DP11 Decompose parameter A()
		// #TEST#: DP12 Decompose parameter B()
		// #TEST#: DP13 Decompose parameter C()
		return bagger.A() + bagger.B() + bagger.C();
	}

	int MunchBaggerReference(Bagger &bagger)
	{
		// #TEST#: DP14 Decompose parameter A()
		// #TEST#: DP15 Decompose parameter B();
		bagger.X(bagger.A() + bagger.B());
		return bagger.C();
	}

	int MunchBaggerConstPointer(const Bagger *bagger)
	{
		// #TEST#: DP16 Decompose parameter A()
		// #TEST#: DP17 Decompose parameter B()
		// #TEST#: DP18 Decompose parameter C()
		return bagger->A() + bagger->B() + bagger->C();
	}

	int MunchBaggerPointer(Bagger *bagger)
	{
		// #TEST#: DP19 Decompose parameter A()
		// #TEST#: DP20 Decompose parameter B()
		bagger->X(bagger->A() + bagger->B());
		return bagger->C();
	}

	void TestDecomposeParameterFields()
	{
		Bag bag = { 0, 1, 2 };
		int a = MunchBagConstReference(bag);
		int b = MunchBagConstPointer(&bag);
		int c = MunchBagReference(bag);
		int d = MunchBagPointer(&bag);
		int e = a + b + c + d;
	}

	void TestDecomposeParameterGetters()
	{
		Bagger bagger;
		Bag bag = { 0, 1, 2 };
		MunchBaggerConstReference(bagger);
		MunchBaggerReference(bagger);
		MunchBaggerConstPointer(&bagger);
		MunchBaggerPointer(&bagger);
	}
}

using namespace DecomposeParameterNamespace;

void TestDecomposeParameter()
{
	TestDecomposeParameterFields();
	TestDecomposeParameterGetters();
}
