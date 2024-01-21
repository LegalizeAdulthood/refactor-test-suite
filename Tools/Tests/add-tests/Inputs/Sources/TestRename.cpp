#include "Rename.h"

#include "Require.h"

#include <stdexcept>
#include <string>

// Renames a local variable, function, method, field, property, parameter,
// type, namespace, active CSS style, C++ global variable or C++ macro and
// updates all references to the modified element.

// #TEST#: R1 Rename this macro
#define MACRO_NO_ARGS 3.14159f

// #TEST#: R2 Rename the macro argument x_ from declaration
// #TEST#: R3 =R2 Rename the macro argument x_ from usage
// #TEST#: R4 Rename this macro
#define MACRO_ONE_ARG(x_) (2.0f * x_)

class Operations
{
public:
    // #GOINK#: Rxx Rename method
    int Operation1()
    {
        return 1;
    }
    // #GOINK#: Rxx Rename method
    int Operation2()
    {
        return 2;
    }
};

// #TEST#: R5 Rename this class, but class in Rename2.cpp shouldn't be renamed
class Rename1
{
public:
    // #TEST#: R6 =R5 Rename this class via its c'tor
    Rename1() : x()
    {
    }

    ~Rename1()
    {
    }

    typedef Rename1 MyClass;

    void Operation()
    {
    }

    int x;
};
