#include "Rename.h"

namespace
{

// distinct from class Rename1 in Rename.cpp
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

} // namespace

void TestRename1()
{
    Rename1 test;
    test.Operation();
    test.Operation2();
}
