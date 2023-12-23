#include "RenameCpp14.h"
#include "Require.h"

// New C++ language features:
// - Variable templates
// - Generic lambdas (parameters of type `auto`)
// - Lambda init capture
// - new/delete elision
// - relaxed restrictions on constexpr functions
// - binary literals
// - digit separators
// - return type deduction for functions
// - aggregate classes with default non-static member initializers

namespace RenameCpp14
{
namespace
{

// #TEST#: R606 Rename template parameter T
template <class T>
// #TEST#: R607 Rename template parameter T
// #TEST#: R608 Rename variable template pi
// #TEST#: R609 Rename use of template parameter T
constexpr T pi = T(3.1415926535897932385L);

template <class T>
T circularArea(T r)
{
    // #TEST#: R610 Rename template parameter T
    // #TEST#: R611 Rename variable template pi
    return pi<T> * r * r;
}

}    // namespace
}    // namespace RenameCpp14

namespace
{

void f1()
{
    {
        using namespace RenameCpp14;
        // #TEST#: R612 Rename variable template pi
        REQUIRE_EQUAL(pi<float>, circularArea(1.0f));
    }

    // #TEST#: R613 Rename variable template pi
    REQUIRE_EQUAL(RenameCpp14::pi<float>, RenameCpp14::circularArea(1.0f));
}

void f2()
{
    {
        using namespace RenameCpp14;
        // #TEST#: R614 Rename variable template pi2
        REQUIRE_EQUAL(pi2<float>, circularArea2(1.0f));
    }

    // #TEST#: R615 Rename variable template pi2
    REQUIRE_EQUAL(RenameCpp14::pi2<float>, RenameCpp14::circularArea2(1.0f));
}

void f3()
{
    // #TEST#: R621 Rename variable fn
    // #TEST#: R622 Rename parameter val in declaration
    // #TEST#: R623 Rename parameter val in first use
    // #TEST#: R624 Rename parameter val in second use
    auto fn = [](auto val) { return val * decltype(val)(2); };
    REQUIRE_EQUAL(4.0f, fn(2.0f));
    REQUIRE_EQUAL(4, fn(2));
}

void f4()
{
    // #TEST#: R625 Rename local variable i
    int i{2};
    // #TEST#: R626 Rename local variable fn
    // #TEST#: R627 Rename local capture variable val
    // #TEST#: R628 Rename local capture variable j
    // #TEST#: R629 Rename use of i in capture expression
    // #TEST#: R630 Rename use of val
    // #TEST#: R631 Rename use of j
    auto fn = [val = 1, j = i] { return val + j; };
    // #TEST#: R632 Rename use of fn
    REQUIRE_EQUAL(3, fn());
    // #TEST#: R633 Rename local variable fn2
    // #TEST#: R634 Rename local capture variable val
    // #TEST#: R635 Rename local capture variable j
    // #TEST#: R636 Rename use of i in capture expression
    // #TEST#: R637 Rename use of val
    // #TEST#: R638 Rename use of j
    auto fn2 = [val = 1, j = i](int k) { return val + j + k; };
    // #TEST#: R639 Rename use of fn2
    REQUIRE_EQUAL(4, fn2(1));
}

}    // namespace

void TestRenameCpp14()
{
    f1();
    f2();
    f3();
    f4();
}
