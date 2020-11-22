// Unindents the if or else statement for a conditional.
// This will apply one of the following refactorings:
//  Replace Nested Conditional with Guard Clause,
//  Remove Redundant Conditional, or
//  Reverse Conditional
// followed by
//  Remove Redundant Conditional.
// Flatten Conditional is also smart enough to recognize
// if (E) return true; else return false; and convert that to return E;.

namespace FlattenConditionNamespace
{
int TestGuardClause(int *x, int y, int z)
{
    // #TEST#: FC1 Flatten Conditional
    if (x != 0)
    {
        if (y > 0)
        {
            if (z > 0)
            {
                return (*x + 10)*y*z;
            }
        }
    }
    return -1;
}

void TestGuardClause()
{
    int x = 10;
    int y = 2;
    int z = 2;
    int r = TestGuardClause(&x, y, z);
}

void TestRedundantConditional()
{
}

void TestReverseRedundantConditional()
{
}

}    // namespace FlattenConditionNamespace

using namespace FlattenConditionNamespace;

void TestFlattenConditional()
{
    TestGuardClause();
    TestRedundantConditional();
    TestReverseRedundantConditional();
}
