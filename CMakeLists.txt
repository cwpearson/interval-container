cmake_minimum_required(VERSION 2.4)
project(interval_container)

set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wshadow -pedantic ${CMAKE_CXX_FLAGS}")

include_directories(include)
add_subdirectory(tests)