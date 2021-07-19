set(CMAKE_MIN_REQ_VERSION 3.5)

cmake_minimum_required(VERSION ${CMAKE_MIN_REQ_VERSION})

project(bmpdecoder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOLUTION_ROOT_DIR   ${CMAKE_CURRENT_SOURCE_DIR})
set(SAMPLE_ROOT_DIR     ${SOLUTION_ROOT_DIR}/sample)
set(BMPLIB_ROOT_DIR     ${SOLUTION_ROOT_DIR}/libbmp)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(compiler_flags)
include(googletest)

add_subdirectory(${BMPLIB_ROOT_DIR})
add_subdirectory(${SAMPLE_ROOT_DIR})
