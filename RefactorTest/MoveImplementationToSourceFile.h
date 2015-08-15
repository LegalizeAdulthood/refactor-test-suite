#pragma once
#include "Require.h"

namespace MoveImplementationToSourceFile
{

// #TEST#: MISF1 Move implementation to source file
inline int f()
{
    return 1;
}

struct Base
{
    // #TEST#: MISF2 Move implementation to source file
    Base() : i{10}
    {}

    // #TEST#: MISF3 Move implementation to source file
    ~Base()
    {}

    // #TEST#: MISF4 Move implementation to source file
    int f()
    {
        return 1;
    }

    // #TEST#: MISF5 Move implementation to source file
    void g()
    {
        REQUIRE_EQUAL(1, f());
    }

private:
    int i;
};

union Variant
{
    int i;
    float f;
    double d;

    // #TEST#: MISF6 Move implementation to source file
    int getInt() const
    {
        return i;
    }
};

class VirtualBase
{
public:
    // #TEST#: MISF7 Move implementation to source file
    virtual ~VirtualBase() {}

    // #TEST#: MISF8 Move implementation to source file (should not be available)
    virtual void f() = 0;

    // #TEST#: MISF9 Move implementation to source file
    virtual void g()
    {
    }

    // #TEST#: MISF10 Move implementation to source file (should not be available)
    virtual int h() const = 0;

    // #TEST#: MISF11 Move implementation to source file (should not be available)
    virtual int (VirtualBase::*GetOperation() const)() const = 0;
};

class Derived : public VirtualBase
{
public:
    // #TEST#: MISF12 Move implementation to source file
    Derived()
    {}

    // #TEST#: MISF13 Move implementation to source file
    virtual ~Derived()
    {}

    // #TEST#: MISF14 Move implementation to source file
    void f() override
    {}

    void g() override
    {}

    // #TEST#: MISF15 Move implementation to source file
    int h() const override
    {
        return 1;
    }

    // #TEST#: MISF16 Move implementation to source file
    int (VirtualBase::*GetOperation() const)() const override
    {
        return &VirtualBase::h;
    }
};

namespace Nested
{

class VirtualBase
{
public:
    // #TEST#: MISF17 Move implementation to source file
    virtual ~VirtualBase() {}

    // #TEST#: MISF18 Move implementation to source file (should not be available)
    virtual void f() = 0;

    // #TEST#: MISF19 Move implementation to source file
    virtual void g()
    {
    }

    // #TEST#: MISF20 Move implementation to source file (should not be available)
    virtual int h() const = 0;

    // #TEST#: MISF21 Move implementation to source file (should not be available)
    virtual int (VirtualBase::*GetOperation() const)() const = 0;
};

class Derived : public VirtualBase
{
public:
    // #TEST#: MISF22 Move implementation to source file
    Derived()
    {}

    // #TEST#: MISF23 Move implementation to source file
    virtual ~Derived()
    {}

    // #TEST#: MISF24 Move implementation to source file
    void f() override
    {}

    void g() override
    {}

    // #TEST#: MISF25 Move implementation to source file
    int h() const override
    {
        return 1;
    }

    // #TEST#: MISF26 Move implementation to source file
    int (VirtualBase::*GetOperation() const)() const override
    {
        return &VirtualBase::h;
    }
};

}

}

extern void TestMoveImplementationToSourceFile();
