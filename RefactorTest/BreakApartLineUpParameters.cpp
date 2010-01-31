#include "stdafx.h"

// Places each parameter on a separate line.
// Moves parameter declarations up so they all exist on the same line.


// #TEST#: BAP1 Break Apart Parameters
static int Function1(int firstParameter, int secondParameter, int thirdParameter, int fourthParameter, int fifthParameter, int sixthParameter, int seventhParameter, int eighthParameter, int ninthParameter, int tenthParameter)
{
	return firstParameter + secondParameter + thirdParameter + fourthParameter + fifthParameter +
		sixthParameter + seventhParameter + eighthParameter, ninthParameter + tenthParameter;
}

// #TEST#: BAP2 Line Up Parameters
static int Function2(int firstParameter,
					 int secondParameter,
					 int thirdParameter,
					 int fourthParameter)
{
	return firstParameter - secondParameter - thirdParameter - fourthParameter;
}

void TestBreakApartLineUpParameters()
{
	// #TEST#: BAP3, BAP4 Break Apart Parameters
	int a = Function1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) + Function2(1, 2, 3, 4);
}
