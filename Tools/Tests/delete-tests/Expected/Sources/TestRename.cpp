#include "Rename.h"

#include "Require.h"

#include <stdexcept>
#include <string>

// Renames a local variable, function, method, field, property, parameter,
// type, namespace, active CSS style, C++ global variable or C++ macro and
// updates all references to the modified element.


#define MACRO_NO_ARGS 3.14159f

class Operations
{
public:

    int Operation1()
    {
        return 1;
    }
    // #TEST#: R3 Rename method
    int Operation2()
    {
        return 2;
    }
};


// #TEST#: R5 Rename the macro argument x_ from usage
// #TEST#: R6 Rename this macro
#define MACRO_ONE_ARG(x_) (2.0f * x_)

// #TEST#: R7 Rename this class, but class in Rename2.cpp shouldn't be renamed
class Rename1
{
public:
    // #TEST#: R8 =R7 Rename this class via its c'tor
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
