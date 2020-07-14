cmake_minimum_required(VERSION 3.10)
project(cache_efficient_code LANGUAGES CXX)

option(ENABLE_DEBUG "enable debugging" false)

include(Sanitizers.cmake)
#include(Assertions.cmake)

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

#set(ALWAYS_ENABLE_ASSERTIONS false)
#set(ALWAYS_ENABLE_ASSERTIONS false)

if (ENABLE_DEBUG)
	add_definitions("-DDEBUG_LEVEL=1")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU OR
  CMAKE_CXX_COMPILER_ID MATCHES Clang)
	add_compile_options("-pedantic-errors")
endif()

include_directories(include)

if (EXISTS ${CMAKE_SOURCE_DIR}/app/test_matrix_transpose.cpp OR
  EXISTS ${CMAKE_SOURCE_DIR}/app/test_matrix_multiply.cpp)
	set(LINALG_FOUND 1)
else()
	set(LINALG_FOUND 0)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/app/test_fft.cpp)
	set(FFT_FOUND 1)
else()
	set(FFT_FOUND 0)
endif()

if(LINALG_FOUND)
	add_executable(test_matrix_transpose app/test_matrix_transpose.cpp)
	add_executable(test_matrix_multiply app/test_matrix_multiply.cpp)
endif()

if(FFT_FOUND)
	add_executable(test_fft app/test_fft.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/app/trivial_matrix_transpose.cpp OR
  EXISTS ${CMAKE_SOURCE_DIR}/app/trivial_matrix_multiply.cpp OR
  EXISTS ${CMAKE_SOURCE_DIR}/app/demo_matrix_transpose.cpp OR
  EXISTS ${CMAKE_SOURCE_DIR}/app/demo_matrix_multiply.cpp)
	add_definitions("-DENABLE_EXTRAS")
	add_executable(trivial_matrix_transpose app/trivial_matrix_transpose.cpp)
	add_executable(trivial_matrix_multiply app/trivial_matrix_multiply.cpp)
	add_executable(demo_matrix_transpose app/demo_matrix_transpose.cpp)
	add_executable(demo_matrix_multiply app/demo_matrix_multiply.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/app/demo_fft.cpp)
	add_definitions("-DENABLE_EXTRAS")
	add_executable(trivial_fft app/trivial_fft.cpp)
	add_executable(demo_fft app/demo_fft.cpp)
	target_link_libraries(demo_fft fftw3)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/app/matrix_transpose.cpp OR
  EXISTS ${CMAKE_SOURCE_DIR}/app/matrix_multiply.cpp)
	include_directories(include)
	add_executable(matrix_transpose app/matrix_transpose.cpp)
	add_executable(matrix_multiply app/matrix_multiply.cpp)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/app/fft.cpp)
	include_directories(include)
	add_executable(fft app/fft.cpp)
	target_link_libraries(fft fftw3)
endif()

enable_testing()

