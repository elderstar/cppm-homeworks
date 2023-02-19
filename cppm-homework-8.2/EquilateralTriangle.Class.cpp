#include "EquilateralTriangle.Class.h"
#include "FigureCreationExeption.Class.h"

EquilateralTriangle::EquilateralTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "Равносторонний треугольник";
		if (!check()) {
			throw WrongShape("Ошибка создания фигуры. Причина: углы не равны 60 град. или стороны не равны друг другу.");
		}
	}
EquilateralTriangle::~EquilateralTriangle() {}

bool EquilateralTriangle::check() 
{
	if (!Triangle::check() || A != 60 || A != C || A != B || a != b || a != c) {
		return false;
	}
	else {
		return true;
	}
}
