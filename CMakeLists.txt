cmake_minimum_required(VERSION 3.24)
project(StringHelpers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(StringHelpers include/StringHelpers/StringHelpers.h)
set_target_properties(StringHelpers PROPERTIES LINKER_LANGUAGE CXX)

include_directories(include)

add_subdirectory(test)