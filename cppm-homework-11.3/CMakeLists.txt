cmake_minimum_required(VERSION 3.22.0)
project(LeaverDybLibInCMake)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(DynLib SHARED ./DynLib/Leaver.h ./DynLib/LeaverClass.cpp)

add_executable(LeaverEXE Source.cpp)

target_link_libraries(LeaverEXE DynLib)