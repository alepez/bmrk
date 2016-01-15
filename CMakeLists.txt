cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

set(PRJ_NAME bmrk)

project(${PRJ_NAME})

set(PRJ_BUILD_EXECUTABLE 1)
set(PRJ_BUILD_STATIC_LIBRARY 1)
set(PRJ_BUILD_SHARED_LIBRARY 1)

set(CXXFLAGS "-std=c++11")

# How to find third party libraries
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/root)
include_directories("deps/root/include")

# Libraries
find_library(GUMBO libgumbo.a)
find_library(GUMBO_QUERY libgumbo_query_static.a)
set(LINK_LIBS ${GUMBO_QUERY} ${GUMBO})

# Subdirectories
add_subdirectory(src)
add_subdirectory(test)
