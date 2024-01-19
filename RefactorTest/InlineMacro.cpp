#include "Require.h"

#include <cmath>
#include <sstream>
#include <string>

// clang-format off
#define MACRO1 -20
#define MACRO2 "This is a test." \
    "  This is more of a test!"
#define MACRO3 -30.0f/std::pow(2.0f, 2.0f)
// #TEST#: IM1 Inline macro MACRO1
#define MACRO4(x_) (MACRO1*x_)
#define MACRO5(x_)      \
    do                  \
    {                   \
        if (x_ > 5)     \
        {               \
            x_ *= 2;    \
        }               \
        else            \
        {               \
            x_ += 4;    \
        }               \
    } while (0)
// clang-format on

namespace
{
template <typename T>
void f1_aux(std::ostream &stream, T value)
{
    stream << value << '\n';
}

template <typename T, typename... Types>
void f1_aux(std::ostream &stream, T head, Types... tail)
{
    f1_aux(stream, head);
    f1_aux(stream, tail...);
}

#define F1_AUX(stream, ...) f1_aux(stream, __VA_ARGS__)

void f1()
{
    std::ostringstream result;
    // #TEST#: IM2 Inline macro F1_AUX
    F1_AUX(result, 10, 20.5, "hello world!");
    require_equal(std::string{"10\n20.5\nhello world!\n"}, result.str());
}

#undef F1_AUX

}    // namespace

void TestInlineMacro()
{
    // #TEST#: IM3 Inline macro MACRO1
    int x = MACRO1;
    REQUIRE_EQUAL(MACRO1, x);

    // #TEST#: IM4 Inline macro MACRO2
    std::string s = MACRO2;
    REQUIRE_EQUAL(std::string{MACRO2}, s);

    // #TEST#: IM5 Inline macro MACRO3
    float f = MACRO3;
    REQUIRE_EQUAL(MACRO3, f);

    // #TEST#: IM6 Inline macro MACRO4
    x = MACRO4(2);
    REQUIRE_EQUAL(MACRO4(2), x);

    // #TEST#: IM7 Inline macro MACRO5
    x = 2;
    MACRO5(x);
    REQUIRE_EQUAL(6, x);

    f1();
}
