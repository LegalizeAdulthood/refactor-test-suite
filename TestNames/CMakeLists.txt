if(NOT ("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING test-names requires C++17 support)
    return()
endif()

add_executable(test-names TestNames.cpp)
set_target_properties(test-names PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
