

cmake_minimum_required( VERSION 3.5)
project(gtest_example)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
# adtools

set (ADMAKE_NEED_EXCEPTION 1)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")

add_compile_options(-g)

if (NOT DEFINED CMAKE_MODULE_PATH)
    set (CMAKE_MODULE_PATH "$ENV{AD_TOOLS}/cmake")
endif ()

include (CMakeListsPub)
set (TARGET_NAME ${CMAKE_PROJECT_NAME}${SUFFIX_STR})

append_3rd_modules (gtest)
# normal

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})


set(SRCS_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(HDRS_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

FILE(GLOB_RECURSE SRCS_FILES ${SRCS_DIR}/*.cpp)
FILE(GLOB_RECURSE HDRS_FILES ${HDRS_DIR}/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
add_library(myClassA SHARED ${SRCS_FILES})
# target_link_libraries(myClassA )

add_executable(${PROJECT_NAME} ${SRCS_FILES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIB}  pthread)


enable_testing()
add_subdirectory(unit_test)

# add_test(myGTest ${PROJECT_NAME})
