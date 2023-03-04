#pragma once
#include <string>

class Figure
{
public:

	Figure();

	int getSideCount();

	std::string getName();

	~Figure();

	void virtual print();

protected:
	int side_count;
	std::string name;
};

class Triangle : public Figure
{
public:
	Triangle(double _a, double _b, double _c, double _A, double _B, double _C);
	~Triangle();

	double get_a();

	double get_b();

	double get_c();

	double get_A();

	double get_B();

	double get_C();

	void print() override;

protected:
	double a, b, c, A, B, C;
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(double a);
	~EquilateralTriangle();
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(double a, double B);
	~IsoscelesTriangle();
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B);
	~RightTriangle();
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D);

	~Quadrilateral();

	double get_a();

	double get_b();

	double get_c();

	double get_d();

	double get_A();

	double get_B();

	double get_C();

	double get_D();

	void print() override;
protected:
	double a, b, c, d, A, B, C, D;
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(double a, double b, double A, double B);
	~Parallelogram();
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b);
	~Rectangle();
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double a, double A, double B);
	~Rhombus();
};

class Square : public Rectangle
{
public:
	Square(double a);
	~Square();
};
