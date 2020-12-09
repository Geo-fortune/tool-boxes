include_directories("/usr/include/jsoncpp")
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
# include headers and source files
FILE(GLOB_RECURSE HDR_FILES ${CMAKE_CURRENT_LIST_DIR}/include/*.h)
FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

add_executable(open3DViewer main.cpp ${SRC_FILES})
target_link_libraries(open3DViewer ${Open3D_LIBRARIES} pthread)
