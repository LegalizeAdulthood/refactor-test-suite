if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING add-test-alias requires C++17 support)
    return()
endif()

add_executable(add-test-alias AddTestAlias.cpp)
set_target_properties(add-test-alias PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(add-test-alias PUBLIC test-cases)

