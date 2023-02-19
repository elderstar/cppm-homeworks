#pragma once
#include "Parallelogram.Class.h"

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b, double c, double d, double A, double B, double C, double D);

	~Rectangle();
protected:
	bool check() override;
};