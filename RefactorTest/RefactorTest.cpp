// RefactorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdexcept>

int main(int argc, char* argv[])
{
    try
    {
        TestAddOverride();
        TestAddParameter();
        TestAddBlockDelimiter();
        TestBooleanToEnum();
        TestBreakApartLineUpParameters();
        TestChangeSignature();
        TestCollapseExpandAccessors();
        TestCombineConditionals();
        TestConditionalToCase();
        TestCreateMethodStub();
        TestCreateMultiVariableDeclaration();
        TestCreateOverload();
        TestCreateSetterMethod();
        TestDecomposeParameter();
        TestEncapsulateDowncast();
        TestEncapsulateField();
        TestExtractConstant();
        TestExtractFunction();
        TestExtractInterface();
        TestExtractMethod();
        TestFlattenConditional();
        TestInlineRecentAssignment();
        TestInlineResult();
        TestInlineTemporary();
        TestIntroduceAlias();
        TestExtractVariable();
        TestIntroduceParameter();
        TestIntroduceParameterObject();
        TestIntroduceResultVariable();
        TestMakeMethodStatic();
        TestMoveDeclarationNearReference();
        TestMoveInitializationToDeclaration();
        TestMoveMethod();
        TestMoveTypeToFile();
        TestMoveTypeToNamespace();
        TestOptimizeNamespaceReferences();
        TestExtractParameter();
        TestReduceVisibility();
        TestRemoveAssignmentsToParameters();
        TestRemoveBlockDelimiter();
        TestRemoveRedundantConditional();
        TestRename();
        TestRenameFileToMatchType();
        TestRenameTypeToMatchFile();
        TestReorderParameters();
        TestReplaceIfWithTernary();
        TestReplaceIterativeForWithRangeFor();
        TestReplaceNestedConditionalWithGuardClause();
        TestReplaceNullZeroWithNullPtr();
        TestReplaceTemporaryWithQuery();
        TestReplaceTernaryWithIf();
        TestReplaceTypeWithAuto();
        TestReplaceWithAlias();
        TestReplaceWithConstant();
        TestReplaceWithLocal();
        TestReverseConditional();
        TestSafeRename();
        TestSimplifyBooleanExpression();
        TestSplitInitializationFromDeclaration();
        TestSplitMultiVariableDeclaration();
        TestSplitTemporaryVariable();
        TestWidenScope();
        TestWidenScopePromoteToConstant();
        TestWidenScopePromoteToField();

        return 0;
    }
    catch (std::runtime_error const &)
    {
        return 1;
    }
    catch (...)
    {
        return 2;
    }
}
