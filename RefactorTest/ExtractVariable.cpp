#include <string>
#include <vector>

// Creates a new local variable initialized with the selected expression.
// Optionally replaces all occurrences of the expression inside this code
// block with a reference to the newly declared local variable.

namespace ExtractVariableNamespace
{
    class Foo
    {
    public:
        void Operation1()
        {
            int x = 3;
            int y = 3 + x;
            int z = 3 + x;
            for (int i = 0; i < 3 + x; i++)
            {
                z += i;
                y *= i;
            }
        }

        void Operation2()
        {
            int x = 3;
            int y = 4;
            bool flag = true;
            const int &xr = x;
            const int &yr = y;
            // #TEST#: EXV2 Extract variable for rhs expression
            const int &z = flag ? xr : yr;
        }

        void Operation3()
        {
            bool which = true;
            // #TEST#: EXV1 Extract variable for rhs expression
            void (Foo::*member)() = which ? &Foo::Operation1 : &Foo::Operation2;
            void (Foo::*member2)() = (member == &Foo::Operation1) ?
                (which ? &Foo::Operation2 : &Foo::Operation1) : &Foo::Operation3;
        }

        void Operation4()
        {
            const int x = 3;
            const int y = 4;
            bool which = false;
            // #TEST#: EXV3 Extract variable for rhs expression
            const int *z = which ? &x : &y;
        }

        void Operation5()
        {
            std::vector<int> v1(3);
            std::vector<int> v2(4);
            bool flag = true;
            // #TEST#: EXV4 Extract variable for rhs expression
            std::vector<int> v3 = flag ? v1 : v2;
        }
    };

    void Function1()
    {
        std::string foo;
        std::string bar = "Bar!";
        // #TEST#: EXV6 Extract variable for rhs expression
        foo = bar + " meta?";
    }
};

using namespace ExtractVariableNamespace;

void TestExtractVariable()
{
    Foo f;
    f.Operation1();
    f.Operation2();
    f.Operation3();
    f.Operation4();
    f.Operation5();

    std::string foo;
    // #TEST#: EXV5 Extract variable for rhs expression
    foo = "";
}
