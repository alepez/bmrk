file(GLOB TEST_SOURCES *.cpp)

enable_testing()

add_executable(unit_tests ${TEST_SOURCES})

add_test(unit_tests unit_tests)

add_definitions("${CXXFLAGS}")

include_directories("." "../src")

target_link_libraries(unit_tests "${PRJ_NAME}-static")
target_link_libraries(unit_tests "gumbo_query_static" "gumbo")

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES})
