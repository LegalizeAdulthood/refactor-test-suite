#pragma once

// #TEST#: AP1 Add parameter, int *goink
extern void AddParameterFn();
// #TEST#: AP2 Add parameter, int goink
extern void AddParameterFn(int first);
// #TEST#: AP3 Add parameter, int goink
extern void AddParameterFn(float &first);
// #TEST#: AP4 Add parameter, int goink
extern void AddParameterFn(const float &first);
// #TEST#: AP5 Add parameter, int goink
extern void AddParameterFnRef(const int &first);
// #TEST#: AP6 Add parameter before first, int goink
extern void AddParameterFnDefault(int first = 0);

class AddParameterTester
{
public:
    // #TEST#: AP7 Add parameter, int goink
    AddParameterTester()
    {
    }
    ~AddParameterTester()
    {
    }

    // #TEST#: AP8 Add parameter, int *goink
    void AddParameter()
    {
    }

    // #TEST#: AP9 Add parameter, int goink
    template <typename T>
    void AddParameter2()
    {
    }

    // #TEST#: AP10 Add parameter, int *goink
    void AddParameter(int first);
    // #TEST#: AP11 Add parameter after first, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP12 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP13 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP14 Add parameter before first, int goink
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP15 Add parameter, int goink
    static void Static();
    // #TEST#: AP16 Add parameter after x, int goink
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP17 Add parameter before x, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP18 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

template <typename T>
class AddParameterTemplateClass
{
public:
    // #TEST#: AP19 Add parameter, int goink
    static T StaticTemplate()
    {
        return T(0);
    }

    // #TEST#: AP20 Add parameter, int goink
    T Template()
    {
        return T(0);
    }

    // #TEST#: AP21 Add parameter, int goink
    static void StaticTemplateArg(T arg)
    {
    }

    // #TEST#: AP22 Add parameter, int goink
    void TemplateArg(T arg)
    {
    }

    // #TEST#: AP23 Add parameter before arg, int goink
    void TemplateArgDefault(T arg = 0)
    {
    }
};

template <typename T>
// #TEST#: AP24 Add parameter, int goink
void AddParameter2()
{
    // #TEST#: AP25 Add parameter, int goink
    T::AddParameter();
}

struct AddParameterStruct
{
    // #TEST#: AP26 Add parameter, int goink
    AddParameterStruct()
    {
    }
    ~AddParameterStruct()
    {
    }

    // #TEST#: AP27 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP28 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP29 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP30 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP31 Add parameter before first, int goink
    // #TEST#: AP32 Add parameter after first, int goink = 1
    void AddParameterDefault(int first = 0);

    // #TEST#: AP33 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP34 Add parameter before first, int goink
    // #TEST#: AP35 Add parameter after first, int goink = 1
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP36 Add parameter, int goink
    static void Static();
    // #TEST#: AP37 Add parameter before y, int goink
    // #TEST#: AP38 Add parameter after y, int goink = 3
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP39 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP40 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

union AddParameterUnion
{
public:
    // #TEST#: AP41 Add parameter, int goink
    AddParameterUnion()
    {
    }
    ~AddParameterUnion()
    {
    }

    // #TEST#: AP42 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP43 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP44 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP45 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP46 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP47 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP48 Add parameter before first, int goink
    // #TEST#: AP49 Add parameter after first, int goink = 1
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP50 Add parameter, int goink
    static void Static();
    // #TEST#: AP51 Add parameter before y, int goink
    // #TEST#: AP52 Add parameter after y, int goink = 1
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP53 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP54 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

template <typename Other>
union AddParameterUnionTemplate
{
public:
    // #TEST#: AP55 Add parameter, int goink
    AddParameterUnionTemplate()
    {
    }
    ~AddParameterUnionTemplate()
    {
    }

    // #TEST#: AP56 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP57 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP58 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP59 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP60 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP61 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP62 Add parameter before first, int goink
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP63 Add parameter, int goink
    static void Static();
    // #TEST#: AP64 Add parameter before y, int goink
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP65 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP66 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }

    // #TEST#: AP67 Add parameter, int goink
    static Other OtherStaticTemplate()
    {
        return Other(0);
    }
    // #TEST#: AP68 Add parameter, int goink
    Other OtherTemplate()
    {
        return Other(0);
    }
};

namespace AddParameterNamespace
{
class Outer
{
public:
    // #TEST#: AP69 Add parameter, int goink
    Outer()
    {
    }
    ~Outer()
    {
    }

    // #TEST#: AP70 Add parameter, int goink
    void Operation()
    {
    }

    class Inner
    {
    public:
        // #TEST#: AP71 Add parameter, int goink
        Inner()
        {
        }

        // #TEST#: AP72 Add parameter, int goink
        void Operation()
        {
        }
    };
};

}    // namespace AddParameterNamespace

template <typename Other>
// #TEST#: AP73 Add parameter, int goink
void AddParameterUnionTemplate<Other>::AddParameter(int first)
{
}

template <typename Other>
// #TEST#: AP74 Add parameter, int goink
void AddParameterUnionTemplate<Other>::AddParameterRef(const int &first)
{
}

template <typename Other>
// #TEST#: AP75 Add parameter before first, int goink
void AddParameterUnionTemplate<Other>::AddParameterDefault(int first)
{
}

template <typename Other>
// #TEST#: AP76 Add parameter, int goink
void AddParameterUnionTemplate<Other>::Static()
{
}

template <typename Other>
// #TEST#: AP77 Add parameter before y, int goink
void AddParameterUnionTemplate<Other>::StaticDefault(int x, int y)
{
}
