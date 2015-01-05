struct BooleanToEnumStruct
{
    BooleanToEnumStruct() : first(false), second(false), third(false)
    {}
    ~BooleanToEnumStruct()
    {}

    // #TEST#: B2E1 Boolean to Enum
    bool first;

    // #TEST#: B2E2 Boolean to Enum
    bool ReturnValueInline()
    {
        return false;
    }

    // #TEST#: B2E3 Boolean to Enum
    bool ReturnValue();

    // #TEST#: B2E4 Boolean to Enum
    bool &ReturnReference()
    {
        return first;
    }

    // #TEST#: B2E5 Boolean to Enum
    const bool &ReturnConstReference()
    {
        return second;
    }

protected:
    bool second;

    // #TEST#: B2E6 Boolean to Enum
    void Argument(bool one)
    {
        first = one;
    }

    // #TEST#: B2E7 Boolean to Enum
    void Assignment(int value)
    {
        third = (value > 10);
    }

    // #TEST#: B2E8 Boolean to Enum
    void ArgumentReference(bool &one)
    {
        first = one;
    }

    // #TEST#: B2E9 Boolean to Enum
    void Third(bool arg)
    {
        third = arg;
    }

private:
    // #TEST#: B2E10 Boolean to Enum
    bool third;
};

struct BooleanToEnumDerivedStruct : public BooleanToEnumStruct
{
    BooleanToEnumDerivedStruct() : BooleanToEnumStruct()
    {}
    ~BooleanToEnumDerivedStruct()
    {}

    // #TEST#: B2E11 Boolean to Enum
    void Second(bool arg)
    {
        second = arg;
    }
    // #TEST#: B2E12 Boolean to Enum
    void Third(bool arg)
    {
        BooleanToEnumStruct::Third(arg);
    }
    // #TEST#: B2E13 Boolean to Enum
    void Argument(bool arg)
    {
        BooleanToEnumStruct::Argument(arg);
    }
};

class BooleanToEnumClass
{
public:
    // #TEST#: B2E14 Boolean to Enum
    bool first;
protected:
    // #TEST#: B2E15 Boolean to Enum
    bool second;

    // #TEST#: B2E21 Boolean to enum
    void SetThird(bool value)
    {
        third = value;
    }

private:
    // #TEST#: B2E16 Boolean to Enum
    bool third;
};

class BooleanToEnumDerivedClass : public BooleanToEnumClass
{
public:
    void SetSecond(bool value);
    void SetThird(bool value);
};
