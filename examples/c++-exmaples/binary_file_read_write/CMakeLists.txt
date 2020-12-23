cmake_minimum_required(VERSION 3.5)
project(binary_file_read_write)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB_RECURSE HDR_FILE ${CMAKE_CURRENT_LIST_DIR}/include/*h)
file(GLOB_RECURSE SRC_FILE ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(binary_file_write binary_file_write.cpp ${SRC_FILE} ${HDR_FILE})
add_executable(binary_file_read binary_file_read.cpp ${SRC_FILE} ${HDR_FILE})
add_executable(image_binary_read_write image_binary_read_write.cpp ${SRC_FILE} ${HDR_FILE})
target_link_libraries(image_binary_read_write ${OpenCV_LIBRARIES})