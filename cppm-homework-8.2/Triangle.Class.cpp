#include "Triangle.Class.h"
#include <iostream>
#include "FigureCreationExeption.Class.h"

Triangle::Triangle(double _a, double _b, double _c, double _A, double _B, double _C)
	{
		a = _a;
		b = _b;
		c = _c;
		A = _A;
		B = _B;
		C = _C;
		countSides();
		name = "Треугольник";
		if (!check()) {
			throw WrongShape("Ошибка создания фигуры. Причина: сумма углов не равна 180");
		}
	}

Triangle::~Triangle() {}

double Triangle::get_a()
{
	return a;
}

double Triangle::get_b()
{
	return b;
}

double Triangle::get_c()
{
	return c;
}

double Triangle::get_A()
{
	return A;
}

double Triangle::get_B()
{
	return B;
}

double Triangle::get_C()
{
	return C;
}

void Triangle::print()
{
	Figure::print();
	std::cout << "(стороны " << get_a() << ", " << get_b() << ", " << get_c() << ";" << "углы "
		<< get_A() << " , " << get_B() << " , " << get_C() << ") создан";
}

bool Triangle::check()
{
	if (side_count != 3 || (A + B + C) != 180) {
		return false;
	}
	else {
		return true;
	}
}

void Triangle::countSides()
{
	side_count = 0;
	for (double i : { a, b, c })
	{
		if (i > 0)
			++side_count;
	}
}
