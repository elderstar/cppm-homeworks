#pragma once
#include "Triangle.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class IsoscelesTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API IsoscelesTriangle(double a, double B);
	FIGURESDYNLIB_API ~IsoscelesTriangle();
};