cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

# set project name
project(NextQuery CXX)

#set compiler version
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-Wall")
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

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add source dir
add_subdirectory(src)

# add google test source dir
add_subdirectory(googletest)

# add src folder for tests
add_subdirectory(test)

# addd curl


enable_testing()

add_executable(NextQuery src/NextQuery.cpp)