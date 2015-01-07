#if !defined(REQUIRE_H)
#define REQUIRE_H

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

#endif
