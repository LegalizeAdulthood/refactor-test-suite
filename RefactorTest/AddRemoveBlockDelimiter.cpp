#include "stdafx.h"

// Adds or removes optional block delimiters.

// Test adding and removing curly brace block delimiters to chunks of code.

static int AddRemoveBlockDelimiters(bool flag)
{
	int x = 0;
	if (flag)
		// #TEST#: ABD1 Add delimiters
		x = AddRemoveBlockDelimiters(false);
	else if (flag || (x > 0))
		// #TEST#: ABD2 Add delimiters
		x = -1;
	else
	// #TEST#: ABD3 Remove delimiters
	{
		x = 1;
	}

	while (x < 10)
		// #TEST#: ABD4 Add delimiters
		if (x < 10)
			// #TEST#: ABD5 Add delimiters
			do
				// #TEST#: ABD6 Add delimiters
				for (x = 1; x < 10; x++)
					// #TEST#: ABD7 Add delimiters
					x++;
			while (x < 5);

	do
	// #TEST#: ABD8 Remove delimiters
	{
		if (x < 20)
		// #TEST#: ABD9 Remove delimiters
		{
			while (x < 10)
			// #TEST#: ABD10 Remove delimiters
			{
				if (x < 10)
				// #TEST#: ABD11 Remove delimiters
				{
					do
					// #TEST#: ABD12 Remove delimiters
					{
						for (x = 1; x < 10; x++)
						// #TEST#: ABD13 Remove delimiters
						{
							x++;
						}
					}
					while (x < 5);
				}
			}
		}
	}
	while (++x < 20);
	return x;
}

void TestAddRemoveBlockDelimiter()
{
	AddRemoveBlockDelimiters(false);
}
