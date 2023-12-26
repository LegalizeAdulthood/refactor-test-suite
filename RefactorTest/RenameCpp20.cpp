#include "RenameCpp20.h"
#include "Require.h"

#include <array>
#include <compare>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

// C++20 language features:
// - spaceship compare operator
// - designated initializers
// - init statements and initializers in range for
// - explicit template parameters in lambdas
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

// #TEST#: R879 Rename function gen
std::vector<int> gen()
{
    return {1, 2, 3, 4, 5};
}

// #TEST#: R880 Rename function sink
void sink(int sum)
{
    std::ostringstream str;
    str << sum << '\n';
}

// init statements and initializers in range for
void f3()
{
    std::vector<int> v;
    v.push_back(10);
    {
        int sum{};
        // #TEST#: R881 Rename function gen
        // #TEST#: R882 Rename local variable i
        // #TEST#: R883 Rename use of v
        for (v = gen(); const int i : v)
        {
            // #TEST#: R884 Rename use of i
            sum += i;
        }
        REQUIRE_EQUAL(1 + 2 + 3 + 4 + 5, sum);
    }
    {
        int sum{};
        // #TEST#: R885 Rename function sink
        // #TEST#: R886 Rename local variable i
        // #TEST#: R887 Rename use of v
        for (sink(sum); const int i : v)
        {
            // #TEST#: R888 Rename use of i
            sum += i;
        }
        REQUIRE_EQUAL(1 + 2 + 3 + 4 + 5, sum);
    }
}

// explicit template parameters in lambdas
void f4()
{
    // #TEST#: R889 Rename local variable fn
    // #TEST#: R890 Rename template parameter N
    // #TEST#: R891 Rename template parameter T
    // #TEST#: R892 Rename use of T
    // #TEST#: R893 Rename use of N
    auto fn = []<size_t N, typename T> { return std::array<T, N>{}; };
    // #TEST#: R894 Rename use of fn
    auto vals = fn.operator()<3, int>();
    std::iota(std::begin(vals), std::end(vals), 10);
    REQUIRE_EQUAL(3, vals.size());
    REQUIRE_EQUAL(10, vals[0]);
    REQUIRE_EQUAL(11, vals[1]);
    REQUIRE_EQUAL(12, vals[2]);
}

// #TEST#: R895 Template parameter T
// #TEST#: R896 Template parameter Args
template <typename T, typename... Args>
// #TEST#: R897 Rename first use of T
// #TEST#: R898 Rename second use of T
// #TEST#: R899 Rename use of Args
// #TEST#: R900 Rename parameter args
T f5Fn(T first, Args... args)
{
    // #TEST#: R901 Rename local variable fn
    // #TEST#: R902 Rename first use of first
    // #TEST#: R903 Rename first use of args
    // #TEST#: R904 Rename second use of first
    // #TEST#: R905 Rename second use of args
    auto fn = [first, args...] { return (first + ... + args); };
    // #TEST#: R906 Rename use of fn
    return fn();
}

// pack expansions in lambda init captures
void f5()
{
    REQUIRE_EQUAL(3, f5Fn(1, 1, 1));
}

}    // namespace

void TestRenameCpp20()
{
    f1();
    f2();
    f3();
    f4();
    f5();
}
