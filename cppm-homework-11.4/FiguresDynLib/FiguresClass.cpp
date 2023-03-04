#include "Figures.h"
#include <iostream>

Figure::Figure()
{
	side_count = 0;
	name = "”игура";
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

Triangle::Triangle(double _a, double _b, double _c, double _A, double _B, double _C)
{
	a = _a;
	b = _b;
	c = _c;
	A = _A;
	B = _B;
	C = _C;
	side_count = 3;
	name = "Треугольник";
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
	std::cout << "\n" << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c();
	std::cout << "\n" << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C();
}

EquilateralTriangle::EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
{
	name = "Равносторонний треугольник";
}

EquilateralTriangle::~EquilateralTriangle() {}

IsoscelesTriangle::IsoscelesTriangle(double a, double B) : Triangle(a, b, a, A, B, C)
{
	A = (180 - B) / 2;
	C = A;
	b = sqrt(a * a + c * c - 2 * a * c * cos(B));
	name = "Равнобедренный треугольник";
}

IsoscelesTriangle::~IsoscelesTriangle() {}

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
{
	name = "Прямоугольный треугольник";
}
RightTriangle::~RightTriangle() {}

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

Rectangle::Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
{
	name = "Прямоугольник";
}

Rectangle::~Rectangle() {}

Rhombus::Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B)
{
	name = "Ромб";
}
Rhombus::~Rhombus() {}

Square::Square(double a) : Rectangle(a, a)
{
	name = "Квадрат";
}

Square::~Square() {}

Parallelogram::Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B)
{
	name = "Параллелограмм";
}

Parallelogram::~Parallelogram() {}