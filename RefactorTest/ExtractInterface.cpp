#include "stdafx.h"

// Extracts an interface of public members from a class.

namespace ExtractInterfaceNamespace
{
    // #TEST#: EI1 Extract interface on this class
    class ExtractInterfaceBase
    {
    public:
        virtual ~ExtractInterfaceBase()
        {
        }
        virtual void Operation3() = 0;
    };

    // #TEST#: EI2 Extract interface on this class
    class ExtractInterface : public ExtractInterfaceBase
    {
    public:
        ExtractInterface()
        {}
        virtual ~ExtractInterface()
        {}

        int GetX() const { return _x; }
        void SetX(int x) { _x = x; }
        void Operation();
        void ConstOperation() const;
        void Operation2(ExtractInterface *foo);
        virtual void Operation3();

    private:
        int _x;
    };

    void ExtractInterface::Operation()
    {
    }

    void ExtractInterface::ConstOperation() const
    {
    }

    void ExtractInterface::Operation2(ExtractInterface *foo)
    {
    }

    void ExtractInterface::Operation3()
    {
    }
}

using namespace ExtractInterfaceNamespace;

void TestExtractInterface()
{
    ExtractInterface *foo = new ExtractInterface();
    delete foo;
}
