#include "RefactorTest.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    try
    {
        TestAddOverride();
        TestAddParameter();
        TestAddBlockDelimiter();
        TestChangeSignature();
        TestCreateMethodStub();
        TestCreateMultiVariableDeclaration();
        TestCreateSetterMethod();
        TestExtractConstant();
        TestExtractFunction();
        TestExtractMethod();
        TestFlattenConditional();
        TestInlineMacro();
        TestInlineRecentAssignment();
        TestInlineResult();
        TestInlineVariable();
        TestExtractVariable();
        TestMakeMethodStatic();
        TestMoveImplementationToSourceFile();
        TestMoveMethod();
        TestOptimizeNamespaceReferences();
        TestExtractParameter();
        TestRemoveBlockDelimiter();
        TestRemoveUnusedParameter();
        TestRename();
        TestRenameCpp11();
        TestRenameCpp14();
        TestRenameCpp17();
        TestReorderParameters();
        TestReplaceIfWithTernary();
        TestReplaceIterativeForWithRangeFor();
        TestReplaceNullZeroWithNullPtr();
        TestReplaceStringLiteralWithRawStringLiteral();
        TestReplaceTernaryWithIf();
        TestReplaceTypeWithAuto();
        TestReverseConditional();
        TestSimplifyBooleanExpression();
        TestSplitInitializationFromDeclaration();
        TestSplitMultiVariableDeclaration();

        return 0;
    }
    catch (std::runtime_error const &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        return 2;
    }
}
