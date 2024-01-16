if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING add-tests requires C++17 support)
    return()
endif()

add_executable(add-tests AddTests.cpp)
set_target_properties(add-tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(add-tests PUBLIC test-cases)
