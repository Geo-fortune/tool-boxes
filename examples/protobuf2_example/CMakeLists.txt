cmake_minimum_required( VERSION 2.8)
project(protobuf2-example)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-g)
ADD_COMPILE_OPTIONS(-std=c++11 -O3 -Wall -Wunused-variable)

# OpenCV -- 
# set(OpenCV_DIR "/usr/local/share/OpenCV")
find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#BOOST
find_package(Boost REQUIRED filesystem date_time)
include_directories(${Boost_INCLUDE_DIRS})

#protobuf
find_package(Protobuf 2 REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

#SRC FILES 
file(GLOB_RECURSE SRC_LIST
    "${CMAKE_CURRENT_LIST_DIR}/source/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/*.cc"
    "${CMAKE_CURRENT_LIST_DIR}/protos/*.cc")

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/proto)

# add executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}
                                      ${Boost_LIBRARIES}
                                      ${PROTOBUF_LIBRARIES}
                                      )

