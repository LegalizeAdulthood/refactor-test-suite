set(headers
    AddParameter.h
    ChangeSignature.h
    CreateOverload.h
    CreateSetterMethod.h
    MoveImplementationToSourceFile.h
    MoveMethod.h
    RemoveUnusedParameters.h
    Rename.h
    RenameCpp11.h
    Require.h
    RefactorTest.h)

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
    RemoveUnusedParameters.cpp
    Rename.cpp
    Rename2.cpp
    RenameCpp11.cpp
    ReorderParameters.cpp
    ReplaceAutoPtrWithUniquePtr.cpp
    ReplaceIfWithTernary.cpp
    ReplaceIterativeForWithRangeFor.cpp
    ReplaceNullZeroWithNullPtr.cpp
    ReplaceStringLiteralWithRawStringLiteral.cpp
    ReplaceTernaryWithIf.cpp
    ReplaceTypeWithAuto.cpp
    ReverseConditional.cpp
    SimplifyBooleanExpression.cpp
    SplitInitializationFromDeclaration.cpp
    SplitMultiVariableDeclaration.cpp
    RefactorTest.cpp)
set(all_files ${headers} ${sources})
source_group("Header Files" FILES ${headers})
source_group("Source Files" FILES ${sources})

add_executable(refactor_test_suite ${all_files})
set_property(TARGET refactor_test_suite PROPERTY CXX_STANDARD 11)
set_property(TARGET refactor_test_suite PROPERTY CXX_STANDARD_REQUIRED ON)
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_property(SOURCE ReplaceAutoPtrWithUniquePtr.cpp
        APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-declarations)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        set_property(SOURCE SplitMultiVariableDeclaration.cpp
            APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-register)
    endif()
elseif(MSVC)
    target_compile_definitions(refactor_test_suite PUBLIC _CRT_SECURE_NO_WARNINGS)
    set_property(SOURCE RenameCpp11.cpp
        APPEND PROPERTY COMPILE_FLAGS /wd4290)
endif()
add_custom_command(TARGET refactor_test_suite POST_BUILD COMMAND refactor_test_suite)
