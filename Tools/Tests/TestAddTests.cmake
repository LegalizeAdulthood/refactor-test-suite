set(TEST_DIR "${TEST_DIR}/${TEST_NAME}")

# copy INPUT_DIR contents to TEST_DIR
file(COPY ${INPUT_DIR}/Sources DESTINATION ${TEST_DIR})
file(COPY ${INPUT_DIR}/Results DESTINATION ${TEST_DIR})

# run tool
execute_process(
    COMMAND ${TOOL} ${TEST_DIR}/Sources R ${TEST_DIR}/Sources/TestRename.cpp ${TEST_DIR}/Results
)

# compare TEST_DIR contents to EXPECTED_DIR
function(compare_file relativePath)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E compare_files
            ${TEST_DIR}/${relativePath} ${EXPECTED_DIR}/${relativePath}
        RESULT_VARIABLE difference
    )
    if(difference EQUAL 0)
        message(STATUS "${TEST_DIR}/${relativePath} ${EXPECTED_DIR}/${relativePath} are equal")
    elseif(difference EQUAL 1)
        message(STATUS "${TEST_DIR}/${relativePath}:")
        execute_process(COMMAND ${CMAKE_COMMAND} -E cat "${TEST_DIR}/${relativePath}")
        message(STATUS "${EXPECTED_DIR}/${relativePath}:")
        execute_process(COMMAND ${CMAKE_COMMAND} -E cat "${EXPECTED_DIR}/${relativePath}")
        message(FATAL_ERROR "${TEST_DIR}/${relativePath} ${EXPECTED_DIR}/${relativePath} are different")
    else()
        message(FATAL_ERROR "Error while comparing ${TEST_DIR}/${relativePath} ${EXPECTED_DIR}/${relativePath}")
    endif()
endfunction()

compare_file(Sources/TestRename.cpp)
compare_file(Results/CLionResults.md)
compare_file(Results/ReSharperCppResults.md)
foreach(case RANGE 1 8)
    compare_file(Results/diffs/R${case}.txt)
endforeach()
