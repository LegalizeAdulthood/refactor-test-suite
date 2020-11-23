#include <cassert>
#include <memory>

static void TestStackAutoPtr()
{
    // #TEST#: RAWU1 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> i(new int(0));
    *i = 10;
    assert(*i == 10);

    // #TEST#: RAWU2 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> cpy;
    cpy = i;
}

// #TEST#: RAWU3 Replace auto_ptr with unique_ptr
static void takeOwnership(std::auto_ptr<int> p) { assert(*p == 10); }

static void TestAutoPtrArgument()
{
    // #TEST#: RAWU4 Replace auto_ptr with unique_ptr
    std::auto_ptr<int> i(new int(10));
    assert(*i == 10);
    takeOwnership(i);
    assert(!i.get());
}

void TestReplaceAutoPtrWithUniquePtr()
{
    TestStackAutoPtr();
    TestAutoPtrArgument();
}
