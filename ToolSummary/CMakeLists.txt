if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING tool-summary requires C++17 support)
    return()
endif()

add_executable(tool-summary ToolSummary.cpp)
set_target_properties(tool-summary PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(tool-summary PUBLIC test-cases)
