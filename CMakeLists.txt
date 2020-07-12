include(Sanitizers.cmake)

# Specify Minimum Required Version
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Specify Project and Language
project(cpp_cache LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

# Set Include Directory
include_directories(include)

# Add Executable Program
add_executable(test_matrix_transpose app/test_matrix_transpose.cpp)
