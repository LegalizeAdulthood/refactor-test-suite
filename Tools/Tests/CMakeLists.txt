function(add_tool_test tool)
    cmake_parse_arguments(args "" "" "COMMAND;COMPARE_FILES;DELETED_FILES" ${ARGN})
    set(INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${tool}/Inputs)
    set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${tool}/Expected)
    set(TEST_DIR ${CMAKE_BINARY_DIR}/ToolTests/${tool})

    add_test(NAME test-${tool}-tool
        COMMAND ${CMAKE_COMMAND}
            -DCMAKE_COMMAND:STRING=${CMAKE_COMMAND}
            -DTEST_NAME:STRING=${tool}
            -DTEST_DIR:PATH=${TEST_DIR}
            -DINPUT_DIR:PATH=${INPUT_DIR}
            -DEXPECTED_DIR:PATH=${EXPECTED_DIR}
            -DTOOL_NAME:STRING=${tool}
            -DTOOL_COMMAND:PATH=$<TARGET_FILE:${tool}>
            "-DTOOL_ARGS:STRING=${args_COMMAND}"
            "-DCOMPARE_FILES:STRING=${args_COMPARE_FILES}"
            "-DDELETED_FILES:STRING=${args_DELETED_FILES}"
            -P ${CMAKE_CURRENT_SOURCE_DIR}/TestTool.cmake
    )
    set_property(TEST test-${tool}-tool PROPERTY LABELS ${tool} tool)
endfunction()

add_tool_test(add-tests
    COMMAND Sources R Sources/TestRename.cpp Results
    COMPARE_FILES
        Sources/TestRename.cpp
        Results/CLionResults.md
        Results/ReSharperCppResults.md
        Results/diffs/R1.txt
        Results/diffs/R2.txt
        Results/diffs/R3.txt
        Results/diffs/R4.txt
        Results/diffs/R5.txt
        Results/diffs/R6.txt
        Results/diffs/R7.txt
        Results/diffs/R8.txt
)
add_tool_test(delete-tests
    COMMAND Sources Results R 1-2,4
    COMPARE_FILES
        Sources/TestRename.cpp
        Results/CLionResults.md
        Results/ReSharperCppResults.md
        Results/diffs/R3.txt
        Results/diffs/R5.txt
        Results/diffs/R6.txt
        Results/diffs/R7.txt
        Results/diffs/R8.txt
    DELETED_FILES
        Results/diffs/R1.txt
        Results/diffs/R2.txt
        Results/diffs/R4.txt
)
add_tool_test(renumber-tests
    COMMAND Sources R Results
    COMPARE_FILES
        Sources/TestRename.cpp
        Results/CLionResults.md
        Results/ReSharperCppResults.md
        Results/diffs/R1.txt
        Results/diffs/R4.txt
        Results/diffs/R5.txt
        Results/diffs/R6.txt
        Results/diffs/R7.txt
        Results/diffs/R8.txt
)
