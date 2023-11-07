cmake_minimum_required(VERSION 3.17)
project(TeradataIceCode)

set(CMAKE_MAKE_PROGRAM "/usr/bin/make")
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 14)
set(targetfile "bin/IceCode.exe")

add_executable(IceCode src/IceCode.cpp src/IceKey.cpp include/IceKey.h)
add_custom_command(TARGET IceCode POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:IceCode> ${CMAKE_SOURCE_DIR}/${targetfile})
#file(COPY build/IceCode DESTINATION bin FOLLOW_SYMLINK_CHAIN)
