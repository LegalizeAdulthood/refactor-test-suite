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

}    // namespace RenameCpp14

namespace
{

void f1()
{
    using namespace RenameCpp14;
    // #TEST#: R611 Rename variable template pi
    REQUIRE_EQUAL(pi<float>, circularArea(1.0f));
}

}    // namespace

void TestRenameCpp14()
{
    f1();
}
