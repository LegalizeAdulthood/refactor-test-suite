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

}    // namespace

void TestRenameCpp17()
{
    f1();
    f2();
}