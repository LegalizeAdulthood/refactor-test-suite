#include "Require.h"

// Makes method static and replaces all references accordingly.
namespace MakeMethodStaticNamespace
{

class Foo
{
public:
    Foo()
    {
    }

    // #TEST#: MMS1 Make method static
    int Add(int a, int b)
    {
        return a + b;
    }

    // #TEST#: MMS2 Make method static
    int Add(int b)
    {
        return _a + b;
    }

    // #TEST#: MMS3 Make method static
    int AddConst(int b) const
    {
        return _a + b;
    }

private:
    static int _a;
};

int Foo::_a = 0;

}

using namespace MakeMethodStaticNamespace;

void TestMakeMethodStatic()
{
    Foo f;
    int sum = f.Add(1, 2);
    REQUIRE_EQUAL(3, sum);
    sum = f.Add(2);
    REQUIRE_EQUAL(2, sum);
    sum = f.AddConst(3);
    REQUIRE_EQUAL(3, sum);
}
