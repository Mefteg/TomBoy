cmake_minimum_required(VERSION 3.10)

# Project's name
project(TomBoy)

set(EXECUTABLE_NAME "tomboy")

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

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
