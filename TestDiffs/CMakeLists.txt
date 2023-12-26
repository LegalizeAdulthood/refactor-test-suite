if(NOT ("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING test-names requires C++17 support)
    return()
endif()

add_executable(test-diffs main.cpp)
set_target_properties(test-diffs PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
