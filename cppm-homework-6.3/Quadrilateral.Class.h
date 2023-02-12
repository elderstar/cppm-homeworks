#pragma once
#include "Figure.Class.h"

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