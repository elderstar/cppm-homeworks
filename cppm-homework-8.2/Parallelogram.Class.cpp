#include "Parallelogram.Class.h"
#include "FigureCreationExeption.Class.h"

Parallelogram::Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		name = "Параллелограмм";
		if (!check()) {
			throw WrongShape("Ошибка создания фигуры. Причина: стороны a,c и b,d попарно не равны, \
углы A,C и B,D попарно не равны");
		}
	}
Parallelogram::~Parallelogram() {}

bool Parallelogram::check() 
{
	if (!Quadrilateral::check() || a != c || b != d || A != C || B != D) {
		return false;
	}
	else {
		return true;
	}
}