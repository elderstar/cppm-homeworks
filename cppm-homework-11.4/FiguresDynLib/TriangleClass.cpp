#include "Triangle.h"
#include<iostream>

Triangle::Triangle(double _a, double _b, double _c, double _A, double _B, double _C)
{
	a = _a;
	b = _b;
	c = _c;
	A = _A;
	B = _B;
	C = _C;
	side_count = 3;
	name = "�����������";
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
	std::cout << "\n" << getName() << ":";
	std::cout << "\n" << "�������: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c();
	std::cout << "\n" << "����: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C();
}