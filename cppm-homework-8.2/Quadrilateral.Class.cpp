#include "Quadrilateral.Class.h"
#include <iostream>
#include "FigureCreationExeption.Class.h"

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
		countSides();
		name = "Четырёхугольник";
		if (!check()) {
			throw WrongShape("Ошибка создания фигуры. Причина: сумма углов не равна 360");
		}
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
	Figure::print();
	std::cout << "(стороны " << get_a() << ", " << get_b() << ", " << get_c() << ", " << get_d() << ";" << "углы "
		<< get_A() << ", " << get_B() << ", " << get_C() << ", " << get_D() << ") создан";
}

bool Quadrilateral::check() 
{
	if (side_count != 4 || (A + B + C + D) != 360) {
		return false;
	}
	else {
		return true;
	}
}

void Quadrilateral::countSides()
{
	side_count = 0;
	for (double i : { a, b, c, d })
	{
		if (i > 0)
			++side_count;
	}
}
