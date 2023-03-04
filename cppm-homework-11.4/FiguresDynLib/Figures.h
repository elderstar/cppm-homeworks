#pragma once
#include <string>

#ifdef FIGURESDYNLIB_EXPORTS
	#define FIGURESDYNLIB_API __declspec(dllexport)
#else
	#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Figure
{
public:

	FIGURESDYNLIB_API Figure();

	FIGURESDYNLIB_API int getSideCount();

	FIGURESDYNLIB_API std::string getName();

	FIGURESDYNLIB_API ~Figure();

	FIGURESDYNLIB_API void virtual print();

protected:
	int side_count;
	std::string name;
};

class Triangle : public Figure
{
public:
	FIGURESDYNLIB_API Triangle(double _a, double _b, double _c, double _A, double _B, double _C);
	FIGURESDYNLIB_API ~Triangle();

	FIGURESDYNLIB_API double get_a();

	FIGURESDYNLIB_API double get_b();

	FIGURESDYNLIB_API double get_c();

	FIGURESDYNLIB_API double get_A();

	FIGURESDYNLIB_API double get_B();

	FIGURESDYNLIB_API double get_C();

	FIGURESDYNLIB_API void print() override;

protected:
	double a, b, c, A, B, C;
};

class EquilateralTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API EquilateralTriangle(double a);
	FIGURESDYNLIB_API ~EquilateralTriangle();
};

class IsoscelesTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API IsoscelesTriangle(double a, double B);
	FIGURESDYNLIB_API ~IsoscelesTriangle();
};

class RightTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API RightTriangle(double a, double b, double c, double A, double B);
	FIGURESDYNLIB_API ~RightTriangle();
};

class Quadrilateral : public Figure
{
public:
	FIGURESDYNLIB_API Quadrilateral(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D);

	FIGURESDYNLIB_API ~Quadrilateral();

	FIGURESDYNLIB_API double get_a();

	FIGURESDYNLIB_API double get_b();

	FIGURESDYNLIB_API double get_c();

	FIGURESDYNLIB_API double get_d();

	FIGURESDYNLIB_API double get_A();

	FIGURESDYNLIB_API double get_B();

	FIGURESDYNLIB_API double get_C();

	FIGURESDYNLIB_API double get_D();

	FIGURESDYNLIB_API void print() override;
protected:
	double a, b, c, d, A, B, C, D;
};

class Parallelogram : public Quadrilateral
{
public:
	FIGURESDYNLIB_API Parallelogram(double a, double b, double A, double B);
	FIGURESDYNLIB_API ~Parallelogram();
};

class Rectangle : public Parallelogram
{
public:
	FIGURESDYNLIB_API Rectangle(double a, double b);
	FIGURESDYNLIB_API ~Rectangle();
};

class Rhombus : public Parallelogram
{
public:
	FIGURESDYNLIB_API Rhombus(double a, double A, double B);
	FIGURESDYNLIB_API ~Rhombus();
};

class Square : public Rectangle
{
public:
	FIGURESDYNLIB_API Square(double a);
	FIGURESDYNLIB_API ~Square();
};
