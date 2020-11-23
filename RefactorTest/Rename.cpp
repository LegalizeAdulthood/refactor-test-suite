#include "Rename.h"

#include "Require.h"

#include <stdexcept>
#include <string>

// Renames a local variable, function, method, field, property, parameter,
// type, namespace, active CSS style, C++ global variable or C++ macro and
// updates all references to the modified element.

// #TEST#: R24 Rename this macro
#define MACRO_NO_ARGS 3.14159f

// #TEST#: R25 Rename the macro argument x_ from declaration
// #TEST#: R99 Rename the macro argument x_ from usage
// #TEST#: R26 Rename this macro
#define MACRO_ONE_ARG(x_) (2.0f * x_)

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
    Rename1() : x() {}

    // #TEST#: R32 Rename this class via its d'tor
    ~Rename1() {}

    // #TEST#: R33 Rename this class via typedef
    // #TEST#: R34 Rename typedef MyClass
    typedef Rename1 MyClass;

    // #TEST#: R3 Rename this method
    void Operation() {}

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
    Rename1() : _y(0) {}

    // #TEST#: R8 rename this method
    int Operation() { return 0; }

private:
    void Method()
    {
        int _y = -4;
        // #TEST#: R31 rename _y, which shadows member _y
        _y = 6;
    }
    int _y;
};

}    // namespace X

// #TEST#: R9 rename this namespace
namespace Y
{
// #TEST#: R10 rename this variable
int x = 0;

class X
{
public:
    X() {}
    ~X() {}
    void Operation() {}
};

}    // namespace Y

union U
{
    int x;
    float f;
    double d;
    const char *s;
    void member(int x_) { x = x_; }
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
    float member() const { return f; }
    void member(int x_) { x = x_; }
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
    virtual Base *Operation() { return this; }
};

class Derived2 : public virtual Derived1
{
public:
    virtual ~Derived2() {}
    // #TEST#: R72 Rename virtual method
    virtual Base *Operation() { return this; }
};

void TestDerived()
{
    Derived2 d;
    // #TEST#: R73 Rename virtual method
    d.Operation();
}

}    // namespace RenameNamespace

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
#define MACRO2(x_) (-20 * x_)
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
int f2_aux() { return 1; }

}    // namespace F2Inner
}    // namespace F2Outer

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

// #TEST#: R526 Rename T
template <class T>
// #TEST#: R527 Rename F4
class F4;

template <>
// #TEST#: R528 Rename F4
class F4<int>
{
public:
    // #TEST#: R529 Rename type
    using type = unsigned int;
    // #TEST#: R530 Rename x
    unsigned int x = 4;
};

template <>
// #TEST#: R531 Rename F4
class F4<float>
{
public:
    // #TEST#: R532 Rename type
    using type = double;
    // #TEST#: R533 Rename x
    double x = 10.5;
};

void f4()
{
    // #TEST#: R534 Rename F4
    // #TEST#: R535 Rename x
    require_equal(4U, F4<int>().x);
    // #TEST#: R536 Rename F4
    // #TEST#: R537 Rename type
    require_equal(true, std::is_same<F4<int>::type, unsigned int>::value);
    // #TEST#: R538 Rename F4
    // #TEST#: R539 Rename x
    require_equal(10.5, F4<float>().x);
    // #TEST#: R540 Rename F4
    // #TEST#: R541 Rename type
    require_equal(true, std::is_same<F4<float>::type, double>::value);
}

// #TEST#: R542 Rename T
template <typename T>
// #TEST#: R543 Rename F5
class F5
{
public:
    // #TEST#: R544 Rename type
    // #TEST#: R545 Rename T
    using type = T;
    // #TEST#: R546 Rename T in declaration
    // #TEST#: R547 Rename x
    // #TEST#: R548 Rename T in initializer
    T x = T(3);
};

template <>
// #TEST#: R549 Rename F5
class F5<int>
{
public:
    // #TEST#: R550 Rename type
    using type = unsigned int;
    // #TEST#: R551 Rename x
    unsigned int x = 4;
};

void f5()
{
    // #TEST#: R552 Rename F5
    // #TEST#: R553 Rename x
    require_equal('\3', F5<char>().x);
    // #TEST#: R554 Rename F5
    // #TEST#: R555 Rename type
    require_equal(true, std::is_same<char, F5<char>::type>::value);
    // #TEST#: R556 Rename F5
    // #TEST#: R557 Rename x
    require_equal(4U, F5<int>().x);
    // #TEST#: R558 Rename F5
    // #TEST#: R559 Rename type
    require_equal(true, std::is_same<F5<int>::type, unsigned int>::value);
}

struct F6
{
    // #TEST#: R560 Rename T
    // #TEST#: R561 Rename U
    template <typename T, typename U>
    // #TEST#: R563 Rename f
    // #TEST#: R564 Rename T parameter x type
    // #TEST#: R565 Rename x parameter
    // #TEST#: R566 Rename U parameter y type
    // #TEST#: R567 Rename y parameter
    // #TEST#: R568 Rename x in decltype expression
    // #TEST#: R569 Rename y in decltype expression
    auto f(T x, U y) -> decltype(x + y)
    {
        // #TEST#: R570 Rename count
        ++count;
        // #TEST#: R571 Rename x
        // #TEST#: R572 Rename y
        return x + y;
    }

    // #TEST#: R573 Rename T
    // #TEST#: R574 Rename U
    template <typename T, typename U>
    // #TEST#: R575 Rename g
    // #TEST#: R576 Rename T in decltype expression
    // #TEST#: R577 Rename U in decltype expression
    // #TEST#: R578 Rename T parameter x type
    // #TEST#: R579 Rename x parameter
    // #TEST#: R580 Rename U parameter y type
    // #TEST#: R581 Rename y parameter
    decltype(T() + U()) g(T x, U y)
    {
        // #TEST#: R582 Rename count
        ++count;
        // #TEST#: R583 Rename x
        // #TEST#: R584 Rename y
        return x + y;
    }

    // #TEST#: R585 Rename count
    int count = 0;
};

void f6()
{
    F6 x;
    // #TEST#: R586 Rename method f
    require_equal(3.0, x.f(1, 2.0));
    // #TEST#: R587 Rename method f
    require_equal(std::string{"foobar"}, x.f(std::string{"foo"}, "bar"));
    // #TEST#: R588 Rename count
    require_equal(2, x.count);

    // #TEST#: R589 Rename method g
    require_equal(3.0, x.g(1.0, 2));
    // #TEST#: R590 Rename method g
    require_equal(std::string{"foobar"}, x.g("foo", std::string{"bar"}));
    // #TEST#: R591 Rename count
    require_equal(4, x.count);
}

// #TEST#: R592 Rename F7Base
struct F7Base
{
    // #TEST#: R593 Rename x
    static int x;
};

// #TEST#: R594 Rename F7Base
// #TEST#: R595 Rename x
int F7Base::x = 7;

// #TEST#: R596 Rename F7Derived
// #TEST#: R597 Rename F7Base
struct F7Derived : F7Base
{
};

void f7()
{
    // #TEST#: R598 Rename p
    // #TEST#: R599 Rename F7Base
    // #TEST#: R600 Rename x
    int &p = F7Base::x;
    // #TEST#: R601 Rename q
    // #TEST#: R602 Rename F7Derived
    // #TEST#: R603 Rename x
    int &q = F7Derived::x;
    // #TEST#: R604 Rename p
    require_equal(7, p);
    // #TEST#: R605 Rename q
    require_equal(7, q);
}

}    // namespace

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
    f4();
    f5();
    f6();
    f7();
}
