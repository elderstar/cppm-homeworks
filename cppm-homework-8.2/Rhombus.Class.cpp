#include "Rhombus.Class.h"
#include "FigureCreationExeption.Class.h"

Rhombus::Rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
{
	name = "����";
	if (!check()) {
		throw WrongShape("������ �������� ������. �������: �� ��� ������� �����, \
��� ���� A,C � B,D ������� �� �����");
	}
}
Rhombus::~Rhombus() {}
