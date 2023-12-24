#include "RenameCpp17.h"
#include "Require.h"

#include <cstdint>

// C++17 language features:
// - lambda capture of *this
// - compile time if constexpr
// - constexpr lambda
// - inline variables
// - structured bindings
// - initializers for if and switch
// - template fold expressions
// - class template argument deduction
// - non-type template parameters declared with auto
// - simplified nested namespaces
// - using-declaration declaring multiple names
// - attribute namespace don't have to repeat

namespace RenameCpp17
{

}    // namespace RenameCpp17

namespace
{

class Foo
{
public:
    int f()
    {
        // #TEST#: R640 Rename local variable fn
        // #TEST#: R641 Rename parameter val
        // #TEST#: R642 Rename use of val
        // #TEST#: R643 Rename use of m_i
        auto fn = [*this](int &val) { val = 3 + m_i; };
        // #TEST#: R644 Rename use of m_i
        m_i = 1;
        // #TEST#: R645 Rename use of fn
        // #TEST#: R646 Rename use of m_i
        fn(m_i);
        // #TEST#: R647 Rename use of m_i
        return m_i;
    }

private:
    int m_i{10};
};

// #TEST#: R648 Rename template parameter T
// #TEST#: R649 Rename template parameter N
template <typename T, size_t N>
// #TEST#: R650 Rename function f
int f()
{
    // #TEST#: R651 Rename use of T
    // #TEST#: R652 Rename use of N
    if constexpr (sizeof(T) == N)
    {
        return 10;
    }
    else
    {
        return -10;
    }
}

void f1()
{
    Foo f;
    REQUIRE_EQUAL(13, f.f());
}

void f2()
{
    // #TEST#: R653 Rename use of f
    REQUIRE_EQUAL(10, (f<std::uint32_t, 4>()));
}

void f3()
{
    // #TEST#: R654 Rename local variable initial
    constexpr int initial{10};
    // #TEST#: R655 Rename local variable fn
    // #TEST#: R656 Rename initial in capture list
    // #TEST#: R657 Rename parameter val
    // #TEST#: R658 Rename use of initial
    // #TEST#: R659 Rename use of val
    constexpr auto fn = [initial](int val) constexpr { return initial + val; };
    int value;
    // #TEST#: R660 Rename use of fn
    if constexpr (15 == fn(5))
    {
        value = 10;
    }
    else
    {
        value = 15;
    }
    // #TEST#: R661 Rename use of fn
    REQUIRE_EQUAL(15, fn(5));
    REQUIRE_EQUAL(10, value);
}

void f4()
{
    // #TEST#: R662 Rename use of g_counter
    ++RenameCpp17::g_counter;
    // #TEST#: R663 Rename use of g_counter
    REQUIRE_EQUAL(1, RenameCpp17::g_counter);
}

}    // namespace

void TestRenameCpp17()
{
    f1();
    f2();
    f3();
    f4();
}
