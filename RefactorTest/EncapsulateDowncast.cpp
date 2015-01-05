#include "stdafx.h"

// Changes the return type of a method to the type that all callers downcast to,
// removing typecasting at calling sites.
//
// When the caret is on a method declaration statement,
// provided that the method's return type is the ancestor of the method's return value.
// Note that the caret should be on the method name or on the return type name. 

namespace EncapsulateDowncastNamespace
{
    class Base
    {
    public:
        virtual ~Base() {}
        virtual Base *Operation() = 0;
    };

    class Derived1 : public virtual Base
    {
    public:
        virtual ~Derived1() {}
        // #TEST#: ED3 Encapsulate Downcast
        virtual Base *Operation()
        {
            return this;
        }
        // #TEST#: ED1 Encapsulate Downcast
        virtual Base *Operation2()
        {
            return this;
        }
        void Operation3()
        {
        }
    };

    class Derived2 : public virtual Derived1
    {
    public:
        virtual ~Derived2() {}
        virtual Base *Operation()
        {
            return this;
        }
        // #TEST#: ED2 Encapsulate Downcast
        virtual Base *Operation2()
        {
            return this;
        }
    };
}

using namespace EncapsulateDowncastNamespace;

void TestEncapsulateDowncast()
{
    Derived1 d1;
    Derived2 d2;

    dynamic_cast<Derived1 *>(d1.Operation2())->Operation3();
    dynamic_cast<Derived1 *>(d2.Operation2())->Operation3();
}
