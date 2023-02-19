#include "Rectangle.Class.h"
#include "FigureCreationExeption.Class.h"

Rectangle::Rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
	{
		name = "�������������";
		if (!check()) {
			throw WrongShape("������ �������� ������. �������: ���� �� ����� 90 ����. \
 ��� ��������������� ������� �� ����� ���� �����");
		}
	}

Rectangle::~Rectangle() {};

bool Rectangle::check()
{
	if (!Parallelogram::check() || a != c || b != d || A != 90 || A != B || A != C) {
		return false;
	}
	else {
		return true;
	}
}
