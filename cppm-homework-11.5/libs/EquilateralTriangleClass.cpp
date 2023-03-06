#include"EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
{
	name = "Равносторонний треугольник";
}

EquilateralTriangle::~EquilateralTriangle() {}