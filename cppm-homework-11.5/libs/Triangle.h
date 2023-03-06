#pragma once
#include"Figure.h"



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