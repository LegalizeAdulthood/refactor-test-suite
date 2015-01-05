#include "stdafx.h"
#include <iostream>

// Consolidates selected parameters into single object.

namespace IntroduceParameterObjectNamespace
{
    // #TEST#: IPO1 Introduce Parameter Object
    int Function1(int a, int b)
    {
        return a + b;
    }

    class Foo
    {
    public:
        Foo() {}
        void Blah();
        void Bar(int a, int b)
        {
            std::cout << "a plus b = " << (a+b) << "\n";;
        }
        void Frob(int a, int b);
    };

    void Foo::Blah()
    {
        int g = 5;
        std::cout << g << "\n";
    }

    void Foo::Frob(int a, int b)
    {
        std::cout << "a minus b = " << (a-b) << "\n";
    }

    struct Bar
    {
        int a;
        int b;
    };
}

using namespace IntroduceParameterObjectNamespace;

void TestIntroduceParameterObject()
{
    int k = Function1(3, 4);
    Foo foo;
    Bar bar = { 1, 2};
    foo.Bar(bar.a, bar.b);
    foo.Frob(2, 3);
}
