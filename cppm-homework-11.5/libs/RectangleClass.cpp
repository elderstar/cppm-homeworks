#include"Rectangle.h"

Rectangle::Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
{
	name = "Прямоугольник";
}

Rectangle::~Rectangle() {}