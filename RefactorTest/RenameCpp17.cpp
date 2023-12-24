#include "RenameCpp17.h"
#include "Require.h"

#include <cstdint>
#include <string>
#include <tuple>

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

void f5()
{
    // binding to arrays
    {
        // #TEST#: R665 Rename variable vals
        int vals[]{1, 2};
        // #TEST#: R666 Rename binding cx
        // #TEST#: R667 Rename binding cy
        // #TEST#: R668 Rename use of vals
        const auto [cx, cy] = vals;
        // #TEST#: R669 Rename use of cx
        REQUIRE_EQUAL(1, cx);
        // #TEST#: R670 Rename use of cy
        REQUIRE_EQUAL(2, cy);
        // #TEST#: R671 Rename binding x
        // #TEST#: R672 Rename binding y
        // #TEST#: R673 Rename use of vals
        auto [x, y] = vals;
        // #TEST#: R674 Rename use of x
        REQUIRE_EQUAL(1, x);
        // #TEST#: R675 Rename use of y
        REQUIRE_EQUAL(2, y);
        // #TEST#: R676 Rename binding vx
        // #TEST#: R677 Rename binding vy
        // #TEST#: R678 Rename use of vals
        auto &[vx, vy] = vals;
        // #TEST#: R679 Rename use of vx
        vx = 4;
        // #TEST#: R680 Rename use of vy
        vy = 5;
        REQUIRE_EQUAL(4, vals[0]);
        REQUIRE_EQUAL(5, vals[1]);
        // #TEST#: R681 Rename binding crx
        // #TEST#: R682 Rename binding cry
        // #TEST#: R683 Rename use of vals
        const auto &[crx, cry] = vals;
        // #TEST#: R684 Rename use of crx
        REQUIRE_EQUAL(4, crx);
        // #TEST#: R685 Rename use of cry
        REQUIRE_EQUAL(5, cry);
    }

    // binding to tuple-like type
    {
        using pair = std::tuple<int, std::string>;
        pair p{1, "one"};
        // #TEST#: R686 Rename binding val
        // #TEST#: R687 Rename binding name
        // #TEST#: R688 Rename use of p
        const auto [val, name] = p;
        REQUIRE_EQUAL(1, val);
        REQUIRE_EQUAL(std::string{"one"}, name);
        // #TEST#: R689 Rename binding val2
        // #TEST#: R690 Rename binding name2
        // #TEST#: R691 Rename use of p
        auto [val2, name2] = p;
        // #TEST#: R692 Rename use of val2
        REQUIRE_EQUAL(1, val2);
        // #TEST#: R693 Rename use of name2
        REQUIRE_EQUAL(std::string{"one"}, name2);
        // #TEST#: R694 Rename binding val3
        // #TEST#: R695 Rename binding name3
        // #TEST#: R696 Rename use of p
        auto &[val3, name3] = p;
        // #TEST#: R697 Rename use of val3
        val3 = 11;
        // #TEST#: R698 Rename use of name3
        name3 = "eleven";
        REQUIRE_EQUAL(11, std::get<0>(p));
        REQUIRE_EQUAL(std::string{"eleven"}, std::get<1>(p));
        // #TEST#: R699 Rename binding val4
        // #TEST#: R700 Rename binding name4
        // #TEST#: R701 Rename use of p
        const auto &[val4, name4] = p;
        // #TEST#: R702 Rename use of val4
        REQUIRE_EQUAL(11, val4);
        // #TEST#: R703 Rename use of name4
        REQUIRE_EQUAL(std::string{"eleven"}, name4);
    }

    // binding to data members
    {
        struct Foo
        {
            int val;
            std::string name;
        };
        Foo f{1, "one"};
        // #TEST#: R704 Rename binding val1
        // #TEST#: R705 Rename binding name1
        // #TEST#: R706 Rename use of f
        const auto [val1, name1] = f;
        // #TEST#: R707 Rename use of val1
        REQUIRE_EQUAL(1, val1);
        // #TEST#: R708 Rename use of name1
        REQUIRE_EQUAL(std::string{"one"}, name1);
        // #TEST#: R709 Rename binding val2
        // #TEST#: R710 Rename binding name2
        // #TEST#: R711 Rename use of f
        const auto &[val2, name2] = f;
        // #TEST#: R712 Rename use of val2
        REQUIRE_EQUAL(1, val2);
        // #TEST#: R713 Rename use of name2
        REQUIRE_EQUAL(std::string{"one"}, name2);
        // #TEST#: R714 Rename binding val3
        // #TEST#: R715 Rename binding name3
        // #TEST#: R716 Rename use of f
        auto &[val3, name3] = f;
        // #TEST#: R717 Rename use of val3
        val3 = 11;
        // #TEST#: R718 Rename use of name3
        name3 = "eleven";
        REQUIRE_EQUAL(11, f.val);
        REQUIRE_EQUAL(std::string{"eleven"}, f.name);
        // #TEST#: R719 Rename binding val4
        // #TEST#: R720 Rename binding name4
        // #TEST#: R721 Rename use of f
        auto [val4, name4] = f;
        // #TEST#: R722 Rename use of val4
        REQUIRE_EQUAL(11, val4);
        // #TEST#: R723 Rename use of name4
        REQUIRE_EQUAL(std::string{"eleven"}, name4);
    }
}

