cmake_minimum_required(VERSION 3.16)
project(lab6)
set(CMAKE_CXX_STANDARD 17)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(lab6 main.cpp isReal.cpp isReal.h)