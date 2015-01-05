#include "stdafx.h"
#include "BooleanToEnum.h"

// Converts a boolean type to an enumeration, updating client code if necessary.


// #TEST#: B2E17 Boolean to Enum
static bool first = true;
// #TEST#: B2E18 Boolean to Enum
bool second = false;

bool BooleanToEnumStruct::ReturnValue()
{
    return third;
}

void BooleanToEnumDerivedClass::SetSecond(bool value)
{
    second = value;
}

void BooleanToEnumDerivedClass::SetThird(bool value)
{
    BooleanToEnumClass::SetThird(value);
}

void TestBooleanToEnum()
{
    // #TEST#: B2E19 Boolean to Enum
    bool foo = first;
    // #TEST#: B2E20 Boolean to Enum
    bool &bar = second;

    BooleanToEnumStruct s;
    s.first = true;

    BooleanToEnumDerivedStruct ds;
    ds.Second(false);
    ds.Third(true);
    ds.Argument(foo);

    BooleanToEnumClass c;
    c.first = true;

    BooleanToEnumDerivedClass dc;
    dc.first = true;
    dc.SetSecond(true);
    dc.SetThird(true);
}
