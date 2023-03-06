#pragma once
#include "Rectangle.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Square : public Rectangle
{
public:
	FIGURESDYNLIB_API Square(double a);
	FIGURESDYNLIB_API ~Square();
};