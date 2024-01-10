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
        TestInlineTypeAlias();
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
        TestRenameCpp20();
        TestReorderParameters();
        TestReplaceAutoWithType();
        TestReplaceIfWithTernary();
        TestReplaceIterativeForWithRangeFor();
        TestReplaceNullZeroWithNullPtr();
        TestReplaceStringLiteralWithRawStringLiteral();
        TestReplaceTernaryWithIf();
        TestReplaceTypedefWithTypeAlias();
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
