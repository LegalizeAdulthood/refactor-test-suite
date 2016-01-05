#pragma once

#include <stdexcept>
#include <sstream>

template <typename T>
void require_equal(T expected, T actual)
{
    if (expected != actual)
    {
        std::ostringstream message;
        message << "expected " << expected << ", got " << actual;
        throw std::runtime_error(message.str().c_str());
    }
}

template <typename T>
void require_equal(char const *file, unsigned line, T expected, T actual)
{
    if (expected != actual)
    {
        std::ostringstream message;
        message << file << '(' << line << "): error: expected " << expected << ", got " << actual;
        throw std::runtime_error(message.str().c_str());
    }
}

#define REQUIRE_EQUAL(expected_, actual_) \
    require_equal(__FILE__, __LINE__, expected_, actual_)
