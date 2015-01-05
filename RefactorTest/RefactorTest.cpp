// RefactorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
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
    TestCreateSplitMultiVariableDeclaration();
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
    TestPromoteToParameter();
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
    TestSplitTemporaryVariable();
    TestWidenScope();
    TestWidenScopePromoteToConstant();
    TestWidenScopePromoteToField();

    return 0;
}
