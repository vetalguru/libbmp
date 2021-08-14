cmake_minimum_required(VERSION ${CMAKE_MIN_REQ_VERSION})

project(libbmp_module_tests)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()

set(BMP_MODULE_TESTS_LIST ${BMPLIB_MODULE_TESTS_DIR}/mt_simple_2x2_24bit_bmp.cpp)

add_executable(${PROJECT_NAME} ${BMP_MODULE_TESTS_LIST})
target_link_libraries(${PROJECT_NAME} gtest_main bmp)

target_include_directories(${PROJECT_NAME} PRIVATE ${BMPLIB_INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME} ${BMP_MODULE_TESTS_LIST})
