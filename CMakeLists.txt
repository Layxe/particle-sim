cmake_minimum_required (VERSION 3.21)
project (framework)

set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Our project name

set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/SDL2")
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/lib/x64/SDL2.lib;${CMAKE_SOURCE_DIR}/lib/x64/SDL2main.lib")

file(GLOB_RECURSE SOURCE_FILES 
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES 
    ${CMAKE_SOURCE_DIR}/include/*.h
    ${CMAKE_SOURCE_DIR}/include/*.hpp)

add_executable(framework ${SOURCE_FILES} ${HEADER_FILES})

# Including our external library's directory for header files!
include_directories(
    "${SDL2_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include/"
    "${CMAKE_SOURCE_DIR}/src"
)

# Copy dll files to the build directory
file(COPY ${PROJECT_SOURCE_DIR}/dll/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR}/Debug)

# Linking SDL2 library with our project.
target_link_libraries(framework ${SDL2_LIBRARY})