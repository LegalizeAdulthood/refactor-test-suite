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
// [X] spaceship compare operator
// [X] designated initializers
// [X] init statements and initializers in range for
// [X] explicit template parameters in lambdas
// [X] pack expansions in lambda init captures
// [X] consteval
// [X] constinit
// [X] aggregate initialization using parentheses
// [X] coroutines: co_yield
// [ ] coroutines: co_await
// [ ] modules
// [ ] constraints and concepts
// [X] abbreviated function template

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

// #TEST#: R907 Rename function sqr
// #TEST#: R908 Rename parameter n
consteval int sqr(int n)
{
    // #TEST#: R909 Rename first use of n
    // #TEST#: R910 Rename second use of n
    return n * n;
}

// consteval
void f6()
{
    // #TEST#: R911 Rename use of sqr
    REQUIRE_EQUAL(4, sqr(2));
}

const char *f7DynamicInit()
{
    return "dynamic initializer";
}

constexpr const char *f7Init(bool param)
{
    return param ? "constant initializer" : f7DynamicInit();
}

// #TEST#: R912 Rename variable f7Val
// #TEST#: R913 Rename function f7Init
constinit const char *f7Val = f7Init(true);

// constinit
void f7()
{
    // #TEST#: R914 Rename use of f7Val
    REQUIRE_EQUAL(std::string{"constant initializer"}, f7Val);
}

// aggregate initialization using parentheses
void f8()
{
    int one = 1;
    int two = 2;
    int three = 3;
    {
        // #TEST#: R915 Rename local variable vals
        // #TEST#: R916 Rename use of one
        const int vals[3](one, 2, 3);
        // #TEST#: R917 Rename use of vals
        REQUIRE_EQUAL(1, vals[0]);
        REQUIRE_EQUAL(2, vals[1]);
        REQUIRE_EQUAL(3, vals[2]);
    }
    {
        // #TEST#: R918 Rename struct Point
        struct Point
        {
            int x;
            int y;
            int z;
        };
        // #TEST#: R919 Rename use of Point
        // #TEST#: R920 Rename use of one
        // #TEST#: R921 Rename use of two
        const Point p(one, two);
        // #TEST#: R922 Rename use of p
        REQUIRE_EQUAL(1, p.x);
        REQUIRE_EQUAL(2, p.y);
        REQUIRE_EQUAL(0, p.z);
    }
    {
        // #TEST#: R923 Rename union Multiple
        union Multiple
        {
            int x;
            float y;
            double z;
        };
        // #TEST#: R924 Rename use of Multiple
        // #TEST#: R925 Rename local variable vals
        // #TEST#: R926 Rename use of one
        const Multiple vals(one);
        // #TEST#: R927 Rename use of vals
        REQUIRE_EQUAL(1, vals.x);
    }
}

// #TEST#: R928 Rename function fibonacci
// #TEST#: R929 Rename parameter n
RenameCpp20::Generator<int> fibonacci(int n)
{
    if (n == 0)
        co_return;

    int b{};
    // #TEST#: R930 Rename use of b
    co_yield b;

    if (n == 1)
        co_return;

    b = 1;
    // #TEST#: R931 Rename use of b
    co_yield b;

    if (n == 2)
        co_return;

    int a = 0;
    for (int i = 2; i < n; ++i)
    {
        // #TEST#: R932 Rename use of a
        // #TEST#: R933 Rename use of b
        co_yield a + b;
        const int s = a + b;
        a = b;
        b = s;
    }
}

// coroutines: co_yield
void f9()
{
    // #TEST#: R934 Rename local variable gen
    // #TEST#: R935 Rename use of fibonacci
    auto gen = fibonacci(10);
    std::vector<int> v;
    // #TEST#: R936 Rename use of gen
    for (int i = 0; gen; ++i)
    {
        // #TEST#: R937 Rename use of gen
        v.push_back(gen());
    }
    REQUIRE_EQUAL(10, v.size());
    REQUIRE_EQUAL(0, v[0]);
    REQUIRE_EQUAL(1, v[1]);
    REQUIRE_EQUAL(1, v[2]);
    REQUIRE_EQUAL(2, v[3]);
    REQUIRE_EQUAL(3, v[4]);
    REQUIRE_EQUAL(5, v[5]);
    REQUIRE_EQUAL(8, v[6]);
    REQUIRE_EQUAL(13, v[7]);
    REQUIRE_EQUAL(21, v[8]);
    REQUIRE_EQUAL(34, v[9]);
}

// #TEST#: R938 Rename function autoSqr
// #TEST#: R939 Rename parameter t
auto autoSqr(auto t)
{
    // #TEST#: R940 Rename first use of t
    // #TEST#: R941 Rename second use of t
    return t * t;
}

// #TEST#: R942 Rename function autoSqrInPlace
// #TEST#: R943 Rename parameter t
void autoSqrInPlace(auto &t)
{
    t *= t;
}

// #TEST#: R944 Rename function autoSqrPtr
// #TEST#: R945 Rename parameter t
void autoSqrPtr(auto *t)
{
    *t *= *t;
}

// #TEST#: R946 Rename function product
// #TEST#: R947 Rename parameter first
// #TEST#: R948 Rename parameter args
auto product(auto first, auto... args)
{
    // #TEST#: R949 Rename use of first
    // #TEST#: R950 Rename use of args
    return (first * ... * args);
}

// abbreviated function template
void f10()
{
    // #TEST#: R951 Rename use of autoSqr
    REQUIRE_EQUAL(4, autoSqr(2));
    // #TEST#: R952 Rename use of autoSqr
    REQUIRE_EQUAL(4.0f, autoSqr(2.0f));
    {
        int t{2};
        // #TEST#: R953 Rename use of autoSqrInPlace
        autoSqrInPlace(t);
        REQUIRE_EQUAL(4, t);
    }
    {
        float t{2.0f};
        // #TEST#: R954 Rename use of autoSqrInPlace
        autoSqrInPlace(t);
        REQUIRE_EQUAL(4.0f, t);
    }
    {
        int t{2};
        // #TEST#: R955 Rename use of autoSqrPtr
        autoSqrPtr(&t);
        REQUIRE_EQUAL(4, t);
    }
    {
        float t{2.0f};
        // #TEST#: R956 Rename use of autoSqrPtr
        autoSqrPtr(&t);
        REQUIRE_EQUAL(4.0f, t);
    }
    {
        // #TEST#: R957 Rename use of product
        REQUIRE_EQUAL(6, product(1, 2, 3));
        // #TEST#: R958 Rename use of product
        REQUIRE_EQUAL(6.0f, product(1.0f, 2.0f, 3.0f));
    }
}

}    // namespace

void TestRenameCpp20()
{
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
    f10();
}
