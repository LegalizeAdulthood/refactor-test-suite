#include "stdafx.h"
#include "Require.h"
#include <stdexcept>
#include <string>

namespace
{

// #TEST#: RAW1
std::string const backslash{"goink\\frob"};

// #TEST#: RAW2
std::string const newline{"goink\nfrob"};

// #TEST#: RAW3
std::string const tab{"goink\tfrob"};

// #TEST#: RAW4
std::string const single_quote{"goink\'frob"};

// #TEST#: RAW5
std::string const double_quote{"goink\"frob"};

// #TEST#: RAW6
std::string const question_mark{"goink\?frob"};

// #TEST#: RAW7
std::string const regex{"goink\\(one|two\\)\\\\\\?.*\\nfrob"};

// #TEST#: RAW8
std::string const path{"C:\\Program Files\\Vendor\\Application\\Application.exe"};

// #TEST#: RAW9
std::string const contains_sentinel{"whoops)\""};

std::string const contains_delim{"whoops)\")delim\""};

}

void TestReplaceStringLiteralWithRawStringLiteral()
{
    using namespace std::literals::string_literals;
    REQUIRE_EQUAL("goink\\frob"s, backslash);
    REQUIRE_EQUAL("goink\nfrob"s, newline);
    REQUIRE_EQUAL("goink\tfrob"s, tab);
    REQUIRE_EQUAL("goink\'frob"s, single_quote);
    REQUIRE_EQUAL("goink\"frob"s, double_quote);
    REQUIRE_EQUAL("goink\?frob"s, question_mark);
    REQUIRE_EQUAL("goink\\(one|two\\)\\\\\\?.*\\nfrob"s, regex);
    REQUIRE_EQUAL("C:\\Program Files\\Vendor\\Application\\Application.exe"s, path);
    REQUIRE_EQUAL("whoops)\""s, contains_sentinel);
    REQUIRE_EQUAL("whoops)\")delim\""s, contains_delim);
}
