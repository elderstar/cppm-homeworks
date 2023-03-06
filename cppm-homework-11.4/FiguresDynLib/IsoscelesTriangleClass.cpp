#include"IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double B) : Triangle(a, b, a, A, B, C)
{
	A = (180 - B) / 2;
	C = A;
	b = sqrt(a * a + c * c - 2 * a * c * cos(B));
	name = "Равнобедренный треугольник";
}

IsoscelesTriangle::~IsoscelesTriangle() {}