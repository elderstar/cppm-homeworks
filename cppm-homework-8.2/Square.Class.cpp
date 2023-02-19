#include "Square.Class.h"
#include "FigureCreationExeption.Class.h"

Square::Square(double a, double b, double c, double d, double A, double B, double C, double D) : Rectangle(a, b, c, d, A, B, C, D)
{
	name = "Квадрат";
	if (!check()) {
		throw WrongShape("Ошибка создания фигуры. Причина: не все стороны равны, \
или углы не равны 90 град.");
	}
}
Square::~Square() {}
