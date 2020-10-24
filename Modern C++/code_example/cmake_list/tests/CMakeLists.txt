add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)


include(CTest)

add_executable(test_blah test_blah.cpp)

target_link_libraries(test_blah
                      blah
                      gtest gtest_main)

add_test(test_blah tests/test_blah)