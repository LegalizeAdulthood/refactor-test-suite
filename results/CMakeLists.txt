if(NOT BUILD_TESTING)
    return()
endif()

function(check_results tool)
    add_test(NAME check-${tool}-results
        COMMAND test-results ${CMAKE_SOURCE_DIR}/RefactorTest ${CMAKE_CURRENT_SOURCE_DIR}/${tool}Results.md)
endfunction()

foreach(result
        ClangTidy
        CLion
        ReSharperCpp
        VisualAssistX
        VisualStudio
        )
    check_results(${result})
endforeach()

add_subdirectory(preliminary)
