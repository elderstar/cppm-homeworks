#pragma once
#include "Triangle.Class.h"

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(double a, double b, double c, double A, double B, double C);
	~EquilateralTriangle();
protected:
	bool check() override;
};