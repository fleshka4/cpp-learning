cmake_minimum_required(VERSION 3.17)
project(7th_lab)

set(CMAKE_CXX_STANDARD 20)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(7th_lab myArray.h main.cpp myString.cpp myString.h payment.h payment.cpp myException.cpp myException.h input.txt)