#include "stdafx.h"
#include <stdexcept>
#include <string>

namespace
{

// #TEST#: RAW1
char const *const backslash = "goink\\frob";

// #TEST#: RAW2
char const *const newline = "goink\nfrob";

// #TEST#: RAW3
char const *const tab = "goink\tfrob";

// #TEST#: RAW4
char const *const single_quote = "goink\'frob";

// #TEST#: RAW5
char const *const double_quote = "goink\"frob";

// #TEST#: RAW6
char const *const question_mark = "goink\?frob";

// #TEST#: RAW7
char const *const regex = "goink\\(one|two\\)\\\\\\?.*\\nfrob";

// #TEST#: RAW8
char const *const path = "C:\\Program Files\\Vendor\\Application\\Application.exe";

void check(std::string const &lhs, std::string const &rhs)
{
    if (lhs != rhs)
    {
        throw std::runtime_error("String '" + lhs + "' is not the same as '" + rhs + "'");
    }
}

}

void TestReplaceStringLiteralWithRawStringLiteral()
{
    check("goink\\frob", backslash);
    check("goink\nfrob", newline);
    check("goink\tfrob", tab);
    check("goink\'frob", single_quote);
    check("goink\"frob", double_quote);
    check("goink\?frob", question_mark);
    check("goink\\(one|two\\)\\\\\\?.*\\nfrob", regex);
    check("C:\\Program Files\\Vendor\\Application\\Application.exe", path);
}
