set(DEBUG ON)
if(DEBUG)
    function(dump_var var)
        message(STATUS "${var}=${${var}}")
    endfunction()
    foreach(var 
        CMAKE_COMMAND
        TEST_NAME
        TEST_DIR
        INPUT_DIR
        EXPECTED_DIR
        TOOL_NAME
        TOOL_COMMAND
        TOOL_ARGS
        )
        dump_var(${var})
    endforeach()
endif()

function(copy_input_subdir subdir)
    if(DEBUG)
        message(STATUS "copy_input_subdir ${subdir} COPY ${INPUT_DIR}/${subdir} DESTINATION ${TEST_DIR})")
    endif()
    if(EXISTS ${INPUT_DIR}/${subdir})
        file(COPY ${INPUT_DIR}/${subdir} DESTINATION ${TEST_DIR})
    endif()
endfunction()

# Delete any existing files in TEST_DIR
file(REMOVE_RECURSE ${TEST_DIR})

# copy INPUT_DIR contents to TEST_DIR
copy_input_subdir(Sources)
copy_input_subdir(Results)

# run tool
if(DEBUG)
    message(STATUS "execute_process COMMAND ${TOOL_COMMAND} ${TOOL_ARGS}")
endif()
execute_process(COMMAND ${TOOL_COMMAND} ${TOOL_ARGS}
    WORKING_DIRECTORY ${TEST_DIR}
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
