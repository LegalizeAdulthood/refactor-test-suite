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
        TestAddRemoveBlockDelimiter();
        TestBooleanToEnum();
        TestBreakApartLineUpParameters();
        TestChangeSignature();
        TestCollapseExpandAccessors();
        TestCombineConditionals();
        TestCompressToExpandFromTernaryExpression();
        TestConditionalToCase();
        TestCreateMethodStub();
        TestCreateMultiVariableDeclaration();
        TestCreateOverload();
        TestCreateSetterMethod();
        TestDecomposeParameter();
        TestEncapsulateDowncast();
        TestEncapsulateField();
        TestExtractFunction();
        TestExtractInterface();
        TestExtractMethod();
        TestFlattenConditional();
        TestInlineRecentAssignment();
        TestInlineResult();
        TestInlineTemporary();
        TestIntroduceAlias();
        TestIntroduceConstant();
        TestIntroduceLocal();
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
        TestRemoveRedundantConditional();
        TestRename();
        TestRenameFileToMatchType();
        TestRenameTypeToMatchFile();
        TestReorderParameters();
        TestReplaceIterativeForWithRangeFor();
        TestReplaceNestedConditionalWithGuardClause();
        TestReplaceNullZeroWithNullPtr();
        TestReplaceTemporaryWithQuery();
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
