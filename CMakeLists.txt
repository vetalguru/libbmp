cmake_minimum_required(VERSION 3.5)

project(bmpdecoder)

set(SOLUTION_ROOT_DIR   ${CMAKE_CURRENT_SOURCE_DIR})
set(SAMPLE_ROOT_DIR     ${SOLUTION_ROOT_DIR}/sample)
set(BMPLIB_ROOT_DIR     ${SOLUTION_ROOT_DIR}/libbmp)
set(THIRDPARTY_ROOT_DIR ${SOLUTION_ROOT_DIR}/thirdparty)

add_subdirectory(${BMPLIB_ROOT_DIR})
add_subdirectory(${SAMPLE_ROOT_DIR})
add_subdirectory(${THIRDPARTY_ROOT_DIR})
