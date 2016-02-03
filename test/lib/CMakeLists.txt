file(GLOB TEST_SOURCES *.cpp)

add_executable(unit_tests ${TEST_SOURCES})
add_test(unit_tests unit_tests)

add_definitions("${CXXFLAGS}")

include_directories("." "../../src/lib")

target_link_libraries(unit_tests "${PRJ_NAME}-static" ${LINK_LIBS})
target_link_libraries(unit_tests ${LINK_LIBS})

if(${TEST_COVERAGE})
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(unit_tests PRIVATE ${TEST_COVERAGE_COMPILE_OPTIONS})
    target_link_libraries(unit_tests ${TEST_COVERAGE_LINKER_OPTIONS})
  else()
    message(WARNING "Clang is needed for test coverage.")
  endif()
endif()

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES} "pthread")

# This is needed to build tests
enable_testing()
