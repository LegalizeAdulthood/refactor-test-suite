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
// #TEST#: R3 Rename the macro argument x_ from usage
// #TEST#: R4 Rename this macro
#define MACRO_ONE_ARG(x_) (2.0f * x_)

class Operations
{
public:
    int Operation1()
    {
        return 1;
    }
    int Operation2()
    {
        return 2;
    }
};

// #TEST#: R5 Rename this class, but class in Rename2.cpp shouldn't be renamed
class Rename1
{
public:
    // #TEST#: R6 Rename this class via its c'tor
    Rename1() : x()
    {
    }

    // #TEST#: R7 Rename this class via its d'tor
    ~Rename1()
    {
    }

    // #TEST#: R8 Rename this class via typedef
    // #TEST#: R9 Rename typedef MyClass
    typedef Rename1 MyClass;

    // #TEST#: R10 Rename this method
    void Operation()
    {
    }

    int x;
};

// #TEST#: R11 Rename this namespace
namespace X
{
// #TEST#: R12 rename this variable
int x = 0;
// #TEST#: R13 rename this variable
static int y = 1;

// #TEST#: R14 rename this class
class Rename1
{
public:
    Rename1() : _y(0)
    {
    }

    // #TEST#: R15 rename this method
    int Operation()
    {
        return 0;
    }

private:
    void Method()
    {
        int _y = -4;
        // #TEST#: R16 rename _y, which shadows member _y
        _y = 6;
    }
    int _y;
};

}    // namespace X

// #TEST#: R17 rename this namespace
namespace Y
{
// #TEST#: R18 rename this variable
int x = 0;

class X
{
public:
    X()
    {
    }
    ~X()
    {
    }
    void Operation()
    {
    }
};

}    // namespace Y

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
        // #TEST#: R19 Rename data member f
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

// #TEST#: R20 Rename class Operations
// #TEST#: R21 Rename function GetOperation
// #TEST#: R22 Rename parameter flag
static int (Operations::*GetOperation(bool flag))()
{
    // #TEST#: R23 Rename class Operations
    // #TEST#: R24 Rename variable result
    // #TEST#: R25 Rename member Operation1
    int (Operations::*result)() = &Operations::Operation1;
    // #TEST#: R26 Rename variable flag
    if (flag)
    {
        // #TEST#: R27 Rename variable result
        // #TEST#: R28 Rename class Operations
        // #TEST#: R29 Rename method Operation2
        result = &Operations::Operation2;
    }
    // #TEST#: R30 Rename variable result
    return result;
}

// #TEST#: R31 Rename namespace RenameNamespace
namespace RenameNamespace
{
// #TEST#: R32 Rename scoped member Renamed.
int Renamed = 0;

class Base
{
public:
    virtual ~Base()
    {
    }
    // #TEST#: R33 Rename virtual method
    virtual Base *Operation() = 0;
};

class Derived1 : public virtual Base
{
public:
    virtual ~Derived1()
    {
    }
    // #TEST#: R34 Rename virtual method
    virtual Base *Operation()
    {
        return this;
    }
};

class Derived2 : public virtual Derived1
{
public:
    virtual ~Derived2()
    {
    }
    // #TEST#: R35 Rename virtual method
    virtual Base *Operation()
    {
        return this;
    }
};

void TestDerived()
{
    Derived2 d;
    // #TEST#: R36 Rename virtual method
    d.Operation();
}

}    // namespace RenameNamespace

// #TEST#: R37 Rename macro MACRO1
#define MACRO1 -20
// #TEST#: R38 Rename macro MACRO1
#if defined(MACRO1)
// #TEST#: R39 Rename macro MACRO1
static int s_macro_value = MACRO1;
#else
static int s_macro_value = -20;
#endif
// #TEST#: R40 Rename macro MACRO1
#undef MACRO1

// #TEST#: R41 Rename macro MACRO2
#define MACRO2(x_) (-20 * x_)
// #TEST#: R42 Rename macro MACRO2
#ifdef MACRO2
// #TEST#: R43 Rename macro MACRO2
static int s_macro_value2 = MACRO2(2);
#else
static int s_macro_value2 = -40;
#endif
// #TEST#: R44 Rename macro MACRO2
#undef MACRO2

// #TEST#: R45 Rename namespace RenameNamespace
using namespace RenameNamespace;

