file(GLOB TEST_SOURCES *.cpp)

enable_testing()

add_executable(unit_tests ${TEST_SOURCES})

add_test(unit_tests unit_tests)

add_definitions("${CXXFLAGS}")

include_directories(. ../src)
include_directories(${INCLUDE_DIR})

link_libraries("${LINK_LIBS}")
link_libraries("${PRJ_NAME}-static")

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES})
