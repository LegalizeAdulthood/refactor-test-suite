#pragma once

#include <sstream>
#include <stdexcept>

template <typename T, typename U>
void require_equal(T expected, U actual)
{
    if (expected != actual)
    {
        std::ostringstream message;
        message << "expected " << expected << ", got " << actual;
        throw std::runtime_error(message.str().c_str());
    }
}

template <typename T, typename U>
void require_equal(char const *file, unsigned line, T expected, U actual)
{
    if (expected != actual)
    {
        std::ostringstream message;
        message << file << '(' << line << "): error: expected " << expected << ", got " << actual;
        message << file << '(' << line << "): error: expected != got\n";
        throw std::runtime_error(message.str().c_str());
    }
}

#define REQUIRE_EQUAL(expected_, actual_) require_equal(__FILE__, __LINE__, expected_, actual_)
