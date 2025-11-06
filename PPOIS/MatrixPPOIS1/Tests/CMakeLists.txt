project(Tests)

add_executable(Tests
        test.cpp
)

target_include_directories(Tests PRIVATE
        ${CMAKE_SOURCE_DIR}/Matrix
)

target_link_libraries(Tests
        Matrix
)

include(GoogleTest)
gtest_discover_tests(Tests)