namespace
{
// #TEST#: R46 Rename T
template <typename T>
// #TEST#: R47 Rename T return type
// #TEST#: R48 Rename f1_aux
// #TEST#: R49 Rename T first parameter type
// #TEST#: R50 Rename value
// #TEST#: R51 Rename T second parameter type
// #TEST#: R52 Rename x
T f1_aux(T value, T x = 1)
{
    // #TEST#: R53 Rename value
    // #TEST#: R54 Rename x
    return value + x;
}

void f1()
{
    // #TEST#: R55 Rename f1_aux
    require_equal(1, f1_aux(0));
    // #TEST#: R56 Rename f1_aux
    require_equal(std::string{"hello world!"}, f1_aux(std::string{"hello "}, std::string{"world!"}));
    // #TEST#: R57 Rename f1_aux
    require_equal(2.0, f1_aux(1.0));
    // #TEST#: R58 Rename f1_aux
    require_equal(7.0f, f1_aux<float>(6));
}

// #TEST#: R59 Rename namespace F2Outer
namespace F2Outer
{
// #TEST#: R60 Rename namespace F2Inner
namespace F2Inner
{
// #TEST#: R61 Rename function f2_aux
int f2_aux()
{
    return 1;
}

}    // namespace F2Inner
}    // namespace F2Outer

void f2_aux2()
{
    // #TEST#: R62 Rename namespace F2Outer
    // #TEST#: R63 Rename namespace F2Inner
    // #TEST#: R64 Rename function f2_aux
    require_equal(1, F2Outer::F2Inner::f2_aux());
}

void f2_aux3()
{
    // #TEST#: R65 Rename namespace F2Outer
    using namespace F2Outer;
    // #TEST#: R66 Rename namespace F2Inner
    // #TEST#: R67 Rename function f2_aux
    require_equal(1, F2Inner::f2_aux());
}

void f2_aux4()
{
    // #TEST#: R68 Rename namespace F2Outer
    // #TEST#: R69 Rename namespace F2Inner
    using namespace F2Outer::F2Inner;
    // #TEST#: R70 Rename function f2_aux
    require_equal(1, f2_aux());
}

void f2_aux5()
{
    // #TEST#: R71 Rename namespace A
    // #TEST#: R72 Rename namespace F2Outer
    namespace A = F2Outer;
    // #TEST#: R73 Rename namespace A
    // #TEST#: R74 Rename namespace F2Inner
    // #TEST#: R75 Rename function f2_aux
    require_equal(1, A::F2Inner::f2_aux());
}

void f2_aux6()
{
    // #TEST#: R76 Rename namespace A
    // #TEST#: R77 Rename namespace F2Outer
    // #TEST#: R78 Rename namespace F2Inner
    namespace A = F2Outer::F2Inner;
    // #TEST#: R79 Rename namespace A
    // #TEST#: R80 Rename function f2_aux
    require_equal(1, A::f2_aux());
}

void f2_aux7()
{
    // #TEST#: R81 Rename namespace A
    // #TEST#: R82 Rename namespace F2Outer
    // #TEST#: R83 Rename namespace F2Inner
    namespace A = F2Outer::F2Inner;
    // #TEST#: R84 Rename namespace A
    using namespace A;
    // #TEST#: R85 Rename function f2_aux
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

// #TEST#: R86 Rename T3
class T3
{
public:
    // #TEST#: R87 Rename T3
    // #TEST#: R88 Rename i3
    T3(int i) : i3(i)
    {
    }
    // #TEST#: R89 Rename i3
    int i3;
};

// #TEST#: R90 Rename i3
int i3 = 3;

// #TEST#: R91 Rename T3
// #TEST#: R92 Rename i3
template <class T3, int i3>
// #TEST#: R93 Rename f3_aux
// #TEST#: R94 Rename T3
// #TEST#: R95 Rename t
int f3_aux(T3 t)
{
    // #TEST#: R96 Rename T3
    // #TEST#: R97 Rename t1
    // #TEST#: R98 Rename t
    T3 t1 = t;
    // #TEST#: R99 Rename i3
    require_equal(2, t1.i3);
    // #TEST#: R100 Rename i3
    require_equal(1, i3);
    // #TEST#: R101 Rename T3
    // #TEST#: R102 Rename t2
    // #TEST#: R103 Rename i3
    ::T3 t2 = ::i3;
    // #TEST#: R104 Rename i3
    require_equal(3, ::i3);
    // #TEST#: R105 Rename t2
    // #TEST#: R106 Rename i3
    return t2.i3;
}

void f3()
{
    // #TEST#: R107 Rename f3_aux
    // #TEST#: R108 Rename T3 template argument
    // #TEST#: R109 Rename T3 function argument expression
    require_equal(3, f3_aux<T3, 1>(T3{2}));
}

// #TEST#: R110 Rename T
template <class T>
// #TEST#: R111 Rename F4
class F4;

template <>
// #TEST#: R112 Rename F4
class F4<int>
{
public:
    // #TEST#: R113 Rename type
    using type = unsigned int;
    // #TEST#: R114 Rename x
    unsigned int x = 4;
};

template <>
// #TEST#: R115 Rename F4
class F4<float>
{
public:
    // #TEST#: R116 Rename type
    using type = double;
    // #TEST#: R117 Rename x
    double x = 10.5;
};

void f4()
{
    // #TEST#: R118 Rename F4
    // #TEST#: R119 Rename x
    require_equal(4U, F4<int>().x);
    // #TEST#: R120 Rename F4
    // #TEST#: R121 Rename type
    require_equal(true, std::is_same<F4<int>::type, unsigned int>::value);
    // #TEST#: R122 Rename F4
    // #TEST#: R123 Rename x
    require_equal(10.5, F4<float>().x);
    // #TEST#: R124 Rename F4
    // #TEST#: R125 Rename type
    require_equal(true, std::is_same<F4<float>::type, double>::value);
}

// #TEST#: R126 Rename T
template <typename T>
// #TEST#: R127 Rename F5
class F5
{
public:
    // #TEST#: R128 Rename type
    // #TEST#: R129 Rename T
    using type = T;
    // #TEST#: R130 Rename T in declaration
    // #TEST#: R131 Rename x
    // #TEST#: R132 Rename T in initializer
    T x = T(3);
};

template <>
// #TEST#: R133 Rename F5
class F5<int>
{
public:
    // #TEST#: R134 Rename type
    using type = unsigned int;
    // #TEST#: R135 Rename x
    unsigned int x = 4;
};

void f5()
{
    // #TEST#: R136 Rename F5
    // #TEST#: R137 Rename x
    require_equal('\3', F5<char>().x);
    // #TEST#: R138 Rename F5
    // #TEST#: R139 Rename type
    require_equal(true, std::is_same<char, F5<char>::type>::value);
    // #TEST#: R140 Rename F5
    // #TEST#: R141 Rename x
    require_equal(4U, F5<int>().x);
    // #TEST#: R142 Rename F5
    // #TEST#: R143 Rename type
    require_equal(true, std::is_same<F5<int>::type, unsigned int>::value);
}

struct F6
{
    // #TEST#: R144 Rename T
    // #TEST#: R145 Rename U
    template <typename T, typename U>
    // #TEST#: R146 (deprecated)
    // #TEST#: R147 Rename f
    // #TEST#: R148 Rename T parameter x type
    // #TEST#: R149 Rename x parameter
    // #TEST#: R150 Rename U parameter y type
    // #TEST#: R151 Rename y parameter
    // #TEST#: R152 Rename x in decltype expression
    // #TEST#: R153 Rename y in decltype expression
    auto f(T x, U y) -> decltype(x + y)
    {
        // #TEST#: R154 Rename count
        ++count;
        // #TEST#: R155 Rename x
        // #TEST#: R156 Rename y
        return x + y;
    }

    // #TEST#: R157 Rename T
    // #TEST#: R158 Rename U
    template <typename T, typename U>
    // #TEST#: R159 Rename g
    // #TEST#: R160 Rename T in decltype expression
    // #TEST#: R161 Rename U in decltype expression
    // #TEST#: R162 Rename T parameter x type
    // #TEST#: R163 Rename x parameter
    // #TEST#: R164 Rename U parameter y type
    // #TEST#: R165 Rename y parameter
    decltype(T() + U()) g(T x, U y)
    {
        // #TEST#: R166 Rename count
        ++count;
        // #TEST#: R167 Rename x
        // #TEST#: R168 Rename y
        return x + y;
    }

    // #TEST#: R169 Rename count
    int count = 0;
};

void f6()
{
    F6 x;
    // #TEST#: R170 Rename method f
    require_equal(3.0, x.f(1, 2.0));
    // #TEST#: R171 Rename method f
    require_equal(std::string{"foobar"}, x.f(std::string{"foo"}, "bar"));
    // #TEST#: R172 Rename count
    require_equal(2, x.count);

    // #TEST#: R173 Rename method g
    require_equal(3.0, x.g(1.0, 2));
    // #TEST#: R174 Rename method g
    require_equal(std::string{"foobar"}, x.g("foo", std::string{"bar"}));
    // #TEST#: R175 Rename count
    require_equal(4, x.count);
}

// #TEST#: R176 Rename F7Base
struct F7Base
{
    // #TEST#: R177 Rename x
    static int x;
};

// #TEST#: R178 Rename F7Base
// #TEST#: R179 Rename x
int F7Base::x = 7;

// #TEST#: R180 Rename F7Derived
// #TEST#: R181 Rename F7Base
struct F7Derived : F7Base
{
};

void f7()
{
    // #TEST#: R182 Rename p
    // #TEST#: R183 Rename F7Base
    // #TEST#: R184 Rename x
    int &p = F7Base::x;
    // #TEST#: R185 Rename q
    // #TEST#: R186 Rename F7Derived
    // #TEST#: R187 Rename x
    int &q = F7Derived::x;
    // #TEST#: R188 Rename p
    require_equal(7, p);
    // #TEST#: R189 Rename q
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
    // #TEST#: R190 Rename anonymous union member
    su.x = 1;
    su.f = 1.0f;
    su.d = 1.0;
    su.s = "Bar";
    su.member(2);
    uf = su.member();

    // #TEST#: R191 Rename MyClass
    // #TEST#: R192 Rename Rename1 from scope qualifier
    Rename1::MyClass myClass;
    myClass.Operation();

    // #TEST#: R193 Rename this variable
    Rename1 test;
    // #TEST#: R194 Rename this method
    test.Operation();
    // #TEST#: R195 Rename this function
    TestRename1();

    {
        using Y::X;
        X xFoo;
        xFoo.Operation();
    }

    // #TEST#: R196 Rename the namespace X
    // #TEST#: R197 Rename the class Rename1
    // #TEST#: R198 Rename the variable test2
    X::Rename1 test2;
    // #TEST#: R199 rename the variable y
    // #TEST#: R200 rename the variable test2
    // #TEST#: R201 rename the method Operation
    // #TEST#: R202 rename the namespace X
    // #TEST#: R203 rename the variable X::x
    // #TEST#: R204 rename the variable X::y
    // #TEST#: R205 rename the variable Y::x
    int y = test2.Operation() + X::x + X::y + Y::x;

    float x = MACRO_NO_ARGS;
    x = MACRO_ONE_ARG(2.0f);

    {
        // #TEST#: R206 Rename the namespace X
        // #TEST#: R207 Rename the variable X::y
        using X::y;
        // #TEST#: R208 Rename y, which is really X::y
        y = -1;
    }

    y = 3;
    {
        int y = 3;
        // #TEST#: R209 Rename y, which shadows outer scope y
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

    // #TEST#: R210 Rename the variable y
    y++;

    using X::Rename1;
    Rename1 fromX;
    fromX.Operation();

    // #TEST#: R211 Rename class Operations
    // #TEST#: R212 Rename variable member
    // #TEST#: R213 Rename function GetOperation
    int (Operations::*member)() = GetOperation(true);
    // #TEST#: R214 Rename variable member
    // #TEST#: R215 Rename class Operations
    // #TEST#: R216 Rename method Operation2
    member = &Operations::Operation2;

    // #TEST#: R217 Rename class Operations
    // #TEST#: R218 Rename variable ops
    Operations ops;
    // #TEST#: R219 Rename variable ops
    // #TEST#: R220 Rename variable member
    (ops.*member)();

    // #TEST#: R221 Rename variable ops2
    Operations *ops2 = new Operations();
    // #TEST#: R222 Rename variable ops2
    // #TEST#: R223 Rename variable member
    (ops2->*member)();
    // #TEST#: R224 Rename variable ops2
    delete ops2;

    // #TEST#: R225 Rename variable ops3
    Operations &ops3 = ops;
    // #TEST#: R226 Rename variable ops3
    // #TEST#: R227 Rename variable member
    ((&ops3)->*member)();

    int x1 = Renamed;

    TestDerived();

    int loop = 0;

    // #TEST#: R228 Rename label
restart:
    loop++;
    if (loop < 5)
    {
        // #TEST#: R229 Rename label
        goto restart;
    }
    REQUIRE_EQUAL(5, loop);

    {
        // #TEST#: R230 Rename variable abstract
        int abstract = 1;
        // #TEST#: R231 Rename variable array
        int array = abstract + 1;
        // #TEST#: R232 Rename variable delegate
        int delegate = array + 1;
        // #TEST#: R233 Rename variable event
        int event = delegate + 1;
        // #TEST#: R234 Rename variable gcnew
        int gcnew = event + 1;
        // #TEST#: R235 Rename variable interface
        int interface = gcnew + 1;
        // #TEST#: R236 Rename variable internal
        int internal = interface + 1;
        // #TEST#: R237 (deprecated)
        // #TEST#: R238 (deprecated)
        // #TEST#: R239 Rename variable override
        int override = internal + 1;
        // #TEST#: R240 Rename variable pin_ptr
        int pin_ptr = override + 1;
        // #TEST#: R241 Rename variable property
        int property = pin_ptr + 1;
        // #TEST#: R242 Rename variable safe_cast
        int safe_cast = property + 1;
        // #TEST#: R243 Rename variable sealed
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
