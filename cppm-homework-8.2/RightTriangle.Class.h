#pragma once
#include "Triangle.Class.h"

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B, double C);
	~RightTriangle();
protected:
	bool check() override;
};