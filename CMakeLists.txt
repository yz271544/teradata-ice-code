cmake_minimum_required(VERSION 3.17)
project(TeradataIceCode)

set(CMAKE_CXX_STANDARD 14)


#add_executable(TeradataIceCode src/main.cpp)
add_executable(IceCode src/IceCode.cpp src/IceKey.cpp include/IceKey.h)