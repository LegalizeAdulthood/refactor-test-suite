#include "stdafx.h"

// Adds or removes optional block delimiters.

// Test adding and removing curly brace block delimiters to chunks of code.

namespace
{

int AddBlockDelimiters(bool flag)
{
    int x = 0;
    if (flag)
        // #TEST#: ABD1 Add delimiters
        x = AddBlockDelimiters(false);
    else if (flag || (x > 0))
        // #TEST#: ABD2 Add delimiters
        x = -1;
    else
        // #TEST#: ABD3 Add delimiters
        x = 1;

    while (x < 10)
        // #TEST#: ABD4 Add delimiters
        if (x < 10)
            // #TEST#: ABD5 Add delimiters
            do
                // #TEST#: ABD6 Add delimiters
                for (x = 1; x < 10; ++x)
                    // #TEST#: ABD7 Add delimiters
                    ++x;
            while (x < 5);

    return x;
}

}

void TestAddBlockDelimiter()
{
    AddBlockDelimiters(false);
}
