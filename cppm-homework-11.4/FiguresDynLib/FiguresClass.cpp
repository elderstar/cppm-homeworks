#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Rhombus.h"
#include "Parallelogram.h"

Figure::Figure()
{
	side_count = 0;
	name = "Фигура";
}

int Figure::getSideCount()
{
	return side_count;
}

std::string Figure::getName()
{
	return name;
}

Figure::~Figure() {}

void Figure::print() {}