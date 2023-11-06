cmake_minimum_required(VERSION 3.17)
project(TeradataIceCode)

set(CMAKE_MAKE_PROGRAM "/usr/bin/make")
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 14)


#add_executable(TeradataIceCode src/main.cpp)
add_executable(IceCode src/IceCode.cpp src/IceKey.cpp include/IceKey.h)
