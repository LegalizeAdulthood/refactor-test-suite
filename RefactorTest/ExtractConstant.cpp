#include <string>

// Declares a new constant initialized to the value
// of the string or number under the edit cursor, or caret.

namespace ExtractConstantNamespace
{
    void Function1() {}
    class Foo
    {
    public:
        int Operation1()
        {
            // #TEST#: EC5 Extract Constant (class)
            // #TEST#: EC6 Extract Constant (global)
            // #TEST#: EC7 Extract Constant (macro)
            // #TEST#: EC13 Extract Constant (local)
            return 1;
        }
        int Const1() const
        {
            return 1;
        }
        float Operation2()
        {
            return 1.0f;
        }
        double Operation3()
        {
            // #TEST#: EC8 Extract Constant
            return 1.0;
        }
        const char *Operation4()
        {
            // #TEST#: EC9 Extract Constant (class)
            // #TEST#: EC10 Extract Constant (global)
            // #TEST#: EC11 Extract Constant (macro)
            // #TEST#: EC12 Extract Constant (local)
            return "Foo";
        }
    };

    struct Bar
    {
        Bar(int x_ = 0) : x(x_)
        {}
        int Operation1()
        {
            return 1;
        }
        int x;
    };

    union Union
    {
        int x;
        float f;

        int Operation1()
        {
            return 1;
        }
    };

    int x;
}

using namespace ExtractConstantNamespace;

class ExtractConstant
{
public:
    ExtractConstant()
        : _a(0),
        _b(0)
    {
    }
    bool Test(int a, int b) const;
    std::string TestString() const;

private:
    int _a;
    int _b;
};

bool ExtractConstant::Test(int a, int b) const
{
    if (a < b)
    {
        // #TEST#: EC1 Replace all occurrences of 3 with named constant
        if (a < 3)
        {
            // #TEST#: EC2 Replace all occurrences of true with named constant
            return true;
        }
        // #TEST#: EC3 Replace all occurrences of 4 with named constant
        if (b > 4)
        {
            return true;
        }
        // #TEST#: EC4 Replace all occurrences of false with named constant
        return false;
    }
    else if (!(a < b))
    {
        if (a >= 3)
        {
            return false;
        }
        if (b <= 4)
        {
            return false;
        }
        return true;
    }
    else
    {
        if (a >= 4)
        {
            return true;
        }
        if (b <= 3)
        {
            return true;
        }
        return false;
    }
}

std::string ExtractConstant::TestString() const
{
    return "";
}

void TestExtractConstant()
{
    ExtractConstant test;
    test.Test(1, 2);
    std::string text = test.TestString();
}
