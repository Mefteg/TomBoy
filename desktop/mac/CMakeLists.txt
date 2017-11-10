cmake_minimum_required(VERSION 3.10)

# Project's name
project(TomBoy)
set(EXECUTABLE_NAME "tomboy")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

# MicroProfile
set(MICROPROFILE_ENABLED OFF CACHE BOOL "Enable/Disable MicroProfile")
if(MICROPROFILE_ENABLED)
add_definitions(-DMICROPROFILE_GPU_TIMERS=0)
add_definitions(-DMICROPROFILE_ENABLED=1)
else()
add_definitions(-DMICROPROFILE_ENABLED=0)
endif()

# Sources & Headers
file(GLOB SOURCES
    ../*.cpp
)

file(GLOB_RECURSE SHARED_SOURCES
    ../../shared/*.cpp
)

file(GLOB HEADERS
    ../*.h
)

file(GLOB_RECURSE SHARED_HEADERS
    ../../shared/*.h
)

# Executable

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${SHARED_SOURCES} ${HEADERS} ${SHARED_HEADERS})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
