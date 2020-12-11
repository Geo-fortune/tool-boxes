cmake_minimum_required(VERSION 3.5)
project(shared_memory_example)

find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB_RECURSE HDR_FILE ${CMAKE_CURRENT_LIST_DIR}/include/*h)
file(GLOB_RECURSE SRC_FILE ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(video_reader video_reader.cpp ${SRC_FILE} ${HDR_FILE})
add_executable(video_writer video_writer.cpp ${SRC_FILE} ${HDR_FILE})
target_link_libraries(video_reader ${OpenCV_LIBRARIES})
target_link_libraries(video_writer ${OpenCV_LIBRARIES})