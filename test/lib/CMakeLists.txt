file(GLOB TEST_SOURCES *.cpp)

add_executable(unit_tests ${TEST_SOURCES})
add_test(unit_tests unit_tests)

set(CXXFLAGS "${CXXFLAGS} -pthread -std=c++11")

add_definitions("${CXXFLAGS}")

include_directories("." "../../src/lib")

target_link_libraries(unit_tests "${PRJ_NAME}-static" ${LINK_LIBS})
target_link_libraries(unit_tests ${LINK_LIBS})

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES})

# This is needed to build tests
enable_testing()
