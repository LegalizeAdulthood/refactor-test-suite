function(add_tool_test tool)
    set(INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${tool}/Inputs)
    set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${tool}/Expected)

    add_test(NAME test-${tool}-tool
        COMMAND ${CMAKE_COMMAND}
            -DCMAKE_COMMAND:STRING=${CMAKE_COMMAND}
            -DTEST_NAME:STRING=${tool}
            -DTEST_DIR:PATH=${CMAKE_BINARY_DIR}/ToolTests/${tool}
            -DINPUT_DIR:PATH=${INPUT_DIR}
            -DEXPECTED_DIR:PATH=${EXPECTED_DIR}
            -DTOOL_NAME:STRING=${tool}
            -DTOOL_COMMAND:PATH=$<TARGET_FILE:${tool}>
            -P ${CMAKE_CURRENT_SOURCE_DIR}/TestTool.cmake
    )
    set_property(TEST test-${tool}-tool PROPERTY LABELS ${tool} tool)
endfunction()

add_tool_test(add-tests)
#add_tool_test(renumber-tests)
