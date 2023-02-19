#pragma once
#include "Triangle.Class.h"

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(double a, double b, double c, double A, double B, double C);
	~IsoscelesTriangle();
protected:
	bool check() override;
};