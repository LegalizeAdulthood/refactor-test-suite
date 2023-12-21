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
    RefactorTest.cpp
    Config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/Config.h
)
source_group("Header Files" REGULAR_EXPRESSION ".*\\.h")
source_group("Source Files" REGULAR_EXPRESSION ".*\\.cpp")
source_group("CMake Template Files" REGULAR_EXPRESSION ".*\\.in")
set(cxx_standard 11)
if("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    set(cxx_standard 14)
    target_sources(refactor_test_suite PUBLIC RenameCpp14.h RenameCpp14.cpp)
    set(HAVE_CPP14 ON)
endif()
configure_file(Config.h.in include/Config.h)
set_target_properties(refactor_test_suite PROPERTIES
    CXX_STANDARD ${cxx_standard}
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_include_directories(refactor_test_suite PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
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
