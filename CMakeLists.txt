cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)
add_definitions(-pthread)

# project name
set(NextQuery NextQuery)

# set project name
project(${NextQuery} C CXX)

#set compiler version
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-Wall -std=c++17 -pthread")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

# set version number
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${CMAKE_SOURCE_DIR}/config/AppConfig.h.in"
        "${CMAKE_SOURCE_DIR}/config/AppConfig.h"
)

# set bin location
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# set location of executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# set libraries output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add source dir
add_subdirectory(src)

file(GLOB PROJECT_SRCS src/*.cpp)

# add curlpp dir
add_subdirectory(curlpp)

file(GLOB CURLPP_SRCS curlpp/src/**.cpp)

# add google test source dir
add_subdirectory(googletest)

# add src folder for tests
add_subdirectory(test)

enable_testing()

add_executable(${NextQuery} ${CURLPP_SRCS} ${PROJECT_SRCS})

target_link_libraries(${NextQuery} curlpp)
target_link_libraries(${NextQuery} pthread)