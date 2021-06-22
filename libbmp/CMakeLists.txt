cmake_minimum_required(VERSION 3.5)


set(INCLUDES ${BMPLIB_ROOT_DIR}/foo.hpp)
set(SOURCES ${BMPLIB_ROOT_DIR}/foo.cpp)

add_library(bmp ${SOURCES} ${INCLUDES})
