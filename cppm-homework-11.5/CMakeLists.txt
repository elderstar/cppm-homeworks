cmake_minimum_required(VERSION 3.22.0)
project(FiguresDynLibCMake)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguresDynLib SHARED ./libs/Figures.h ./libs/FiguresClass.cpp)

add_executable(FiguresEXE Source.cpp)

target_link_libraries(FiguresEXE FiguresDynLib)