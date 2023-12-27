#pragma once

#include "Config.h"

extern void TestAddOverride();
extern void TestAddBlockDelimiter();
extern void TestAddParameter();
extern void TestChangeSignature();
extern void TestCreateMethodStub();
extern void TestCreateMultiVariableDeclaration();
extern void TestCreateSetterMethod();
extern void TestExtractFunction();
extern void TestExtractMethod();
extern void TestFlattenConditional();
extern void TestInlineMacro();
extern void TestInlineRecentAssignment();
extern void TestInlineResult();
extern void TestInlineTypeAlias();
extern void TestInlineVariable();
extern void TestExtractConstant();
extern void TestExtractVariable();
extern void TestMakeMethodStatic();
extern void TestMoveImplementationToSourceFile();
extern void TestMoveMethod();
extern void TestOptimizeNamespaceReferences();
extern void TestExtractParameter();
extern void TestRemoveBlockDelimiter();
extern void TestRemoveUnusedParameter();
extern void TestRemoveRedundantConditional();
extern void TestRename();
extern void TestRenameCpp11();
#ifdef HAVE_CPP14
extern void TestRenameCpp14();
#else
inline void TestRenameCpp14() {}
#endif
#ifdef HAVE_CPP17
extern void TestRenameCpp17();
#else
inline void TestRenameCpp17() {}
#endif
#ifdef HAVE_CPP20
extern void TestRenameCpp20();
#else
inline void TestRenameCpp20() {}
#endif
extern void TestRenameFileToMatchType();
extern void TestRenameTypeToMatchFile();
extern void TestReorderParameters();
extern void TestReplaceIfWithTernary();
extern void TestReplaceIterativeForWithRangeFor();
extern void TestReplaceNestedConditionalWithGuardClause();
extern void TestReplaceNullZeroWithNullPtr();
extern void TestReplaceStringLiteralWithRawStringLiteral();
extern void TestReplaceTernaryWithIf();
extern void TestReplaceTypedefWithTypeAlias();
extern void TestReplaceTypeWithAuto();
extern void TestReplaceWithAlias();
extern void TestReplaceWithConstant();
extern void TestReverseConditional();
extern void TestSafeRename();
extern void TestSimplifyBooleanExpression();
extern void TestSplitInitializationFromDeclaration();
extern void TestSplitMultiVariableDeclaration();
