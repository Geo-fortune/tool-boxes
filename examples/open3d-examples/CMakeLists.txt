cmake_minimum_required(VERSION 3.5)
project(open3d_visulization_example)

#find open3d
find_package(Open3D REQUIRED)
include_directories(${Open3D_INCLUDE_DIRS})

# include headers and source files
FILE(GLOB_RECURSE HDR_FILES ${CMAKE_CURRENT_LIST_DIR}/include/*.h)
FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_subdirectory(visualization)