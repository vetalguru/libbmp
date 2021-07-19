cmake_minimum_required(VERSION ${CMAKE_MIN_REQ_VERSION})

project(bmp)

set(BMPLIB_INCLUDE_DIR ${BMPLIB_ROOT_DIR}/include)
set(BMPLIB_SOURCES_DIR ${BMPLIB_ROOT_DIR}/src)
set(BMPLIB_TESTS_DIR   ${BMPLIB_ROOT_DIR}/tests)

set(INCLUDES ${BMPLIB_INCLUDE_DIR}/foo.hpp)

set(SOURCES ${BMPLIB_SOURCES_DIR}/foo.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

target_include_directories(${PROJECT_NAME} PUBLIC ${BMPLIB_INCLUDE_DIR})

add_subdirectory(${BMPLIB_TESTS_DIR})
