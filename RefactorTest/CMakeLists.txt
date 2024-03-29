add_library(refactor-test-cases STATIC
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
    ExtractFunction2.c
    ExtractMethod.cpp
    ExtractParameter.cpp
    ExtractVariable.cpp
    FlattenConditional.cpp
    InlineMacro.cpp
    InlineTypeAlias.cpp
    InlineVariable.cpp
    MakeMethodStatic.cpp
    MoveImplementationToSourceFile.h
    MoveImplementationToSourceFile.cpp
    MoveMethod.h
    MoveMethod.cpp
    RemoveBlockDelimiter.cpp
    RemoveUnusedIncludes.cpp
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
    ReplaceAutoWithType.cpp
    ReplaceIfWithTernary.cpp
    ReplaceIterativeForWithRangeFor.cpp
    ReplaceNullZeroWithNullPtr.cpp
    ReplaceStringLiteralWithRawStringLiteral.cpp
    ReplaceTernaryWithIf.cpp
    ReplaceTypedefWithTypeAlias.cpp
    ReplaceTypeWithAuto.cpp
    ReverseConditional.cpp
    SimplifyBooleanExpression.cpp
    SplitInitializationFromDeclaration.cpp
    SplitMultiVariableDeclaration.cpp
    Config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/Config.h
)
source_group("Header Files" REGULAR_EXPRESSION ".*\\.h")
source_group("Source Files" REGULAR_EXPRESSION ".*\\.(cpp|c)")
source_group("CMake Template Files" REGULAR_EXPRESSION ".*\\.in")
if("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    add_library(refactor-14 OBJECT RenameCpp14.h RenameCpp14.cpp)
    set_target_properties(refactor-14 PROPERTIES
        FOLDER "Test Cases"
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON)
    target_link_libraries(refactor-test-cases PUBLIC refactor-14)
    set(HAVE_CPP14 ON)
endif()
if("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    add_library(refactor-17 OBJECT RenameCpp17.h RenameCpp17.cpp)
    set_target_properties(refactor-17 PROPERTIES
        FOLDER "Test Cases"
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)
    target_link_libraries(refactor-test-cases PUBLIC refactor-17)
    set(HAVE_CPP17 ON)
endif()
if("cxx_std_20" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    add_library(refactor-20 OBJECT
        RenameCpp20.h
        RenameCpp20.cpp
        RenameCpp20Concepts.cpp
        RenameCpp20Constraints.cpp
    )
    set_target_properties(refactor-20 PROPERTIES
        FOLDER "Test Cases"
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON)
    target_link_libraries(refactor-test-cases PUBLIC refactor-20)
    set(HAVE_CPP20 ON)
endif()
configure_file(Config.h.in include/Config.h)
set_target_properties(refactor-test-cases PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    FOLDER "Test Cases"
)
target_include_directories(refactor-test-cases PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_property(SOURCE ReplaceAutoPtrWithUniquePtr.cpp
        APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-declarations)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        set_property(SOURCE SplitMultiVariableDeclaration.cpp
            APPEND PROPERTY COMPILE_FLAGS -Wno-deprecated-register)
    endif()
elseif(MSVC)
    target_compile_definitions(refactor-test-cases PUBLIC _CRT_SECURE_NO_WARNINGS)
    set_property(SOURCE RenameCpp11.cpp
        APPEND PROPERTY COMPILE_FLAGS /wd4290)
endif()

add_executable(refactor-test-suite
    RefactorTest.h
    RefactorTest.cpp
)
set_target_properties(refactor-test-suite PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    FOLDER "Test Cases"
)
target_link_libraries(refactor-test-suite PUBLIC refactor-test-cases)
add_custom_command(TARGET refactor-test-suite POST_BUILD COMMAND refactor-test-suite)
add_custom_command(TARGET refactor-test-suite POST_BUILD COMMAND test-names -o "${CMAKE_BINARY_DIR}/Tool.md" ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command(TARGET refactor-test-suite POST_BUILD COMMAND test-diffs ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/results/diffs)
