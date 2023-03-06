#pragma once
#include "Triangle.h"
#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class EquilateralTriangle : public Triangle
{
public:
	FIGURESDYNLIB_API EquilateralTriangle(double a);
	FIGURESDYNLIB_API ~EquilateralTriangle();
};