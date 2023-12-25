#include "RenameCpp20.h"
#include "Require.h"

#include <compare>
#include <iostream>

// C++20 language features:
// - spaceship compare operator
// - designated initializers
// - init statements and initializers in range for
// - pack expansions in lambda init captures
// - consteval
// - constinit
// - aggregate initialization using parentheses
// - coroutines
// - modules
// - constraints and concepts
// - abbreviated function template

std::ostream &operator<<(std::ostream &str, const std::strong_ordering &val)
{
    if (val == std::strong_ordering::less)
        return str << "less";
    if (val == std::strong_ordering::equal)
        return str << "equal";
    if (val == std::strong_ordering::greater)
        return str << "greater";
    return str << "?unknown";
}

std::ostream &operator<<(std::ostream &str, const std::partial_ordering &val)
{
    if (val == std::partial_ordering::less)
        return str << "less";
    if (val == std::partial_ordering::equivalent)
        return str << "equivalent";
    if (val == std::partial_ordering::greater)
        return str << "greater";
    if (val == std::partial_ordering::unordered)
        return str << "unordered";
    return str << "?unknown";
}

namespace RenameCpp20
{
}    // namespace RenameCpp20

namespace
{

// spaceship operator
void f1()
{
    // integral type comparison
    {
        // #TEST#: R843 Rename x
        int x{1};
        // #TEST#: R844 Rename y
        int y{2};
        // #TEST#: R845 Rename first use of x
        // #TEST#: R846 Rename second use of x
        REQUIRE_EQUAL(std::strong_ordering::equal, x <=> x);
        // #TEST#: R847 Rename use of x
        // #TEST#: R848 Rename use of y
        REQUIRE_EQUAL(std::strong_ordering::less, x <=> y);
        // #TEST#: R849 Rename use of y
        // #TEST#: R850 Rename use of x
        REQUIRE_EQUAL(std::strong_ordering::greater, y <=> x);
    }
    // floating-point type comparison
    {
        // #TEST#: R851 Rename x
        float x{1.0f};
        // #TEST#: R852 Rename y
        float y{2.0f};
        // #TEST#: R853 Rename first use of x
        // #TEST#: R854 Rename second use of x
        REQUIRE_EQUAL(std::partial_ordering::equivalent, x <=> x);
        // #TEST#: R855 Rename use of x
        // #TEST#: R856 Rename use of y
        REQUIRE_EQUAL(std::partial_ordering::less, x <=> y);
        // #TEST#: R857 Rename use of y
        // #TEST#: R858 Rename use of x
        REQUIRE_EQUAL(std::partial_ordering::greater, y <=> x);
    }
}

// designated initializers
void f2()
{
    // #TEST#: R863 Rename use of Point
    using RenameCpp20::Point;
    {
        // #TEST#: R864 Rename use of Point
        // #TEST#: R865 Rename use of x
        Point p{.x = 10};
        // #TEST#: R866 Rename use of x
        REQUIRE_EQUAL(10, p.x);
        // #TEST#: R867 Rename use of y
        REQUIRE_EQUAL(0, p.y);
        // #TEST#: R868 Rename use of z
        REQUIRE_EQUAL(0, p.z);
    }
    {
        // #TEST#: R869 Rename use of Point
        // #TEST#: R870 Rename use of x
        Point p{.y = 10};
        // #TEST#: R871 Rename use of x
        REQUIRE_EQUAL(0, p.x);
        // #TEST#: R872 Rename use of y
        REQUIRE_EQUAL(10, p.y);
        // #TEST#: R873 Rename use of z
        REQUIRE_EQUAL(0, p.z);
    }
    {
        // #TEST#: R874 Rename use of Point
        // #TEST#: R875 Rename use of x
        Point p{.x = 20, .y = 10};
        // #TEST#: R876 Rename use of x
        REQUIRE_EQUAL(20, p.x);
        // #TEST#: R877 Rename use of y
        REQUIRE_EQUAL(10, p.y);
        // #TEST#: R878 Rename use of z
        REQUIRE_EQUAL(0, p.z);
    }
}

}    // namespace

void TestRenameCpp20()
{
    f1();
    f2();
}
