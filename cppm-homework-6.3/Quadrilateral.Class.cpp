#include "Quadrilateral.Class.h"
#include <iostream>

Quadrilateral::Quadrilateral(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D)
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
	A = _A;
	B = _B;
	C = _C;
	D = _D;
	side_count = 4;
	name = "Четырёхугольник";
}

Quadrilateral::~Quadrilateral() {}

double Quadrilateral::get_a()
{
	return a;
}

double Quadrilateral::get_b()
{
	return b;
}

double Quadrilateral::get_c()
{
	return c;
}

double Quadrilateral::get_d()
{
	return d;
}

double Quadrilateral::get_A()
{
	return A;
}

double Quadrilateral::get_B()
{
	return B;
}

double Quadrilateral::get_C()
{
	return C;
}

double Quadrilateral::get_D()
{
	return D;
}

void Quadrilateral::print()
{
	std::cout << "\n" << getName() << ":";
	std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d();
	std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D();
}