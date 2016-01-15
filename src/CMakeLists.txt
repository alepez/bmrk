file(GLOB_RECURSE SOURCES *.cpp)

add_definitions("${CXXFLAGS}")
include_directories(".")

# Executable
if(${PRJ_BUILD_EXECUTABLE})
  add_executable(${PRJ_NAME} ${SOURCES})
endif()

target_link_libraries(${PRJ_NAME} ${LINK_LIBS})

# Library

# Exclude main.cpp
foreach(filename ${SOURCES})
  if("${filename}" MATCHES "main.cpp")
    list(REMOVE_ITEM SOURCES "${filename}")
  endif()
endforeach()

if(${PRJ_BUILD_STATIC_LIBRARY})
  add_library(${PRJ_NAME}-static STATIC ${SOURCES})
endif()

if(${PRJ_BUILD_SHARED_LIBRARY})
  add_library(${PRJ_NAME}-shared SHARED ${SOURCES})
endif()
