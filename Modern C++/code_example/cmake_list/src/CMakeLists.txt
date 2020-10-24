add_library(hello SHARED hello.cpp) #adding for implementation
add_library(blah SHARED blah.cpp)   #shared -> dynamic library

add_executable(bin_main main.cpp) #for main code

target_link_libraries(bin_main 
                      hello
                      blah) #linking binary to a compiled implemenatation