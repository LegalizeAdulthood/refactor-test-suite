#pragma once

#include <sstream>
#include <string>

namespace ChangeSignatureNamespace
{
// #TEST#: CS1 Rename first parameter to operand1
// #TEST#: CS2 Rename second parameter to operand2
// #TEST#: CS3 Rename function to Primitive
// #TEST#: CS4 Add const qualifier to first parameter
// #TEST#: CS5 Add const qualifier to second parameter
inline int Function1(int a, int b)
{
    return a + b;
}

// #TEST#: CS6 Change type of prefix to 'std::string const &'
inline std::string Function1(int a, std::string prefix)
{
    std::ostringstream str;
    str << prefix << a;
    return str.str();
}

// #TEST#: CS7 Rename first parameter to operand1
// #TEST#: CS8 Rename second parameter to operand2
// #TEST#: CS9 Rename function to Primitive
// #TEST#: CS10 Add const qualifier to first parameter
// #TEST#: CS11 Add const qualifier to second parameter
int Function2(int a, int b);

class ChangeSignature
{
public:
    // #TEST#: CS12 Rename first parameter to goink
    // #TEST#: CS13 Rename second parameter to goink
    // #TEST#: CS14 Rename method to Primitive
    // #TEST#: CS15 Change type of first parameter to float
    // #TEST#: CS16 Change return type to float
    int Method1(int a, int b)
    {
        return a + b;
    }

    // #TEST#: CS17 Rename first parameter to goink
    // #TEST#: CS18 Rename second parameter to goink
    // #TEST#: CS19 Change type of first parameter to float
    // #TEST#: CS20 Change return type to float
    int Method2(int a, int b);

private:
    int member1{};
};

}    // namespace ChangeSignatureNamespace
