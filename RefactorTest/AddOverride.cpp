#include "stdafx.h"

#include <cassert>
#include <cmath>

// Add override keyword to method overriding virtual method in base class

class Interface
{
public:
    virtual ~Interface() { }

    virtual void Method() = 0;

    virtual int Getter() const = 0;

    virtual void Setter(int value) = 0;
};

class Implementation : public Interface
{
public:
    Implementation()
        : value_(0)
    { }

    virtual ~Implementation() { }

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

    // #TEST#: AO4 Add override not available
    virtual void Setter(float value)
    {
        value_ = int(std::floor(value));
    }

private:
    int value_;
};

void TestAddOverride()
{
    Implementation i;
    i.Method();
    i.Setter(i.Getter());
    assert(!i.Getter());
    i.Setter(3.14159f);
    assert(3 == i.Getter());
}
