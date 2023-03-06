#pragma once
#include "Parallelogram.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Rhombus : public Parallelogram
{
public:
	FIGURESDYNLIB_API Rhombus(double a, double A, double B);
	FIGURESDYNLIB_API ~Rhombus();
};