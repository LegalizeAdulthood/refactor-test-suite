if(NOT BUILD_TESTING)
    return()
endif()

foreach(result 
        #AppleXcode
        ClangTidy
        #CLion
        #EclipseCDT
        #QtCreator
        ReSharperCpp
        VisualAssistX
        VisualStudio
        )
    add_test(NAME check-${result}-results
        COMMAND test-results ${CMAKE_SOURCE_DIR}/RefactorTest ${CMAKE_CURRENT_SOURCE_DIR}/${result}Results.md
    )
endforeach()
