#include "RenameCpp14.h"
#include "Require.h"

// New C++ language features:
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
constexpr T pi = T(3.1415926535897932385L);

template <class T>
T circularArea(T r)
{
    // #TEST#: R609 Rename template parameter T
    // #TEST#: R610 Rename variable template pi
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
        // #TEST#: R611 Rename variable template pi
        REQUIRE_EQUAL(pi<float>, circularArea(1.0f));
    }

    // #TEST#: R612 Rename variable template pi
    REQUIRE_EQUAL(RenameCpp14::pi<float>, RenameCpp14::circularArea(1.0f));

    // rename variable template declared in header
}

void f2()
{
    // #TEST#: Rxxx Rename variable fn
    // #TEST#: Rxxx Rename parameter val in declaration
    // #TEST#: Rxxx Rename parameter val in first use
    // #TEST#: Rxxx Rename parameter val in second use
    auto fn = [](auto val) { return val * decltype(val)(2); };
    REQUIRE_EQUAL(4.0f, fn(2.0f));
    REQUIRE_EQUAL(4, fn(2));
}

}    // namespace

void TestRenameCpp14()
{
    f1();
    f2();
}
