cmake_minimum_required(VERSION 3.24)
project(StringHelpers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(StringHelpersLib StringHelpers.cpp test/test.cpp)

add_executable(exec main.cpp)
target_link_libraries(exec StringHelpersLib)
add_subdirectory(test)
