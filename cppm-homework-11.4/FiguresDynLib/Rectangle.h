#pragma once
#include "Parallelogram.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Rectangle : public Parallelogram
{
public:
	FIGURESDYNLIB_API Rectangle(double a, double b);
	FIGURESDYNLIB_API ~Rectangle();
};