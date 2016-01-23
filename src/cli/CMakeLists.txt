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
  target_compile_options(${PRJ_NAME} PRIVATE "-fcoverage-mapping")
  target_compile_options(${PRJ_NAME} PRIVATE "-fprofile-instr-generate")
  target_link_libraries(${PRJ_NAME} "-fcoverage-mapping")
  target_link_libraries(${PRJ_NAME} "-fprofile-instr-generate")
endif()
