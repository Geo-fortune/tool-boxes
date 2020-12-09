
add_executable(imshow_test imshow_test.cpp)
target_link_libraries(imshow_test ${OpenCV_LIBRARIES} pthread)