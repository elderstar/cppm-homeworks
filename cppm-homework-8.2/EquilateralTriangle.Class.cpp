#include "EquilateralTriangle.Class.h"
#include "FigureCreationExeption.Class.h"

EquilateralTriangle::EquilateralTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "�������������� �����������";
		if (!check()) {
			throw WrongShape("������ �������� ������. �������: ���� �� ����� 60 ����. ��� ������� �� ����� ���� �����.");
		}
	}
EquilateralTriangle::~EquilateralTriangle() {}

bool EquilateralTriangle::check() 
{
	if (!Triangle::check() || A != 60 || A != C || A != B || a != b || a != c) {
		return false;
	}
	else {
		return true;
	}
}
