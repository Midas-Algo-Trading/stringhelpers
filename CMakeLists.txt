cmake_minimum_required(VERSION 3.24)
project(stringhelpers)

add_library(${PROJECT_NAME} include/stringhelpers/StringHelpers.h)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME} PUBLIC include)

option(BUILD_TESTS "Build the test directory" OFF)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()