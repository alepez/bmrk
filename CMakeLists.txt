cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

set(PRJ_NAME bmrk)

project(${PRJ_NAME})

set(PRJ_TYPE_EXECUTABLE 1)
set(PRJ_BUILD_LIBRARY 1)

set(LINK_LIBS  "gumbo_query_static" "gumbo")
set(CXXFLAGS "-std=c++11")

link_directories("deps/root/lib")
include_directories("deps/root/include")

add_subdirectory(src)
add_subdirectory(test)
