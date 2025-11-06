cmake_minimum_required(VERSION 3.27)
project(VectorPPOIS1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(VectorPPOIS1 main.cpp
        Vector/Vector.h
        Vector/Vector.cpp
)

add_subdirectory(googletest-main)
enable_testing()
include(GoogleTest)

add_subdirectory(Tests)
target_link_libraries(Tests GTest::gtest_main)

add_subdirectory(Vector)
target_link_libraries(VectorPPOIS1
        Vector
)


