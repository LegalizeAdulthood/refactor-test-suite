cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)
project(refactor-test-suite)
include(CTest)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT refactor-test-suite)

add_subdirectory(RefactorTest)
add_subdirectory(results)
add_subdirectory(Tools)
