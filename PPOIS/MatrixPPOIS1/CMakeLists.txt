cmake_minimum_required(VERSION 3.27)
project(MatrixPPOIS1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(MatrixPPOIS1 main.cpp
        Matrix/Matrix.h
        Matrix/Matrix.cpp
)

add_subdirectory(googletest-main)
enable_testing()
include(GoogleTest)

add_subdirectory(Tests)
target_link_libraries(Tests GTest::gtest_main)

add_subdirectory(Matrix)
target_link_libraries(MatrixPPOIS1
        Matrix
)


