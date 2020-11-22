#include <cassert>

namespace
{
int getSomething()
{
    static int i = 2;
    return ++i;
}

}    // namespace

// Where possible, simplifies the Boolean expression.
//      expr == true => expr
//      expr == false => !expr
//      false && expr => false
//      true && expr => expr
//      false || expr => expr
//      true || expr => true
//      expr && expr => expr, if no side-effects
//      expr || expr => expr, if no side-effects
//      !(expr1 != expr2) => (expr1 == expr2)
//      !(expr1 == expr2) => (expr1 != expr2)
//      !(expr1 >= expr2) => (expr1 < expr2)
//      !(expr1 <= expr2) => (expr1 > expr2)

void TestSimplifyBooleanExpression()
{
    bool b1 = true;
    // #TEST#: SB1 Simplify boolean rhs to b1
    bool b2 = true && b1;
    assert(b2);

    // #TEST#: SB2 Simplify boolean rhs to false
    bool b3 = false && b1;
    assert(!b3);

    // #TEST#: SB3 Simplify boolean rhs to true
    bool b4 = true || b1;
    assert(b4);

    // #TEST#: SB4 Simplify boolean rhs to b1
    bool b5 = false || b1;
    assert(b5);

    // #TEST#: SB5 Simplify boolean rhs to b1
    bool b6 = b1 && (true && (false || true));
    assert(b6);

    // #TEST#: SB6 Simplify boolean rhs to b1
    bool b7 = b1 == true;
    assert(b7);

    // #TEST#: SB7 Simplify boolean rhs to !b1
    bool b8 = b1 == false;
    assert(!b8);

    // #TEST#: SB8 Simplify boolean rhs to b1
    bool b9 = b1 && b1;
    assert(b9);

    // #TEST#: SB9 Simplify boolean rhs to b1
    bool b10 = b1 || b1;
    assert(b10);

    // #TEST#: SB10 Simplify boolean rhs to (i == 3)
    int const i = getSomething();
    bool b11 = !(i != 3);
    assert(b11);

    // #TEST#: SB11 Simplify boolean rhs to (i != 3)
    bool b12 = !(i == 3);
    assert(!b12);

    // #TEST#: SB12 Simplify boolean rhs to (i > 3)
    bool b13 = !(i <= 3);
    assert(!b13);

    // #TEST#: SB13 Simplify boolean rhs to (i < 3)
    bool b14 = !(i >= 3);
    assert(!b14);
}
