# require the minimum version of cmake to be 3.12
cmake_minimum_required(VERSION 3.12)

# find all sources in the test
file(GLOB_RECURSE MOLOG_TEST_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp")

# add the executable and link it
add_executable(MologTest ${MOLOG_TEST_SOURCE_FILES})
target_link_libraries(MologTest
    gtest_main
    Molog
)

# add the test
include(GoogleTest)
gtest_discover_tests(MologTest)
add_test(NAME Molog COMMAND MologTest)