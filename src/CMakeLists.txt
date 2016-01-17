file(GLOB_RECURSE SOURCES *.cpp)

add_definitions("${CXXFLAGS}")
include_directories(".")

# Executable
if(${PRJ_BUILD_EXECUTABLE})
  add_executable(${PRJ_NAME} ${SOURCES})
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

target_link_libraries(${PRJ_NAME}
  ${LINK_LIBS}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
)

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
