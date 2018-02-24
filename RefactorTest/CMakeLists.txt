set(headers
    AddParameter.h
    ChangeSignature.h
    CreateOverload.h
    CreateSetterMethod.h
    DecomposeParameter.h
    MoveImplementationToSourceFile.h
    MoveMethod.h
    RemoveUnusedParameters.h
    Rename.h
    RenameCpp11.h
    RenameFileToMatchType.h
    Require.h
    RefactorTest.h
    stdafx.h)

set(sources
    AddOverride.cpp
    AddParameter.cpp
    AddBlockDelimiter.cpp
    ChangeSignature.cpp
    CreateMethodStub.cpp
    CreateSetterMethod.cpp
    CreateMultiVariableDeclaration.cpp
    ExtractConstant.cpp
    ExtractFunction.cpp
    ExtractFunction2.cpp
    ExtractMethod.cpp
    ExtractParameter.cpp
    ExtractVariable.cpp
    FlattenConditional.cpp
    InlineMacro.cpp
    InlineRecentAssignment.cpp
    InlineResult.cpp
    InlineVariable.cpp
    MakeMethodStatic.cpp
    MoveImplementationToSourceFile.cpp
    MoveMethod.cpp
    OptimizeNamespaceReferences.cpp
    RemoveBlockDelimiter.cpp
    RemoveRedundantConditional.cpp
    RemoveUnusedParameters.cpp
    Rename.cpp
    Rename2.cpp
    RenameCpp11.cpp
    RenameFileToMatchType.cpp
    RenameTypeToMatchFile.cpp
    ReorderParameters.cpp
    ReplaceAutoPtrWithUniquePtr.cpp
    ReplaceIfWithTernary.cpp
    ReplaceIterativeForWithRangeFor.cpp
    ReplaceNestedConditionalWithGuardClause.cpp
    ReplaceNullZeroWithNullPtr.cpp
    ReplaceStringLiteralWithRawStringLiteral.cpp
    ReplaceTernaryWithIf.cpp
    ReplaceTypeWithAuto.cpp
    ReplaceWithAlias.cpp
    ReplaceWithConstant.cpp
    ReverseConditional.cpp
    SafeRename.cpp
    SimplifyBooleanExpression.cpp
    SplitInitializationFromDeclaration.cpp
    SplitMultiVariableDeclaration.cpp
    stdafx.cpp
    RefactorTest.cpp)
set(source_files ${headers} ${sources})
source_group("Header Files" FILES ${headers})
source_group("Source Files" FILES ${sources})

add_executable(refactor_test_suite ${source_files})
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    target_compile_options(refactor_test_suite PUBLIC -std=c++11)
    set_property(SOURCE ReplaceAutoPtrWithUniquePtr.cpp
        APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-declarations)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        set_property(SOURCE SplitMultiVariableDeclaration.cpp
            APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-register)
    endif()
endif()
add_custom_command(TARGET refactor_test_suite POST_BUILD COMMAND refactor_test_suite)
