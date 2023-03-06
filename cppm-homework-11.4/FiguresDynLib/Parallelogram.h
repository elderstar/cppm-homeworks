#pragma once
#include "Quadrilateral.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Parallelogram : public Quadrilateral
{
public:
	FIGURESDYNLIB_API Parallelogram(double a, double b, double A, double B);
	FIGURESDYNLIB_API ~Parallelogram();
};