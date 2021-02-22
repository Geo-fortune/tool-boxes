
cmake_minimum_required(VERSION 2.8)

project(ins_singleton_example)

set (ADMAKE_NEED_EXCEPTION 1)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
ADD_COMPILE_OPTIONS(-std=c++11 -O3 -Wall -Wunused-variable)

if (NOT DEFINED CMAKE_MODULE_PATH)
    set (CMAKE_MODULE_PATH "$ENV{AD_TOOLS}/cmake")
endif ()

include (CMakeListsPub)
set (TARGET_NAME ${CMAKE_PROJECT_NAME}${SUFFIX_STR})

append_3rd_modules (lcm)
 
set(SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source )
set(HDRS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${HDRS_DIR})

file(GLOB_RECURSE SRCS_FILES ${SRCS_DIR}/*.cpp)

# add executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${SRCS_FILES})
target_link_libraries(${PROJECT_NAME}  ${LCM_LIB}  
                                       pthread )



