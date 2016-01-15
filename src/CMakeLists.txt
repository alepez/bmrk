file(GLOB_RECURSE SOURCES *.cpp)

if(${PRJ_TYPE_EXECUTABLE})
  add_executable(${PRJ_NAME} ${SOURCES})
endif()

add_definitions("${CXXFLAGS}")

include_directories(".")

target_link_libraries(${PRJ_NAME} "gumbo_query_static" "gumbo")

foreach(filename ${SOURCES})
  if(NOT "${filename}" MATCHES "main.cpp")
    list(APPEND OBJECTS ${filename})
  endif()
endforeach()

if(${PRJ_BUILD_LIBRARY})
  add_library(${PRJ_NAME}-static STATIC ${OBJECTS})
  add_library(${PRJ_NAME}-shared SHARED ${OBJECTS})
endif()
