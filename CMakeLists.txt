cmake_minimum_required(VERSION 2.8.4)
project(refactor_test_suite)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

set(headers
    RefactorTest/AddParameter.h
    RefactorTest/BooleanToEnum.h
    RefactorTest/ChangeSignature.h
    RefactorTest/CreateOverload.h
    RefactorTest/CreateSetterMethod.h
    RefactorTest/DecomposeParameter.h
    RefactorTest/MoveImplementationToSourceFile.h
    RefactorTest/MoveMethod.h
    RefactorTest/RemoveUnusedParameters.h
    RefactorTest/Rename.h
    RefactorTest/RenameFileToMatchType.h
    RefactorTest/Require.h
    RefactorTest/RefactorTest.h
    RefactorTest/stdafx.h)

set(sources
    RefactorTest/AddOverride.cpp
    RefactorTest/AddParameter.cpp
    RefactorTest/AddBlockDelimiter.cpp
    RefactorTest/BooleanToEnum.cpp
    RefactorTest/BreakApartLineUpParameters.cpp
    RefactorTest/ChangeSignature.cpp
    RefactorTest/CollapseExpandAccessors.cpp
    RefactorTest/CombineConditionals.cpp
    RefactorTest/ConditionalToCase.cpp
    RefactorTest/CreateMethodContract.cpp
    RefactorTest/CreateMethodStub.cpp
    RefactorTest/CreateOverload.cpp
    RefactorTest/CreateSetterMethod.cpp
    RefactorTest/CreateMultiVariableDeclaration.cpp
    RefactorTest/DecomposeParameter.cpp
    RefactorTest/EncapsulateDowncast.cpp
    RefactorTest/EncapsulateField.cpp
    RefactorTest/ExtractConstant.cpp
    RefactorTest/ExtractFunction.cpp
    RefactorTest/ExtractFunction2.cpp
    RefactorTest/ExtractInterface.cpp
    RefactorTest/ExtractMethod.cpp
    RefactorTest/ExtractParameter.cpp
    RefactorTest/ExtractVariable.cpp
    RefactorTest/FlattenConditional.cpp
    RefactorTest/InlineMacro.cpp
    RefactorTest/InlineRecentAssignment.cpp
    RefactorTest/InlineResult.cpp
    RefactorTest/InlineVariable.cpp
    RefactorTest/IntroduceAlias.cpp
    RefactorTest/IntroduceParameter.cpp
    RefactorTest/IntroduceParameterObject.cpp
    RefactorTest/IntroduceResultVariable.cpp
    RefactorTest/MakeMethodStatic.cpp
    RefactorTest/MoveDeclarationNearReference.cpp
    RefactorTest/MoveInitializationToDeclaration.cpp
    RefactorTest/MoveImplementationToSourceFile.cpp
    RefactorTest/MoveMethod.cpp
    RefactorTest/MoveTypeToFile.cpp
    RefactorTest/MoveTypeToNamespace.cpp
    RefactorTest/OptimizeNamespaceReferences.cpp
    RefactorTest/ReduceVisibility.cpp
    RefactorTest/RemoveAssignmentsToParameters.cpp
    RefactorTest/RemoveBlockDelimiter.cpp
    RefactorTest/RemoveRedundantConditional.cpp
    RefactorTest/RemoveUnusedParameters.cpp
    RefactorTest/Rename.cpp
    RefactorTest/Rename2.cpp
    RefactorTest/RenameFileToMatchType.cpp
    RefactorTest/RenameTypeToMatchFile.cpp
    RefactorTest/ReorderParameters.cpp
    RefactorTest/ReplaceAutoPtrWithUniquePtr.cpp
    RefactorTest/ReplaceIfWithTernary.cpp
    RefactorTest/ReplaceIterativeForWithRangeFor.cpp
    RefactorTest/ReplaceNestedConditionalWithGuardClause.cpp
    RefactorTest/ReplaceNullZeroWithNullPtr.cpp
    RefactorTest/ReplaceStringLiteralWithRawStringLiteral.cpp
    RefactorTest/ReplaceTemporaryWithQuery.cpp
    RefactorTest/ReplaceTernaryWithIf.cpp
    RefactorTest/ReplaceTypeWithAuto.cpp
    RefactorTest/ReplaceWithAlias.cpp
    RefactorTest/ReplaceWithConstant.cpp
    RefactorTest/ReplaceWithLocal.cpp
    RefactorTest/ReverseConditional.cpp
    RefactorTest/SafeRename.cpp
    RefactorTest/SimplifyBooleanExpression.cpp
    RefactorTest/SplitInitializationFromDeclaration.cpp
    RefactorTest/SplitMultiVariableDeclaration.cpp
    RefactorTest/SplitTemporaryVariable.cpp
    RefactorTest/stdafx.cpp
    RefactorTest/WidenScope.cpp
    RefactorTest/WidenScopePromoteToConstant.cpp
    RefactorTest/WidenScopePromoteToField.cpp
    RefactorTest/RefactorTest.cpp)

set(SOURCE_FILES ${headers} ${sources})
source_group("Header Files" FILES ${headers})
source_group("Source Files" FILES ${sources})

add_executable(refactor_test_suite ${SOURCE_FILES})
add_custom_command(TARGET refactor_test_suite POST_BUILD COMMAND refactor_test_suite)
