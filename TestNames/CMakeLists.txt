if(NOT ("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING test-names requires C++17 support)
    return()
endif()

add_executable(test-names main.cpp)
set_target_properties(test-names PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
add_custom_command(TARGET test-names POST_BUILD COMMAND test-names ${CMAKE_CURRENT_SOURCE_DIR}/../RefactorTest > ${CMAKE_CURRENT_BINARY_DIR}/Tool.md)
