#pragma once
#include"Figure.h"

#ifdef FIGURESDYNLIB_EXPORTS
#define FIGURESDYNLIB_API __declspec(dllexport)
#else
#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Triangle : public Figure
{
public:
	FIGURESDYNLIB_API Triangle(double _a, double _b, double _c, double _A, double _B, double _C);
	FIGURESDYNLIB_API ~Triangle();

	FIGURESDYNLIB_API double get_a();

	FIGURESDYNLIB_API double get_b();

	FIGURESDYNLIB_API double get_c();

	FIGURESDYNLIB_API double get_A();

	FIGURESDYNLIB_API double get_B();

	FIGURESDYNLIB_API double get_C();

	FIGURESDYNLIB_API void print() override;

protected:
	double a, b, c, A, B, C;
};