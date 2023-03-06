#pragma once
#include "Figure.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Quadrilateral : public Figure
{
public:
	FIGURESDYNLIB_API Quadrilateral(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D);

	FIGURESDYNLIB_API ~Quadrilateral();

	FIGURESDYNLIB_API double get_a();

	FIGURESDYNLIB_API double get_b();

	FIGURESDYNLIB_API double get_c();

	FIGURESDYNLIB_API double get_d();

	FIGURESDYNLIB_API double get_A();

	FIGURESDYNLIB_API double get_B();

	FIGURESDYNLIB_API double get_C();

	FIGURESDYNLIB_API double get_D();

	FIGURESDYNLIB_API void print() override;
protected:
	double a, b, c, d, A, B, C, D;
};