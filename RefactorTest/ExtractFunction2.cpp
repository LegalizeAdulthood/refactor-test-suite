#include "stdafx.h"
#include <stdio.h>

void TestExtractFunctionCFile()
{
	FILE *f = fopen("tmp.tmp", "wb");
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		// #TEST#: EXF19 Extract Function on right hand side of assignment.
		y += getc(f);
	}
	fclose(f);
}
