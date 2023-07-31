cmake_minimum_required(VERSION 3.24)
project(stringhelpers)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} include/stringhelpers/stringhelpers.h include/stringhelpers/cpp_file.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(STRINGHELPERS_BUILD_TESTS "Build the test directory for stringhelpers" OFF)

if(STRINGHELPERS_BUILD_TESTS)
    add_subdirectory(tests)
endif()