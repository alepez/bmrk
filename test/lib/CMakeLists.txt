file(GLOB TEST_SOURCES *.cpp)

add_executable(unit_tests ${TEST_SOURCES})
add_test(unit_tests unit_tests)

add_definitions("${CXXFLAGS}")

include_directories("." "../../src/lib")

target_link_libraries(unit_tests "${PRJ_NAME}-static" ${LINK_LIBS})
target_link_libraries(unit_tests ${LINK_LIBS})

if(${TEST_COVERAGE})
  target_compile_options(unit_tests PRIVATE "-fcoverage-mapping")
  target_compile_options(unit_tests PRIVATE "-fprofile-instr-generate")
  target_link_libraries(unit_tests "-fcoverage-mapping")
  target_link_libraries(unit_tests "-fprofile-instr-generate")
endif()

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES} "pthread")

# This is needed to build tests
enable_testing()
