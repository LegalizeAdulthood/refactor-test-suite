#include "Require.h"

#include <memory>

static void TestStackAutoPtr()
{
    // #TEST#: RAWU1 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> i(new int(0));
    *i = 10;
    REQUIRE_EQUAL(10, *i);

    // #TEST#: RAWU2 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> cpy;
    cpy = i;
    REQUIRE_EQUAL(10, *cpy);
    REQUIRE_EQUAL(true, nullptr == i.get());
}

// #TEST#: RAWU3 Replace auto_ptr with unique_ptr
static void takeOwnership(std::auto_ptr<int> p)
{
    REQUIRE_EQUAL(10, *p);
}

static void TestAutoPtrArgument()
{
    // #TEST#: RAWU4 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> i(new int(10));
    REQUIRE_EQUAL(10, *i);
    takeOwnership(i);
    REQUIRE_EQUAL(true, nullptr == i.get());
}

void TestReplaceAutoPtrWithUniquePtr()
{
    TestStackAutoPtr();
    TestAutoPtrArgument();
}
