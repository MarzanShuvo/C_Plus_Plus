project(cmake_test_project) #mandatory
cmake_minimum_required(VERSION 3.10.2)

message(STATUS "!!!!!!!!!!!!! ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src) #to search header in the directory and #include<hello.h> can be used

add_subdirectory(${PROJECT_SOURCE_DIR}/src) #PROJECT_SOURCE_DIR is a cmake variable for path

enable_testing() # for testing and must be decleare in top most cmake
add_subdirectory(tests)