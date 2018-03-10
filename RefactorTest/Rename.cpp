#include "Rename.h"
#include "Require.h"
#include <string>
#include <stdexcept>

// Renames a local variable, function, method, field, property, parameter,
// type, namespace, active CSS style, C++ global variable or C++ macro and
// updates all references to the modified element.

// #TEST#: R24 Rename this macro
#define MACRO_NO_ARGS 3.14159f

// #TEST#: R25 Rename the macro argument x_ from declaration
// #TEST#: R99 Rename the macro argument x_ from usage
// #TEST#: R26 Rename this macro
#define MACRO_ONE_ARG(x_) (2.0f*x_)

class Operations
{
public:
    int Operation1() { return 1; }
    int Operation2() { return 2; }
};

// #TEST#: R1 Rename this class, but class in Rename2.cpp shouldn't be renamed
class Rename1
{
public:
    // #TEST#: R2 Rename this class via its c'tor
    Rename1()
        : x()
    {
    }

    // #TEST#: R32 Rename this class via its d'tor
    ~Rename1()
    {
    }

    // #TEST#: R33 Rename this class via typedef
    // #TEST#: R34 Rename typedef MyClass
    typedef Rename1 MyClass;

    // #TEST#: R3 Rename this method
    void Operation()
    {
    }

    int x;
};

// #TEST#: R4 Rename this namespace
namespace X
{

// #TEST#: R5 rename this variable
int x = 0;
// #TEST#: R6 rename this variable
static int y = 1;

// #TEST#: R7 rename this class
class Rename1
{
public:
    Rename1() : _y(0)
    {
    }

    // #TEST#: R8 rename this method
    int Operation()
    {
        return 0;
    }

private:
    void Method()
    {
        int _y = -4;
        // #TEST#: R31 rename _y, which shadows member _y
        _y = 6;
    }
    int _y;
};

}

// #TEST#: R9 rename this namespace
namespace Y
{

// #TEST#: R10 rename this variable
int x = 0;

class X
{
public:
    X()
    {}
    ~X()
    {
    }
    void Operation()
    {
    }
};

}

union U
{
    int x;
    float f;
    double d;
    const char *s;
    void member(int x_)
    {
        x = x_;
    }
    float member() const
    {
        // #TEST#: R38 Rename data member f
        return f;
    }
};

struct SU
{
    int kind;
    union
    {
        int x;
        float f;
        double d;
        const char *s;
    };
    float member() const
    {
        return f;
    }
    void member(int x_)
    {
        x = x_;
    }
};

// #TEST#: R39 Rename class Operations
// #TEST#: R40 Rename function GetOperation
// #TEST#: R41 Rename parameter flag
static int (Operations::*GetOperation(bool flag))()
{
    // #TEST#: R42 Rename class Operations
    // #TEST#: R43 Rename variable result
    // #TEST#: R44 Rename member Operation1
    int (Operations::*result)() = &Operations::Operation1;
    // #TEST#: R45 Rename variable flag
    if (flag)
    {
        // #TEST#: R46 Rename variable result
        // #TEST#: R47 Rename class Operations
        // #TEST#: R48 Rename method Operation2
        result = &Operations::Operation2;
    }
    // #TEST#: R49 Rename variable result
    return result;
}

// #TEST#: R56 Rename namespace RenameNamespace
namespace RenameNamespace
{

// #TEST#: R57 Rename scoped member Renamed.
int Renamed = 0;

class Base
{
public:
    virtual ~Base() {}
    // #TEST#: R70 Rename virtual method
    virtual Base *Operation() = 0;
};

class Derived1 : public virtual Base
{
public:
    virtual ~Derived1() {}
    // #TEST#: R71 Rename virtual method
    virtual Base *Operation()
    {
        return this;
    }
};

class Derived2 : public virtual Derived1
{
public:
    virtual ~Derived2() {}
    // #TEST#: R72 Rename virtual method
    virtual Base *Operation()
    {
        return this;
    }
};

void TestDerived()
{
    Derived2 d;
    // #TEST#: R73 Rename virtual method
    d.Operation();
}

}

// #TEST#: R74 Rename macro MACRO1
#define MACRO1 -20
// #TEST#: R75 Rename macro MACRO1
#if defined(MACRO1)
// #TEST#: R76 Rename macro MACRO1
static int s_macro_value = MACRO1;
#else
static int s_macro_value = -20;
#endif
// #TEST#: R77 Rename macro MACRO1
#undef MACRO1

// #TEST#: R78 Rename macro MACRO2
#define MACRO2(x_) (-20*x_)
// #TEST#: R79 Rename macro MACRO2
#ifdef MACRO2
// #TEST#: R80 Rename macro MACRO2
static int s_macro_value2 = MACRO2(2);
#else
static int s_macro_value2 = -40;
#endif
// #TEST#: R81 Rename macro MACRO2
#undef MACRO2

