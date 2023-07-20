cmake_minimum_required(VERSION 3.24)
project(stringhelpers)

add_library(${PROJECT_NAME} include/stringhelpers/stringhelpers.h)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(STRINGHELPERS_BUILD_TESTS "Build the test directory for stringhelpers" OFF)

if(STRINGHELPERS_BUILD_TESTS)
    add_subdirectory(tests)
endif()