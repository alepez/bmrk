cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)
SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

set(PRJ_NAME bmrk)

project(${PRJ_NAME})

set(PRJ_BUILD_EXECUTABLE 1)
set(PRJ_BUILD_STATIC_LIBRARY 1)
set(PRJ_BUILD_SHARED_LIBRARY 0)

set(TEST_COVERAGE 0)

set(CXXFLAGS "-std=c++11")

# How to find third party libraries
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/root)
include_directories("deps/root/include")

# Libraries
find_library(GUMBO libgumbo.a)
find_library(GUMBO_QUERY libgumbo_query_static.a)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

set(LINK_LIBS
	${GUMBO_QUERY}
	${GUMBO}
	${CURL_LIBRARIES}
	${OPENSSL_LIBRARIES}
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
)

# Subdirectories
add_subdirectory(src/lib)
add_subdirectory(test/lib)

add_subdirectory(src/cli)
# FIXME add_subdirectory(test/cli)

# This is needed to run tests with `make test`
enable_testing()