// #TEST#: R58 Rename namespace RenameNamespace
using namespace RenameNamespace;

namespace
{

// #TEST#: R416 Rename T
template <typename T>
// #TEST#: R417 Rename T return type
// #TEST#: R418 Rename f1_aux
// #TEST#: R419 Rename T first parameter type
// #TEST#: R420 Rename value
// #TEST#: R421 Rename T second parameter type
// #TEST#: R422 Rename x
T f1_aux(T value, T x = 1)
{
    // #TEST#: R423 Rename value
    // #TEST#: R424 Rename x
    return value + x;
}

void f1()
{
    // #TEST#: R425 Rename f1_aux
    require_equal(1, f1_aux(0));
    // #TEST#: R426 Rename f1_aux
    require_equal(std::string{"hello world!"}, f1_aux(std::string{"hello "}, std::string{"world!"}));
    // #TEST#: R427 Rename f1_aux
    require_equal(2.0, f1_aux(1.0));
    // #TEST#: R428 Rename f1_aux
    require_equal(7.0f, f1_aux<float>(6));
}

// #TEST#: R475 Rename namespace F2Outer
namespace F2Outer
{
// #TEST#: R476 Rename namespace F2Inner
namespace F2Inner
{

// #TEST#: R477 Rename function f2_aux
int f2_aux()
{
    return 1;
}

} // namespace F2Inner
} // namespace F2Outer

void f2_aux2()
{
    // #TEST#: R478 Rename namespace F2Outer
    // #TEST#: R479 Rename namespace F2Inner
    // #TEST#: R480 Rename function f2_aux
    require_equal(1, F2Outer::F2Inner::f2_aux());
}

void f2_aux3()
{
    // #TEST#: R481 Rename namespace F2Outer
    using namespace F2Outer;
    // #TEST#: R482 Rename namespace F2Inner
    // #TEST#: R483 Rename function f2_aux
    require_equal(1, F2Inner::f2_aux());
}

void f2_aux4()
{
    // #TEST#: R484 Rename namespace F2Outer
    // #TEST#: R485 Rename namespace F2Inner
    using namespace F2Outer::F2Inner;
    // #TEST#: R486 Rename function f2_aux
    require_equal(1, f2_aux());
}

void f2_aux5()
{
    // #TEST#: R487 Rename namespace A
    // #TEST#: R488 Rename namespace F2Outer
    namespace A = F2Outer;
    // #TEST#: R489 Rename namespace A
    // #TEST#: R490 Rename namespace F2Inner
    // #TEST#: R491 Rename function f2_aux
    require_equal(1, A::F2Inner::f2_aux());
}

void f2_aux6()
{
    // #TEST#: R492 Rename namespace A
    // #TEST#: R493 Rename namespace F2Outer
    // #TEST#: R494 Rename namespace F2Inner
    namespace A = F2Outer::F2Inner;
    // #TEST#: R495 Rename namespace A
    // #TEST#: R496 Rename function f2_aux
    require_equal(1, A::f2_aux());
}

void f2_aux7()
{
    // #TEST#: R497 Rename namespace A
    // #TEST#: R498 Rename namespace F2Outer
    // #TEST#: R499 Rename namespace F2Inner
    namespace A = F2Outer::F2Inner;
    // #TEST#: R500 Rename namespace A
    using namespace A;
    // #TEST#: R501 Rename function f2_aux
    require_equal(1, f2_aux());
}

void f2()
{
    f2_aux2();
    f2_aux3();
    f2_aux4();
    f2_aux5();
    f2_aux6();
    f2_aux7();
}

// #TEST#: R502 Rename T3
class T3
{
public:
    // #TEST#: R503 Rename T3
    // #TEST#: R504 Rename i3
    T3(int i) : i3(i) {}
    // #TEST#: R505 Rename i3
    int i3;
};

// #TEST#: R506 Rename i3
int i3 = 3;

// #TEST#: R507 Rename T3
// #TEST#: R508 Rename i3
template <class T3, int i3>
// #TEST#: R509 Rename f3_aux
// #TEST#: R510 Rename T3
// #TEST#: R511 Rename t
int f3_aux(T3 t)
{
    // #TEST#: R512 Rename T3
    // #TEST#: R513 Rename t1
    // #TEST#: R514 Rename t
    T3 t1 = t;
    // #TEST#: R515 Rename i3
    require_equal(2, t1.i3);
    // #TEST#: R516 Rename i3
    require_equal(1, i3);
    // #TEST#: R517 Rename T3
    // #TEST#: R518 Rename t2
    // #TEST#: R519 Rename i3
    ::T3 t2 = ::i3;
    // #TEST#: R520 Rename i3
    require_equal(3, ::i3);
    // #TEST#: R521 Rename t2
    // #TEST#: R522 Rename i3
    return t2.i3;
}

void f3()
{
    // #TEST#: R523 Rename f3_aux
    // #TEST#: R524 Rename T3 template argument
    // #TEST#: R525 Rename T3 function argument expression
    require_equal(3, f3_aux<T3, 1>(T3{2}));
}

}

