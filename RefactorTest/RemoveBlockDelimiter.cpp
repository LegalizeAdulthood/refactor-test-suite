#include "stdafx.h"

// removes optional block delimiters.

// Test adding and removing curly brace block delimiters to chunks of code.

namespace
{

int RemoveBlockDelimiters(bool flag)
{
    int x = 0;

    do
    // #TEST#: RBD1 Remove delimiters
    {
        if (x < 20)
        // #TEST#: RBD2 Remove delimiters
        {
            while (x < 10)
            // #TEST#: RBD3 Remove delimiters
            {
                if (flag)
                // #TEST#: RBD4 Remove delimiters
                {
                    do
                    // #TEST#: RBD5 Remove delimiters
                    {
                        for (int i = 1; i < 10; ++i)
                        // #TEST#: RBD6 Remove delimiters
                        {
                            ++x;
                        }
                    }
                    while (x < 5);
                }
                x += 10;
            }
        }
    }
    while (++x < 20);

    try
    // #TEST#: RBD7 Remove delimiters (should not be available)
    {
        ++x;
    }
    catch (...)
    // #TEST#: RBD8 Remove delimiters (should not be available)
    {
        --x;
    }

    return x;
}

}

void TestRemoveBlockDelimiter()
{
    RemoveBlockDelimiters(false);
}