void f6()
{
    int val{6};
    // #TEST#: R724 Rename local variable i
    // #TEST#: R725 Rename use of i
    // #TEST#: R726 Rename use of val
    if (int i = val % 2; i == 0)
    {
        // #TEST#: R727 Rename use of i
        ++i;
        // #TEST#: R728 Rename use of i
        val = i;
    }
    REQUIRE_EQUAL(1, val);

    // #TEST#: R729 Rename local variable i
    // #TEST#: R730 Rename use of i
    switch (int i = val % 2; i)
    {
    case 0:
        // #TEST#: R731 Rename use of i
        ++i;
        // #TEST#: R732 Rename use of i
        val = 100 + i;
        break;
    case 1:
        // #TEST#: R733 Rename use of i
        ++i;
        // #TEST#: R734 Rename use of i
        val = 200 + i;
        break;
    default:
        val = 0;
        break;
    }
    REQUIRE_EQUAL(202, val);
}

// #TEST#: R735 Rename template parameter Args
template <typename... Args>
// #TEST#: R736 Rename function allUnaryRight
// #TEST#: R737 Rename use of Args
// #TEST#: R738 Rename parameter args
bool allUnaryRight(Args... args)
{
    // #TEST#: R739 Rename use of args
    return (args && ...);
}

// #TEST#: R740 Rename template parameter Args
template <typename... Args>
// #TEST#: R741 Rename function allUnaryLeft
// #TEST#: R742 Rename use of Args
// #TEST#: R743 Rename parameter args
bool allUnaryLeft(Args... args)
{
    // #TEST#: R744 Rename use of args
    return (... && args);
}

// #TEST#: R745 Rename template parameter Args
template <typename... Args>
// #TEST#: R746 Rename function allUnaryLeft
// #TEST#: R747 Rename use of Args
// #TEST#: R748 Rename parameter init
// #TEST#: R749 Rename parameter args
bool allBinaryRight(bool init, Args... args)
{
    // #TEST#: R750 Rename use of init
    // #TEST#: R751 Rename use of args
    return (args && ... && init);
}

// #TEST#: R752 Rename template parameter Args
template <typename... Args>
// #TEST#: R753 Rename function allUnaryLeft
// #TEST#: R754 Rename use of Args
// #TEST#: R755 Rename parameter init
// #TEST#: R756 Rename parameter args
bool allBinaryLeft(bool init, Args... args)
{
    // #TEST#: R757 Rename use of init
    // #TEST#: R758 Rename use of args
    return (init && ... && args);
}

void f7()
{
    const bool all1 = allUnaryLeft(true, true, true, true);
    REQUIRE_EQUAL(true, all1);
    const bool all2 = allUnaryRight(true, true, true, true);
    REQUIRE_EQUAL(true, all2);
    const bool all3 = allBinaryLeft(true, true, true, true);
    REQUIRE_EQUAL(true, all3);
    const bool all4 = allBinaryRight(true, true, true, true);
    REQUIRE_EQUAL(true, all4);
}

}    // namespace

void TestRenameCpp17()
{
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
}
