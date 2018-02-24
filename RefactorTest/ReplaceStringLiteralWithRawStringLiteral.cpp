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

// #TEST#: RAW10
std::string const contains_delim{"whoops)\")delim\""};

}

void TestReplaceStringLiteralWithRawStringLiteral()
{
    REQUIRE_EQUAL(std::string("goink\\frob"), backslash);
    REQUIRE_EQUAL(std::string("goink\nfrob"), newline);
    REQUIRE_EQUAL(std::string("goink\tfrob"), tab);
    REQUIRE_EQUAL(std::string("goink\'frob"), single_quote);
    REQUIRE_EQUAL(std::string("goink\"frob"), double_quote);
    REQUIRE_EQUAL(std::string("goink\?frob"), question_mark);
    REQUIRE_EQUAL(std::string("goink\\(one|two\\)\\\\\\?.*\\nfrob"), regex);
    REQUIRE_EQUAL(std::string("C:\\Program Files\\Vendor\\Application\\Application.exe"), path);
    REQUIRE_EQUAL(std::string("whoops)\""), contains_sentinel);
    REQUIRE_EQUAL(std::string("whoops)\")delim\""), contains_delim);
}
