#include "Require.h"

#include <cmath>

// Add override keyword to method overriding virtual method in base class

class Interface
{
public:
    virtual ~Interface()
    {
    }

    virtual void Method() = 0;

    virtual int Getter() const = 0;

    virtual void Setter(int value) = 0;

    virtual void LValueRef() & = 0;

    virtual void RValueRef() && = 0;

    virtual void NoExcept() noexcept = 0;

    virtual void Volatile() volatile = 0;

    virtual void ConstVolatile() const volatile = 0;
};

class Implementation : public Interface
{
public:
    Implementation() : value_(0)
    {
    }

    // #TEST#: AO8 Add override
    virtual ~Implementation()
    {
    }

    // #TEST#: AO1 Add override
    virtual void Method()
    {
    }

    // #TEST#: AO2 Add override
    virtual int Getter() const
    {
        return value_;
    }

    // #TEST#: AO3 Add override
    virtual void Setter(int value)
    {
        value_ = value;
    }

    // #TEST#: AO4 Add override (not available)
    virtual void Setter(float value)
    {
        value_ = int(std::floor(value));
    }

    // #TEST#: AO9 Add override
    virtual void LValueRef() &
    {
    }

    // #TEST#: AO10 Add override
    virtual void RValueRef() &&
    {
    }

    // #TEST#: AO11 Add override
    virtual void NoExcept() noexcept
    {
    }

    // #TEST#: AO12 Add override
    virtual void Volatile() volatile
    {
    }

    // #TEST#: AO13 Add override
    virtual void ConstVolatile() const volatile
    {
    }

private:
    int value_;
};

class AbstractImplementation : public Interface
{
public:
    AbstractImplementation() : value_(0)
    {
    }

    virtual ~AbstractImplementation()
    {
    }

    virtual int Getter() const override
    {
        return value_;
    }

    virtual void Setter(int value) override
    {
        value_ = value;
    }

private:
    int value_;
};

class DerivedImplementation : public AbstractImplementation
{
public:
    DerivedImplementation() : AbstractImplementation()
    {
    }

    virtual ~DerivedImplementation()
    {
    }

    // #TEST#: AO5 Add override
    virtual void Method()
    {
    }

    // #TEST#: AO6 Add override
    virtual void LValueRef() &
    {
    }

    // #TEST#: AO7 Add override
    virtual void RValueRef() &&
    {
    }

    // #TEST#: AO14 Add override
    virtual void NoExcept() noexcept
    {
    }

    // #TEST#: AO15 Add override
    virtual void Volatile() volatile
    {
    }

    // #TEST#: AO16 Add override
    virtual void ConstVolatile() const volatile
    {
    }
};

void TestAddOverride()
{
    Implementation i;
    i.Method();
    i.Setter(i.Getter());
    REQUIRE_EQUAL(true, !i.Getter());
    i.Setter(3.14159f);
    REQUIRE_EQUAL(3, i.Getter());

    DerivedImplementation d;
    d.Method();
    d.Setter(i.Getter());
    REQUIRE_EQUAL(3, d.Getter());
}
