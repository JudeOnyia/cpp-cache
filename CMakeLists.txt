# Specify Minimum Required Version
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Specify Project and Language
project(cpp_cache LANGUAGES CXX)

# Set Include Directory
include_directories(include)

# Add Executable Program
add_executable(test_matrix_transpose app/test_matrix_transpose.cpp)
add_executable(test_matrix_multiply app/test_matrix_multiply.cpp)
add_executable(test_fft app/test_fft.cpp)
