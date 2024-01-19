#include "RenameCpp17.h"
#include "Require.h"

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

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

// #TEST#: R653 Rename A
// #TEST#: R654 Rename B
// #TEST#: R655 Rename C
namespace RenameCpp17::A::B::C
{

// #TEST#: R656 Rename x
int x{10};

int y{20};
int z{30};

}    // namespace RenameCpp17::A::B::C

namespace
{

class Foo
{
public:
    int f()
    {
        // #TEST#: R657 Rename local variable fn
        // #TEST#: R658 Rename parameter val
        // #TEST#: R659 Rename use of val
        // #TEST#: R660 Rename use of m_i
        auto fn = [*this](int &val) { val = 3 + m_i; };
        // #TEST#: R661 Rename use of m_i
        m_i = 1;
        // #TEST#: R662 Rename use of fn
        // #TEST#: R663 Rename use of m_i
        fn(m_i);
        // #TEST#: R664 Rename use of m_i
        return m_i;
    }

    int i() const
    {
        return m_i;
    }

private:
    // #TEST#: R665 Rename member m_i
    int m_i{10};
};

// #TEST#: R666 Rename template parameter T
// #TEST#: R667 Rename template parameter N
template <typename T, size_t N>
// #TEST#: R668 Rename function f
int f()
{
    // #TEST#: R669 Rename use of T
    // #TEST#: R670 Rename use of N
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
    REQUIRE_EQUAL(10, f.i());
    REQUIRE_EQUAL(13, f.f());
}

void f2()
{
    // #TEST#: R671 Rename use of f
    REQUIRE_EQUAL(10, (f<std::uint32_t, 4>()));
}

void f3()
{
    // #TEST#: R672 Rename local variable initial
    constexpr int initial{10};
    // #TEST#: R673 Rename use of initial
    static_assert(10 == initial);
    // #TEST#: R674 Rename local variable fn
    // #TEST#: R675 Rename initial in capture list
    // #TEST#: R676 Rename parameter val
    // #TEST#: R677 Rename use of initial
    // #TEST#: R678 Rename use of val
    constexpr auto fn = [initial](int val) constexpr
    {
        return initial + val;
    };
    // #TEST#: R679 Rename use of fn
    static_assert(10 == fn(0));
    int value;
    // #TEST#: R680 Rename use of fn
    if constexpr (15 == fn(5))
    {
        value = 10;
    }
    else
    {
        value = 15;
    }
    // #TEST#: R681 Rename use of fn
    REQUIRE_EQUAL(15, fn(5));
    REQUIRE_EQUAL(10, value);
}

void f4()
{
    // #TEST#: R682 Rename use of g_counter
    ++RenameCpp17::g_counter;
    // #TEST#: R683 Rename use of g_counter
    REQUIRE_EQUAL(1, RenameCpp17::g_counter);
}

void f5()
{
    // binding to arrays
    {
        // #TEST#: R684 Rename variable vals
        int vals[]{1, 2};
        // #TEST#: R685 Rename binding cx
        // #TEST#: R686 Rename binding cy
        // #TEST#: R687 Rename use of vals
        const auto [cx, cy] = vals;
        // #TEST#: R688 Rename use of cx
        REQUIRE_EQUAL(1, cx);
        // #TEST#: R689 Rename use of cy
        REQUIRE_EQUAL(2, cy);
        // #TEST#: R690 Rename binding x
        // #TEST#: R691 Rename binding y
        // #TEST#: R692 Rename use of vals
        auto [x, y] = vals;
        // #TEST#: R693 Rename use of x
        REQUIRE_EQUAL(1, x);
        // #TEST#: R694 Rename use of y
        REQUIRE_EQUAL(2, y);
        // #TEST#: R695 Rename binding vx
        // #TEST#: R696 Rename binding vy
        // #TEST#: R697 Rename use of vals
        auto &[vx, vy] = vals;
        // #TEST#: R698 Rename use of vx
        vx = 4;
        // #TEST#: R699 Rename use of vy
        vy = 5;
        REQUIRE_EQUAL(4, vals[0]);
        REQUIRE_EQUAL(5, vals[1]);
        // #TEST#: R700 Rename binding crx
        // #TEST#: R701 Rename binding cry
        // #TEST#: R702 Rename use of vals
        const auto &[crx, cry] = vals;
        // #TEST#: R703 Rename use of crx
        REQUIRE_EQUAL(4, crx);
        // #TEST#: R704 Rename use of cry
        REQUIRE_EQUAL(5, cry);
    }

    // binding to tuple-like type
    {
        using pair = std::tuple<int, std::string>;
        pair p{1, "one"};
        // #TEST#: R705 Rename binding val
        // #TEST#: R706 Rename binding name
        // #TEST#: R707 Rename use of p
        const auto [val, name] = p;
        // #TEST#: R708 Rename use of val
        REQUIRE_EQUAL(1, val);
        // #TEST#: R709 Rename use of name
        REQUIRE_EQUAL(std::string{"one"}, name);
        // #TEST#: R710 Rename binding val2
        // #TEST#: R711 Rename binding name2
        // #TEST#: R712 Rename use of p
        auto [val2, name2] = p;
        // #TEST#: R713 Rename use of val2
        REQUIRE_EQUAL(1, val2);
        // #TEST#: R714 Rename use of name2
        REQUIRE_EQUAL(std::string{"one"}, name2);
        // #TEST#: R715 Rename binding val3
        // #TEST#: R716 Rename binding name3
        // #TEST#: R717 Rename use of p
        auto &[val3, name3] = p;
        // #TEST#: R718 Rename use of val3
        val3 = 11;
        // #TEST#: R719 Rename use of name3
        name3 = "eleven";
        REQUIRE_EQUAL(11, std::get<0>(p));
        REQUIRE_EQUAL(std::string{"eleven"}, std::get<1>(p));
        // #TEST#: R720 Rename binding val4
        // #TEST#: R721 Rename binding name4
        // #TEST#: R722 Rename use of p
        const auto &[val4, name4] = p;
        // #TEST#: R723 Rename use of val4
        REQUIRE_EQUAL(11, val4);
        // #TEST#: R724 Rename use of name4
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
        // #TEST#: R725 Rename binding val1
        // #TEST#: R726 Rename binding name1
        // #TEST#: R727 Rename use of f
        const auto [val1, name1] = f;
        // #TEST#: R728 Rename use of val1
        REQUIRE_EQUAL(1, val1);
        // #TEST#: R729 Rename use of name1
        REQUIRE_EQUAL(std::string{"one"}, name1);
        // #TEST#: R730 Rename binding val2
        // #TEST#: R731 Rename binding name2
        // #TEST#: R732 Rename use of f
        const auto &[val2, name2] = f;
        // #TEST#: R733 Rename use of val2
        REQUIRE_EQUAL(1, val2);
        // #TEST#: R734 Rename use of name2
        REQUIRE_EQUAL(std::string{"one"}, name2);
        // #TEST#: R735 Rename binding val3
        // #TEST#: R736 Rename binding name3
        // #TEST#: R737 Rename use of f
        auto &[val3, name3] = f;
        // #TEST#: R738 Rename use of val3
        val3 = 11;
        // #TEST#: R739 Rename use of name3
        name3 = "eleven";
        REQUIRE_EQUAL(11, f.val);
        REQUIRE_EQUAL(std::string{"eleven"}, f.name);
        // #TEST#: R740 Rename binding val4
        // #TEST#: R741 Rename binding name4
        // #TEST#: R742 Rename use of f
        auto [val4, name4] = f;
        // #TEST#: R743 Rename use of val4
        REQUIRE_EQUAL(11, val4);
        // #TEST#: R744 Rename use of name4
        REQUIRE_EQUAL(std::string{"eleven"}, name4);
    }
}

void f6()
{
    int val{6};
    // #TEST#: R745 Rename local variable i
    // #TEST#: R746 Rename use of i
    // #TEST#: R747 Rename use of val
    if (int i = val % 2; i == 0)
    {
        // #TEST#: R748 Rename use of i
        ++i;
        // #TEST#: R749 Rename use of i
        val = i;
    }
    REQUIRE_EQUAL(1, val);

    // #TEST#: R750 Rename local variable i
    // #TEST#: R751 Rename use of i
    switch (int i = val % 2; i)
    {
    case 0:
        // #TEST#: R752 Rename use of i
        ++i;
        // #TEST#: R753 Rename use of i
        val = 100 + i;
        break;
    case 1:
        // #TEST#: R754 Rename use of i
        ++i;
        // #TEST#: R755 Rename use of i
        val = 200 + i;
        break;
    default:
        val = 0;
        break;
    }
    REQUIRE_EQUAL(202, val);
}

// #TEST#: R756 Rename template parameter Args
template <typename... Args>
// #TEST#: R757 Rename function allUnaryRight
// #TEST#: R758 Rename use of Args
// #TEST#: R759 Rename parameter args
bool allUnaryRight(Args... args)
{
    // #TEST#: R760 Rename use of args
    return (args && ...);
}

// #TEST#: R761 Rename template parameter Args
template <typename... Args>
// #TEST#: R762 Rename function allUnaryLeft
// #TEST#: R763 Rename use of Args
// #TEST#: R764 Rename parameter args
bool allUnaryLeft(Args... args)
{
    // #TEST#: R765 Rename use of args
    return (... && args);
}

// #TEST#: R766 Rename template parameter Args
template <typename... Args>
// #TEST#: R767 Rename function allBinaryRight
// #TEST#: R768 Rename parameter init
// #TEST#: R769 Rename use of Args
// #TEST#: R770 Rename parameter args
bool allBinaryRight(bool init, Args... args)
{
    // #TEST#: R771 Rename use of args
    // #TEST#: R772 Rename use of init
    return (args && ... && init);
}

// #TEST#: R773 Rename template parameter Args
template <typename... Args>
// #TEST#: R774 Rename function allBinaryLeft
// #TEST#: R775 Rename parameter init
// #TEST#: R776 Rename use of Args
// #TEST#: R777 Rename parameter args
bool allBinaryLeft(bool init, Args... args)
{
    // #TEST#: R778 Rename use of init
    // #TEST#: R779 Rename use of args
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

template <typename Value, typename String>
struct ValueName
{
    ValueName(Value value, String name) : value(value), name(name)
    {
    }
    Value value;
    String name;
};

void f8()
{
    float f1{1.0f};
    int i1{10};
    // declarations
    {
        // #TEST#: R780 Rename local variable p
        // #TEST#: R781 Rename use of f1
        // #TEST#: R782 Rename use of i1
        std::pair p{f1, i1};
        // #TEST#: R783 Rename use of p
        REQUIRE_EQUAL(1.0f, p.first);
        // #TEST#: R784 Rename use of p
        REQUIRE_EQUAL(10, p.second);
        // #TEST#: R785 Rename local variable t
        // #TEST#: R786 Rename use of f1
        // #TEST#: R787 Rename use of i1
        std::tuple t{f1, i1};
        // #TEST#: R788 Rename use of t
        REQUIRE_EQUAL(1.0f, std::get<0>(t));
        // #TEST#: R789 Rename use of t
        REQUIRE_EQUAL(10, std::get<1>(t));
    }
    // new expressions
    {
        // #TEST#: R790 Rename local variable p1
        // #TEST#: R791 Rename use of f1
        // #TEST#: R792 Rename use of i1
        const auto *p1 = new std::pair{f1, i1};
        // #TEST#: R793 Rename use of p1
        REQUIRE_EQUAL(1.0f, p1->first);
        // #TEST#: R794 Rename use of p1
        REQUIRE_EQUAL(10, p1->second);
        // #TEST#: R795 Rename use of p1
        delete p1;
        // #TEST#: R796 Rename local variable name
        const char *name{"one"};
        // #TEST#: R797 Rename local variable p2
        // #TEST#: R798 Rename use of f1
        // #TEST#: R799 Rename use of name
        const auto *p2 = new ValueName{f1, std::string_view{name}};
        // #TEST#: R800 Rename use of p2
        REQUIRE_EQUAL(1.0f, p2->value);
        // #TEST#: R801 Rename use of name
        // #TEST#: R802 Rename use of p2
        REQUIRE_EQUAL(std::string_view{name}, p2->name);
        // #TEST#: R803 Rename use of p2
        delete p2;
    }
    // function-style cast expressions
    {
        int src[]{1, 2, 3};
        // #TEST#: R804 Rename local variable dest
        std::vector<int> dest;
        // #TEST#: R805 Rename use of dest
        std::copy(std::begin(src), std::end(src), std::back_insert_iterator(dest));
        REQUIRE_EQUAL(true, std::equal(std::begin(src), std::end(src), dest.begin()));
    }
}

// #TEST#: R806 Rename template parameter T
template <typename T>
// #TEST#: R807 Rename struct Container
struct Container
{
    // #TEST#: R808 Rename use of Container
    // #TEST#: R809 Rename use of T
    Container(T t) : m_how(1)
    {
    }

    // #TEST#: R810 Rename template parameter Iter
    template <typename Iter>
    // #TEST#: R811 Rename use of Container
    // #TEST#: R812 Rename first use of Iter
    // #TEST#: R813 Rename second use of Iter
    Container(Iter begin, Iter end) : m_how(2)
    {
    }

    int m_how{};
};

// #TEST#: R814 Rename template parameter Iter
template <typename Iter>
// #TEST#: R815 Rename first use of Container
// #TEST#: R816 Rename first use of Iter
// #TEST#: R817 Rename second use of Iter
// #TEST#: R818 Rename second use of Container
// #TEST#: R819 Rename third use of Iter
Container(Iter begin, Iter end)->Container<typename std::iterator_traits<Iter>::value_type>;

void f9()
{
    // #TEST#: R820 Rename use of Container
    // #TEST#: R821 Rename local variable c1
    const Container c1{7};
    // #TEST#: R822 Rename use of c1
    REQUIRE_EQUAL(1, c1.m_how);
    std::vector vals{1.0f, 2.0f, 3.0f};
    // #TEST#: R823 Rename use of Container
    // #TEST#: R824 Rename local variable c2
    // #TEST#: R825 Rename first use of vals
    // #TEST#: R826 Rename second use of vals
    const Container c2{vals.begin(), vals.end()};
    // #TEST#: R827 Rename use of c2
    REQUIRE_EQUAL(2, c2.m_how);
}

void f10()
{
    // #TEST#: R828 Rename A
    // #TEST#: R829 Rename B
    // #TEST#: R830 Rename C
    // #TEST#: R831 Rename x
    REQUIRE_EQUAL(10, RenameCpp17::A::B::C::x);

    {
        // #TEST#: R832 Rename A
        // #TEST#: R833 Rename B
        // #TEST#: R834 Rename C
        using namespace RenameCpp17::A::B::C;
        // #TEST#: R835 Rename x
        REQUIRE_EQUAL(10, x);
    }
}

void f11()
{
    {
        // #TEST#: R836 Rename A
        // #TEST#: R837 Rename B
        // #TEST#: R838 Rename C
        // #TEST#: R839 Rename y
        // #TEST#: R840 Rename z
        using RenameCpp17::A::B::C::y, RenameCpp17::A::B::C::z;
        // #TEST#: R841 Rename use of y
        // #TEST#: R842 Rename use of z
        REQUIRE_EQUAL(50, y + z);
    }
    {
        using namespace RenameCpp17;
        // #TEST#: R843 Rename A
        // #TEST#: R844 Rename B
        // #TEST#: R845 Rename C
        // #TEST#: R846 Rename y
        // #TEST#: R847 Rename z
        using A::B::C::y, A::B::C::z;
        // #TEST#: R848 Rename use of y
        // #TEST#: R849 Rename use of z
        REQUIRE_EQUAL(50, y + z);
    }
    {
        // #TEST#: R850 Rename A
        using namespace RenameCpp17::A;
        // #TEST#: R851 Rename B
        // #TEST#: R852 Rename C
        // #TEST#: R853 Rename y
        // #TEST#: R854 Rename z
        using B::C::y, B::C::z;
        // #TEST#: R855 Rename use of y
        // #TEST#: R856 Rename use of z
        REQUIRE_EQUAL(50, y + z);
    }
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
    f8();
    f9();
    f10();
    f11();
}
