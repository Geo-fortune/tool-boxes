cmake_minimum_required(VERSION 3.5)
project(stl_algorithm_example)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB_RECURSE HDR_FILE ${CMAKE_CURRENT_LIST_DIR}/include/*h)
file(GLOB_RECURSE SRC_FILE ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(stl_algorithm main.cpp ${SRC_FILE} ${HDR_FILE})