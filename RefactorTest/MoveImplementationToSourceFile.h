#pragma once

namespace MoveImplementationToSourceFile
{

inline int f()
{
    return 1;
}

struct Base
{
    int f()
    {
        return 1;
    }


};

}

extern void TestMoveImplementationToSourceFile();
