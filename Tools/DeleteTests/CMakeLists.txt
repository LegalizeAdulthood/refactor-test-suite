if(NOT ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES))
    message(WARNING delete-tests requires C++17 support)
    return()
endif()

add_executable(delete-tests DeleteTests.cpp)
set_target_properties(delete-tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    FOLDER Tools
)
target_link_libraries(delete-tests PUBLIC test-cases)

