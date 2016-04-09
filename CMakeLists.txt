cmake_minimum_required(VERSION 3.4)
project(caesar_shift)

include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(GTEST_ROOT ${CONAN_GTEST_ROOT})

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(caesar_shift ${SOURCE_FILES})
target_link_libraries(caesar_shift ${GTEST_BOTH_LIBRARIES})
