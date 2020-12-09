cmake_minimum_required(VERSION 3.5)
project(open3d_visulization_example)

#find open3d
find_package(Open3D REQUIRED)
include_directories(${Open3D_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(visualization)
add_subdirectory(open3d-viewer)