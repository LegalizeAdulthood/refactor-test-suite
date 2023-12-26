#include "Require.h"

#include <cstddef>

// Replace uses of NULL or 0 with nullptr

class Initializer
{
public:
    Initializer(char *p_ = NULL,             // #TEST#: RZNP1 Replace NULL with nullptr
                char *q_ = 0,                // #TEST#: RZNP2 Replace 0 with nullptr
                char const *f_ = NULL,       // #TEST#: RZNP3 Replace NULL with nullptr
                char const *g_ = 0,          // #TEST#: RZNP4 Replace 0 with nullptr
                char const *const h_ = NULL, // #TEST#: RZNP5 Replace NULL with nullptr
                char const *const i_ = 0)    // #TEST#: RZNP6 Replace 0 with nullptr
        : p(p_),
        q(q_),
        d(NULL), // #TEST#: RZNP7 Replace NULL with nullptr
        e(0),    // #TEST#: RZNP8 Replace 0 with nullptr
        f(NULL), // #TEST#: RZNP9 Replace NULL with nullptr
        g(0),    // #TEST#: RZNP10 Replace 0 with nullptr
        h(NULL), // #TEST#: RZNP11 Replace NULL with nullptr
        i(0)     // #TEST#: RZNP12 Replace 0 with nullptr
    {
        REQUIRE_EQUAL(true, !p_);
        REQUIRE_EQUAL(true, !q_);
        REQUIRE_EQUAL(true, !f_);
        REQUIRE_EQUAL(true, !g_);
        REQUIRE_EQUAL(true, !h_);
        REQUIRE_EQUAL(true, !i_);
        REQUIRE_EQUAL(true, !p);
        REQUIRE_EQUAL(true, !q);
        REQUIRE_EQUAL(true, !d);
        REQUIRE_EQUAL(true, !e);
        REQUIRE_EQUAL(true, !f);
        REQUIRE_EQUAL(true, !g);
        REQUIRE_EQUAL(true, !h);
        REQUIRE_EQUAL(true, !i);
    }

    void check()
    {
        REQUIRE_EQUAL(true, !p);
        REQUIRE_EQUAL(true, !q);
        REQUIRE_EQUAL(true, !d);
        REQUIRE_EQUAL(true, !e);
        REQUIRE_EQUAL(true, !f);
        REQUIRE_EQUAL(true, !g);
        REQUIRE_EQUAL(true, !h);
        REQUIRE_EQUAL(true, !i);
    }

private:
    char *p;
    char *q;
    char *d;
    char *e;
    char const *f;
    char const *g;
    char const *const h;
    char const *const i;
};

static void TestClass()
{
    Initializer i;
    i.check();
}

static void TestDefaultArguments(char *p = NULL,             // #TEST#: RZNP13 Replace NULL with nullptr
                                 char *q = 0,                // #TEST#: RZNP14 Replace 0 with nullptr
                                 char const *f = NULL,       // #TEST#: RZNP15 Replace NULL with nullptr
                                 char const *g = 0,          // #TEST#: RZNP16 Replace 0 with nullptr
                                 char const *const h = NULL, // #TEST#: RZNP17 Replace NULL with nullptr
                                 char const *const i = 0)    // #TEST#: RZNP18 Replace 0 with nullptr
{
    REQUIRE_EQUAL(true, !p);
    REQUIRE_EQUAL(true, !q);
    REQUIRE_EQUAL(true, !f);
    REQUIRE_EQUAL(true, !g);
    REQUIRE_EQUAL(true, !h);
    REQUIRE_EQUAL(true, !i);
}

static void TestAssignment()
{
    char *a = NULL;             // #TEST#: RZNP19 Replace NULL with nullptr
    char *b = 0;                // #TEST#: RZNP20 Replace 0 with nullptr
    char c = 0;                 // #TEST#: RZNP21 Should not be available
    char *d = nullptr;          // #TEST#: RZNP22 Should not be available
    char const *f = NULL;       // #TEST#: RZNP23 Replace NULL with nullptr
    char const *g = 0;          // #TEST#: RZNP24 Replace 0 with nullptr
    char const *const h = NULL; // #TEST#: RZNP25 Replace NULL with nullptr
    char const *const i = 0;    // #TEST#: RZNP26 Replace 0 with nullptr

    REQUIRE_EQUAL(true, !a);
    REQUIRE_EQUAL(true, !b);
    REQUIRE_EQUAL(true, !d);
    REQUIRE_EQUAL(true, !f);
    REQUIRE_EQUAL(true, !g);
    REQUIRE_EQUAL(true, !h);
    REQUIRE_EQUAL(true, !i);
}

static void TestMemberPointers()
{
    class Foo
    {
    public:
        int Method0() { return 0; }
    };
    // #TEST#: RZNP27 Replace NULL with nullptr
    int (Foo::*member)() = NULL;
    REQUIRE_EQUAL(true, !member);

    // #TEST#: RZNP28 Replace 0 with nullptr
    member = 0;
    REQUIRE_EQUAL(true, !member);
}

void TestReplaceNullZeroWithNullPtr()
{
    TestClass();
    TestAssignment();
    TestDefaultArguments();
    TestMemberPointers();
}
