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
  target_compile_options(${PRJ_NAME}-static PRIVATE "--coverage" "-g" "-O0")
endif()
