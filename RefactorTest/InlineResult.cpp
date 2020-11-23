#include <vector>

// Replaces final assignments to the temporary variable
// with a statement that immediately returns the value.

namespace InlineResultNamespace
{

struct Foo
{
    Foo(int x = 0, float f = 0.0f, double d = 0.0) : _x(x), _f(f), _d(d) {}

    int _x;
    float _f;
    double _d;
};

class Bar
{
public:
    int Operation1() { return 0; }
    int Operation2() { return 1; }
};

int Result1(bool flag, int x)
{
    // #TEST#: IR1 Inline result
    int result = 0;

    if (flag)
    {
        result = -10;
    }
    else if (x > 10)
    {
        result = -x;
    }

    return result;
}

int &Result2(bool flag, int &x, int &y)
{
    // #TEST#: IR2 Inline result
    int &result = x;

    if (flag)
    {
        result = y;
    }

    return result;
}

Foo Result3(bool flag, int x, float f)
{
    // #TEST#: IR3 Inline result
    Foo result = Foo();
    if (flag)
    {
        result = Foo(x, f, -1.0);
    }
    else
    {
        result = Foo(-1, f, -2.0);
    }
    return result;
}

std::vector<int>::size_type Result4(bool flag, std::vector<int>::size_type x, std::vector<int> &vec)
{
    // #TEST#: IR4 Inline result
    std::vector<int>::size_type result = 0;

    if (flag)
    {
        if (x > vec.size())
        {
            result = x;
        }
        else
        {
            result = vec.size();
        }
    }
    else
    {
        result = vec.size() + 1;
    }
    return result;
}

int (Bar::*Result5(bool flag))()
{
    // #TEST#: IR5 Inline result
    int (Bar::*result)() = &Bar::Operation1;
    if (flag)
    {
        result = &Bar::Operation2;
    }
    return result;
}

}    // namespace InlineResultNamespace

using namespace InlineResultNamespace;

void TestInlineResult()
{
    int x = Result1(true, 15);
    int y = -1;
    int &r = Result2(true, x, y);
    Foo f = Result3(true, -1, -10.0f);
    std::vector<int> vec(10);
    std::vector<int>::size_type size = Result4(true, vec.size() + 10, vec);
    int (Bar::*operation)() = Result5(true);
}
