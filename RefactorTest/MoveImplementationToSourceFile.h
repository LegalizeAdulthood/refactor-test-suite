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
    Base() : i{10}
    {}

    ~Base()
    {}

    // #TEST#: MISF2 Move implementation to source file
    int f()
    {
        return 1;
    }

    // #TEST#: MISF3 Move implementation to source file
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

    int getInt() const
    {
        return i;
    }
};

class VirtualBase
{
public:
    virtual ~VirtualBase() {}

    virtual void f() = 0;

    virtual void g()
    {
    }

    virtual int h() const = 0;

    virtual int (VirtualBase::*GetOperation() const)() const = 0;
};

class Derived : public VirtualBase
{
public:
    Derived()
    {}

    virtual ~Derived()
    {}

    void f() override
    {}

    void g() override
    {}

    int h() const override
    {
        return 1;
    }

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
    virtual ~VirtualBase() {}

    virtual void f() = 0;

    virtual void g()
    {
    }

    virtual int h() const = 0;

    virtual int (VirtualBase::*GetOperation() const)() const = 0;
};

class Derived : public VirtualBase
{
public:
    Derived()
    {}

    virtual ~Derived()
    {}

    void f() override
    {}

    void g() override
    {}

    int h() const override
    {
        return 1;
    }

    int (VirtualBase::*GetOperation() const)() const override
    {
        return &VirtualBase::h;
    }
};

}

}

extern void TestMoveImplementationToSourceFile();
