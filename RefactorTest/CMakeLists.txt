add_executable(refactor_test_suite
    AddOverride.cpp
    AddParameter.h
    AddParameter.cpp
    AddBlockDelimiter.cpp
    ChangeSignature.h
    ChangeSignature.cpp
    CreateMethodStub.cpp
    CreateOverload.h
    CreateSetterMethod.h
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
    MoveImplementationToSourceFile.h
    MoveImplementationToSourceFile.cpp
    MoveMethod.h
    MoveMethod.cpp
    OptimizeNamespaceReferences.cpp
    RefactorTest.h
    RemoveBlockDelimiter.cpp
    RemoveUnusedParameters.h
    RemoveUnusedParameters.cpp
    Rename.h
    Rename.cpp
    Rename2.cpp
    RenameCpp11.h
    RenameCpp11.cpp
    ReorderParameters.cpp
    Require.h
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
source_group("Header Files" REGULAR_EXPRESSION ".*\\.h")
source_group("Source Files" REGULAR_EXPRESSION ".*\\.cpp")
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
