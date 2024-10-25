cmake_minimum_required(VERSION 3.29)
project(HW7)

enable_testing()

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(HW7 src/main.cpp
        src/vec.h)

add_executable(vec_tests test/vec_tests.cpp)

target_link_libraries(vec_tests gtest gtest_main)

add_test(NAME VecTests COMMAND vec_tests)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)