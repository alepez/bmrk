cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

set(PRJ_NAME bmrk)
set(PRJ_TYPE_EXECUTABLE 1)
set(PRJ_BUILD_LIBRARY 1)
set(LINK_LIBS "")
set(CXXFLAGS "-std=c++11")

link_directories("deps/root/lib")
include_directories("deps/root/include")

project(${PRJ_NAME})

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