void TestRename()
{
    U u;
    u.x = 1;
    u.f = 1.0f;
    u.d = 1.0;
    u.s = "Foo";
    u.member(2);
    float uf = u.member();
    SU su;
    // #TEST#: R37 Rename anonymous union member
    su.x = 1;
    su.f = 1.0f;
    su.d = 1.0;
    su.s = "Bar";
    su.member(2);
    uf = su.member();

    // #TEST#: R35 Rename MyClass
    // #TEST#: R36 Rename Rename1 from scope qualifier
    Rename1::MyClass myClass;
    myClass.Operation();

    // #TEST#: R11 Rename this variable
    Rename1 test;
    // #TEST#: R12 Rename this method
    test.Operation();
    // #TEST#: R13 Rename this function
    TestRename1();

    {
        using Y::X;
        X xFoo;
        xFoo.Operation();
    }

    // #TEST#: R14 Rename the namespace X
    // #TEST#: R15 Rename the class Rename1
    // #TEST#: R16 Rename the variable test2
    X::Rename1 test2;
    // #TEST#: R17 rename the variable y
    // #TEST#: R18 rename the variable test2
    // #TEST#: R19 rename the method Operation
    // #TEST#: R20 rename the namespace X
    // #TEST#: R21 rename the variable X::x
    // #TEST#: R22 rename the variable X::y
    // #TEST#: R23 rename the variable Y::x
    int y = test2.Operation() + X::x + X::y + Y::x;

    float x = MACRO_NO_ARGS;
    x = MACRO_ONE_ARG(2.0f);

    {
        // #TEST#: R27 Rename the namespace X
        // #TEST#: R28 Rename the variable X::y
        using X::y;
        // #TEST#: R29 Rename y, which is really X::y
        y = -1;
    }

    y = 3;
    {
        int y = 3;
        // #TEST#: R30 Rename y, which shadows outer scope y
        y = 4;
        if (y != 4)
        {
            throw std::runtime_error("R30 may have failed");
        }
    }
    if (y != 3)
    {
        throw std::runtime_error("R30 may have failed");
    }

    // #TEST#: R98 Rename the variable y
    y++;

    using X::Rename1;
    Rename1 fromX;
    fromX.Operation();

    // #TEST#: R50 Rename class Operations
    // #TEST#: R51 Rename variable member
    // #TEST#: R52 Rename function GetOperation
    int (Operations::*member)() = GetOperation(true);
    // #TEST#: R53 Rename variable member
    // #TEST#: R54 Rename class Operations
    // #TEST#: R55 Rename method Operation2
    member = &Operations::Operation2;

    // #TEST#: R59 Rename class Operations
    // #TEST#: R60 Rename variable ops
    Operations ops;
    // #TEST#: R61 Rename variable ops
    // #TEST#: R62 Rename variable member
    (ops.*member)();

    // #TEST#: R63 Rename variable ops2
    Operations *ops2 = new Operations();
    // #TEST#: R64 Rename variable ops2
    // #TEST#: R65 Rename variable member
    (ops2->*member)();
    // #TEST#: R66 Rename variable ops2
    delete ops2;

    // #TEST#: R67 Rename variable ops3
    Operations &ops3 = ops;
    // #TEST#: R68 Rename variable ops3
    // #TEST#: R69 Rename variable member
    ((&ops3)->*member)();

    int x1 = Renamed;

    TestDerived();

    int loop = 0;

    // #TEST#: R82 Rename label
restart:
    loop++;
    if (loop < 5)
    {
        // #TEST#: R83 Rename label
        goto restart;
    }
    REQUIRE_EQUAL(5, loop);

    {
        // #TEST#: R84 Rename variable abstract
        int abstract = 1;
        // #TEST#: R85 Rename variable array
        int array = abstract + 1;
        // #TEST#: R86 Rename variable delegate
        int delegate = array + 1;
        // #TEST#: R87 Rename variable event
        int event = delegate + 1;
        // #TEST#: R88 Rename variable gcnew
        int gcnew = event + 1;
        // #TEST#: R89 Rename variable interface
        int interface = gcnew + 1;
        // #TEST#: R90 Rename variable internal
        int internal = interface + 1;
        // #TEST#: R93 Rename variable override
        int override = internal + 1;
        // #TEST#: R94 Rename variable pin_ptr
        int pin_ptr = override + 1;
        // #TEST#: R95 Rename variable property
        int property = pin_ptr + 1;
        // #TEST#: R96 Rename variable safe_cast
        int safe_cast = property + 1;
        // #TEST#: R97 Rename variable sealed
        int sealed = safe_cast + 1;
        int x = sealed + 1;
        std::string dashes;
        dashes.append(x, '-');
        REQUIRE_EQUAL(std::string("-------------"), dashes);
    }
    f1();
    f2();
    f3();
}
