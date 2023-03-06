cmake_minimum_required(VERSION 3.22.0)
project(FiguresDynLibCMake)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguresDynLib SHARED 
./libs/Figure.h ./libs/FiguresClass.cpp 
./libs/EquilateralTriangle.h ./libs/EquilateralTriangleClass.cpp
./libs/IsoscelesTriangle.h ./libs/IsoscelesTriangleClass.cpp
./libs/Parallelogram.h ./libs/ParallelogramClass.cpp
./libs/Quadrilateral.h ./libs/QuadrilateralClass.cpp
./libs/Rectangle.h ./libs/RectangleClass.cpp
./libs/Rhombus.h ./libs/RhombusClass.cpp
./libs/RightTriangle.h ./libs/RightTriangleClass.cpp
./libs/Square.h ./libs/SquareClass.cpp
./libs/Triangle.h ./libs/TriangleClass.cpp
)

add_executable(FiguresEXE Source.cpp)

target_link_libraries(FiguresEXE FiguresDynLib)