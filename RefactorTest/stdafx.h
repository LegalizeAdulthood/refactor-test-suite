// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#include <tchar.h>

extern void TestAddRemoveBlockDelimiter();
extern void TestAddParameter();
extern void TestBooleanToEnum();
extern void TestBreakApartLineUpParameters();
extern void TestCollapseExpandAccessors();
extern void TestCombineConditionals();
extern void TestCompressToExpandFromTernaryExpression();
extern void TestConditionalToCase();
extern void TestCreateMethodContract();
extern void TestCreateMethodStub();
extern void TestCreateSplitMultiVariableDeclaration();
extern void TestCreateOverload();
extern void TestCreateSetterMethod();
extern void TestDecomposeParameter();
extern void TestEncapsulateDowncast();
extern void TestEncapsulateField();
extern void TestExtractFunction();
extern void TestExtractInterface();
extern void TestExtractMethod();
extern void TestFlattenConditional();
extern void TestInlineRecentAssignment();
extern void TestInlineResult();
extern void TestInlineTemporary();
extern void TestIntroduceAlias();
extern void TestIntroduceConstant();
extern void TestIntroduceLocal();
extern void TestIntroduceParameter();
extern void TestIntroduceParameterObject();
extern void TestIntroduceResultVariable();
extern void TestIntroduceSetterGuardClause();
extern void TestMakeMethodStatic();
extern void TestMoveDeclarationNearReference();
extern void TestMoveInitializationToDeclaration();
extern void TestMoveMethod();
extern void TestMoveTypeToFile();
extern void TestMoveTypeToNamespace();
extern void TestOptimizeNamespaceReferences();
extern void TestPromoteToParameter();
extern void TestReduceVisibility();
extern void TestRemoveAssignmentsToParameters();
extern void TestRemoveRedundantConditional();
extern void TestRename();
extern void TestRenameFileToMatchType();
extern void TestRenameTypeToMatchFile();
extern void TestReorderParameters();
extern void TestReplaceNestedConditionalWithGuardClause();
extern void TestReplaceTemporaryWithQuery();
extern void TestReplaceWithAlias();
extern void TestReplaceWithConstant();
extern void TestReplaceWithLocal();
extern void TestReverseConditional();
extern void TestSafeRename();
extern void TestSimplifyBooleanExpression();
extern void TestSplitInitializationFromDeclaration();
extern void TestSplitTemporaryVariable();
extern void TestWidenScope();
extern void TestWidenScopePromoteToConstant();
extern void TestWidenScopePromoteToField();
