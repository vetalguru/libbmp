cmake_minimum_required(VERSION ${CMAKE_MIN_REQ_VERSION})

project(libbmp_unit_tests)

enable_testing()

set(BMP_UT_LIST ${BMPLIB_UNIT_TESTS_DIR}/ut_foo_tests.cpp)

add_executable(${PROJECT_NAME} ${BMP_UT_LIST})
target_link_libraries(${PROJECT_NAME} gtest_main bmp)

target_include_directories(${PROJECT_NAME} PRIVATE ${BMPLIB_INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME} ${BMP_UT_LIST})
