#include "Square.Class.h"
#include "FigureCreationExeption.Class.h"

Square::Square(double a, double b, double c, double d, double A, double B, double C, double D) : Rectangle(a, b, c, d, A, B, C, D)
{
	name = "�������";
	if (!check()) {
		throw WrongShape("������ �������� ������. �������: �� ��� ������� �����, \
��� ���� �� ����� 90 ����.");
	}
}
Square::~Square() {}
