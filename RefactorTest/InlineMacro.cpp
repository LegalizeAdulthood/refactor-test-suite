#include <cmath>
#include <string>
#include "Require.h"

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

void TestInlineMacro()
{
    // #TEST#: IM2 Inline macro MACRO1
    int x = MACRO1;
    REQUIRE_EQUAL(MACRO1, x);

    // #TEST#: IM3 Inline macro MACRO2
    std::string s = MACRO2;
    REQUIRE_EQUAL(std::string{MACRO2}, s);

    // #TEST#: IM4 Inline macro MACRO3
    float f = MACRO3;
    REQUIRE_EQUAL(MACRO3, f);

    // #TEST#: IM5 Inline macro MACRO4
    x = MACRO4(2);
    REQUIRE_EQUAL(MACRO4(2), x);

    // #TEST#: IM6 Inline macro MACRO5
    x = 2;
    MACRO5(x);
    REQUIRE_EQUAL(6, x);
}
