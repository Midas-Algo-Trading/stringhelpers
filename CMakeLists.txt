cmake_minimum_required(VERSION 3.24)
project(stringhelpers)

include_directories(include)

option(STRINGHELPERS_BUILD_TESTS "Build the test directory for stringhelpers" OFF)

if(STRINGHELPERS_BUILD_TESTS)
    add_subdirectory(tests)
endif()