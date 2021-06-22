cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME sample)

set(SOURCES ${SAMPLE_ROOT_DIR}/main.cpp)
add_executable(sample ${SOURCES})

include_directories(${BMPLIB_ROOT_DIR})
target_link_libraries(${PROJECT_NAME} bmp)
