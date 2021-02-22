

include_directories(${PROJECT_SOURCE_DIR}/include)

link_libraries(${PROJECT_BINARY_DIR})


add_executable(myAddTest  myAddTest.cpp )
target_link_libraries(myAddTest myClassA ${GTEST_LIB}  pthread)

add_executable(myMultiTest myMultiTest.cpp )
target_link_libraries(myMultiTest myClassA ${GTEST_LIB}  pthread)

add_executable(myFixtureTest myFixtureTest.cpp )
target_link_libraries(myFixtureTest myClassA ${GTEST_LIB}  pthread)


add_test(myTest01 myAddTest)
add_test(myTest02 myMultiTest)

