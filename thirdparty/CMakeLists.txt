cmake_minimum_required(VERSION 3.5)

add_subdirectory(${THIRDPARTY_ROOT_DIR}/googletest)

add_subdirectory(${THIRDPARTY_ROOT_DIR}/zlib)
set(ENV{ZLIBLIB} "${CMAKE_BINARY_DIR}/thirdparty/zlib")
set(ENV{ZLIBINC} "${THIRDPARTY_ROOT_DIR}/zlib")
set(ENV{CPPFLAGS} "-I$ZLIBINC")
set(ENV{LDFLAGS} "-L$ZLIBLIB")
set(ENV{LD_LIBRARY_PATH} "$ZLIBLIB:$LD_LIBRARY_PATH")

add_subdirectory(${THIRDPARTY_ROOT_DIR}/libpng)

