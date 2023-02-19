#include "RightTriangle.Class.h"
#include "Triangle.Class.h"
#include "FigureCreationExeption.Class.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "Прямоугольный треугольник";
		if (!check()) {
			throw WrongShape("Ошибка создания фигуры. Причина: угол С не равен 90");
		}
	}
RightTriangle::~RightTriangle() {};

bool RightTriangle::check() 
{
	if (!Triangle::check() || C != 90) {
		return false;
	}
	else {
		return true;
	}
}
