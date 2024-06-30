cmake_minimum_required(VERSION 3.28)
project(stringhelpers CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(stringhelpers INTERFACE include)

target_include_directories(stringhelpers INTERFACE include)

set_target_properties(stringhelpers PROPERTIES LINKER_LANGUAGE CXX)

include_directories(include)

option(STRINGHELPERS_BUILD_TESTS "Build tests" OFF)
if (STRINGHELPERS_BUILD_TESTS)
    add_subdirectory(tests)
endif()