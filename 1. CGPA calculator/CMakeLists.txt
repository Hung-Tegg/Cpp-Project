cmake_minimum_required(VERSION 3.26.5)
set(CMAKE_CXX_STANDARD 11)
include_directories(inc)

file(GLOB SOURCE "src/*.cpp")

project(CGPACalculator)

add_executable(CGPACalculator ${SOURCE})
