#include "stdafx.h"
#include "Rename.h"

class Rename1
{
public:
    Rename1()
        : _x(0)
    {
    }
    ~Rename1()
    {
    }
    void Operation()
    {
    }

    void Operation2()
    {
    }

private:
    int _x;
};

void TestRename1()
{
    Rename1 test;
    test.Operation();
    test.Operation2();
}
