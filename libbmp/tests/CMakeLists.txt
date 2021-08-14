set(BMPLIB_UNIT_TESTS_DIR   ${BMPLIB_TESTS_DIR}/unit_tests)
set(BMPLIB_MODULE_TESTS_DIR ${BMPLIB_TESTS_DIR}/module_tests)

add_subdirectory(${BMPLIB_UNIT_TESTS_DIR})
add_subdirectory(${BMPLIB_MODULE_TESTS_DIR})
