if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING test-results requires C++17 support)
    return()
endif()

add_executable(test-results TestResults.cpp)
set_target_properties(test-results PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(test-results PUBLIC test-cases)
