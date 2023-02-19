#include "Rhombus.Class.h"
#include "FigureCreationExeption.Class.h"

Rhombus::Rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
{
	name = "Ромб";
	if (!check()) {
		throw WrongShape("Ошибка создания фигуры. Причина: не все стороны равны, \
или углы A,C и B,D попарно не равны");
	}
}
Rhombus::~Rhombus() {}
