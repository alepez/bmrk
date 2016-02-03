file(GLOB_RECURSE SOURCES *.cpp)

add_definitions("${CXXFLAGS}")
include_directories(".")

if(${PRJ_BUILD_STATIC_LIBRARY})
  add_library(${PRJ_NAME}-static STATIC ${SOURCES})
endif()

if(${PRJ_BUILD_SHARED_LIBRARY})
  add_library(${PRJ_NAME}-shared SHARED ${SOURCES})
endif()

if(${TEST_COVERAGE})
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PRJ_NAME}-static PRIVATE ${TEST_COVERAGE_COMPILE_OPTIONS})
  else()
    message(WARNING "Clang is needed for test coverage.")
  endif()
endif()
