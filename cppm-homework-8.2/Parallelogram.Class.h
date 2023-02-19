#pragma once
#include "Quadrilateral.Class.h"

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D);
	~Parallelogram();

protected:
	bool check() override;
};