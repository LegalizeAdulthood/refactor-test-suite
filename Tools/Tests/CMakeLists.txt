set(INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Inputs)
set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Expected)
add_test(NAME test-add-tests-tool
    COMMAND ${CMAKE_COMMAND}
        -DCMAKE_COMMAND:STRING=${CMAKE_COMMAND}
        -DTEST_NAME:STRING=add-tests
        -DTEST_DIR:STRING=${CMAKE_BINARY_DIR}/ToolTests
        -DINPUT_DIR:STRING=${INPUT_DIR}
        -DEXPECTED_DIR:STRING=${EXPECTED_DIR}
        -DTOOL=$<TARGET_FILE:add-tests>
        -P ${CMAKE_CURRENT_SOURCE_DIR}/TestAddTests.cmake
)
set_tests_properties(test-add-tests-tool PROPERTIES LABELS add-tests)
