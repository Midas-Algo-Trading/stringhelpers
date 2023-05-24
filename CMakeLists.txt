# CMakeLists.txt in the StringHelpers directory

# Create the library target
add_library(StringHelpersLib STATIC StringHelpers.h)

set_target_properties(StringHelpersLib PROPERTIES LINKER_LANGUAGE CXX)

# Set the include directory for the library
target_include_directories(StringHelpersLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(test)