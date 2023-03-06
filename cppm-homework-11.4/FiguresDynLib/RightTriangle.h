#pragma once
#include "Triangle.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class RightTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API RightTriangle(double a, double b, double c, double A, double B);
	FIGURESDYNLIB_API ~RightTriangle();
};