if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING renumber-tests requires C++17 support)
    return()
endif()

add_executable(renumber-tests RenumberTests.cpp)
set_target_properties(renumber-tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(renumber-tests PUBLIC test-cases)
