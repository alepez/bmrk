cmake_minimum_required(VERSION 2.6)

set(PRJ_NAME bmrk)
set(PRJ_TYPE_EXECUTABLE 1)
set(PRJ_BUILD_LIBRARY 1)
set(LINK_LIBS "")
set(CXXFLAGS "")
set(INCLUDE_DIR )

project(${PRJ_NAME})

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
