file(GLOB_RECURSE SOURCES *.cpp)

add_definitions("${CXXFLAGS}")
include_directories(".")

if(${PRJ_BUILD_EXECUTABLE})
  add_executable(${PRJ_NAME} ${SOURCES})
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

target_link_libraries(${PRJ_NAME}
  ${PRJ_NAME}-static
  ${LINK_LIBS}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
)

if(${TEST_COVERAGE})
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PRJ_NAME} PRIVATE ${TEST_COVERAGE_COMPILE_OPTIONS})
    target_link_libraries(${PRJ_NAME} ${TEST_COVERAGE_LINKER_OPTIONS})
  else()
    message(WARNING "Clang is needed for test coverage.")
  endif()
endif()
