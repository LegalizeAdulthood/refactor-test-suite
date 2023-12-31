#pragma once

// #TEST#: AP27 Add parameter, int *goink
extern void AddParameterFn();
// #TEST#: AP28 Add parameter, int goink
extern void AddParameterFn(int first);
// #TEST#: AP29 Add parameter, int goink
extern void AddParameterFn(float &first);
// #TEST#: AP30 Add parameter, int goink
extern void AddParameterFn(const float &first);
// #TEST#: AP31 Add parameter, int goink
extern void AddParameterFnRef(const int &first);
// #TEST#: AP32 Add parameter before first, int goink
extern void AddParameterFnDefault(int first = 0);

class AddParameterTester
{
public:
    // #TEST#: AP33 Add parameter, int goink
    AddParameterTester()
    {
    }
    ~AddParameterTester()
    {
    }

    // #TEST#: AP1 Add parameter, int *goink
    void AddParameter()
    {
    }

    // #TEST#: AP2 Add parameter, int goink
    template <typename T>
    void AddParameter2()
    {
    }

    // #TEST#: AP3 Add parameter, int *goink
    void AddParameter(int first);
    // #TEST#: AP4 Add parameter after first, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP5 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP6 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP7 Add parameter before first, int goink
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP8 Add parameter, int goink
    static void Static();
    // #TEST#: AP9 Add parameter after x, int goink
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP10 Add parameter before x, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP11 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

template <typename T>
class AddParameterTemplateClass
{
public:
    // #TEST#: AP34 Add parameter, int goink
    static T StaticTemplate()
    {
        return T(0);
    }

    // #TEST#: AP35 Add parameter, int goink
    T Template()
    {
        return T(0);
    }

    // #TEST#: AP36 Add parameter, int goink
    static void StaticTemplateArg(T arg)
    {
    }

    // #TEST#: AP37 Add parameter, int goink
    void TemplateArg(T arg)
    {
    }

    // #TEST#: AP38 Add parameter before arg, int goink
    void TemplateArgDefault(T arg = 0)
    {
    }
};

template <typename T>
// #TEST#: AP12 Add parameter, int goink
void AddParameter2()
{
    // #TEST#: AP25 Add parameter, int goink
    T::AddParameter();
}

struct AddParameterStruct
{
    // #TEST#: AP39 Add parameter, int goink
    AddParameterStruct()
    {
    }
    ~AddParameterStruct()
    {
    }

    // #TEST#: AP40 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP41 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP42 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP43 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP44 Add parameter before first, int goink
    // #TEST#: AP45 Add parameter after first, int goink = 1
    void AddParameterDefault(int first = 0);

    // #TEST#: AP46 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP47 Add parameter before first, int goink
    // #TEST#: AP48 Add parameter after first, int goink = 1
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP49 Add parameter, int goink
    static void Static();
    // #TEST#: AP50 Add parameter before y, int goink
    // #TEST#: AP51 Add parameter after y, int goink = 3
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP52 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP53 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

union AddParameterUnion
{
public:
    // #TEST#: AP54 Add parameter, int goink
    AddParameterUnion()
    {
    }
    ~AddParameterUnion()
    {
    }

    // #TEST#: AP55 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP56 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP57 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP58 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP59 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP60 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP61 Add parameter before first, int goink
    // #TEST#: AP62 Add parameter after first, int goink = 1
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP63 Add parameter, int goink
    static void Static();
    // #TEST#: AP64 Add parameter before y, int goink
    // #TEST#: AP65 Add parameter after y, int goink = 1
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP66 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP67 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }
};

template <typename Other>
union AddParameterUnionTemplate
{
public:
    // #TEST#: AP68 Add parameter, int goink
    AddParameterUnionTemplate()
    {
    }
    ~AddParameterUnionTemplate()
    {
    }

    // #TEST#: AP69 Add parameter, int *goink
    void AddParameter()
    {
    }

    template <typename T>
    // #TEST#: AP70 Add parameter, int goink
    void AddParameter2()
    {
    }

    // #TEST#: AP71 Add parameter, int goink
    void AddParameter(int first);
    // #TEST#: AP72 Add parameter, int goink
    void AddParameterRef(const int &first);
    // #TEST#: AP73 Add parameter before first, int goink
    void AddParameterDefault(int first = 0);

    // #TEST#: AP74 Add parameter, int goink
    static void AddParameterStaticInline()
    {
    }
    // #TEST#: AP75 Add parameter before first, int goink
    static void AddParameterStaticDefaultInline(int first = 0)
    {
    }
    // #TEST#: AP76 Add parameter, int goink
    static void Static();
    // #TEST#: AP77 Add parameter before y, int goink
    static void StaticDefault(int x, int y = 0);
    template <typename T>
    // #TEST#: AP78 Add parameter, int goink
    static void StaticTemplate(int x)
    {
        T val = x;
    }
    template <typename T>
    // #TEST#: AP79 Add parameter before x, int goink
    static void StaticTemplateDefault(int x = 0)
    {
    }

    // #TEST#: AP80 Add parameter, int goink
    static Other OtherStaticTemplate()
    {
        return Other(0);
    }
    // #TEST#: AP81 Add parameter, int goink
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
    // #TEST#: AP82 Add parameter, int goink
    Outer()
    {
    }
    ~Outer()
    {
    }

    // #TEST#: AP83 Add parameter, int goink
    void Operation()
    {
    }

    class Inner
    {
    public:
        // #TEST#: AP84 Add parameter, int goink
        Inner()
        {
        }

        // #TEST#: AP85 Add parameter, int goink
        void Operation()
        {
        }
    };
};

}    // namespace AddParameterNamespace

template <typename Other>
// #TEST#: AP197 Add parameter, int goink
void AddParameterUnionTemplate<Other>::AddParameter(int first)
{
}

template <typename Other>
// #TEST#: AP198 Add parameter, int goink
void AddParameterUnionTemplate<Other>::AddParameterRef(const int &first)
{
}

template <typename Other>
// #TEST#: AP199 Add parameter before first, int goink
void AddParameterUnionTemplate<Other>::AddParameterDefault(int first)
{
}

template <typename Other>
// #TEST#: AP200 Add parameter, int goink
void AddParameterUnionTemplate<Other>::Static()
{
}

template <typename Other>
// #TEST#: AP201 Add parameter before y, int goink
void AddParameterUnionTemplate<Other>::StaticDefault(int x, int y)
{
}
