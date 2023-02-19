#include "IsoscelesTriangle.Class.h"
#include "Triangle.Class.h"
#include "FigureCreationExeption.Class.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		name = "�������������� �����������";
		if (!check()) {
			throw WrongShape("������ �������� ������. �������: ������� '�' �� ����� 'c' \
��� ���� 'A' �� ����� ���� 'C'");
		}
	}
IsoscelesTriangle::~IsoscelesTriangle() {}

bool IsoscelesTriangle::check() 
{
	if (!Triangle::check() || A != C || a != c) {
		return false;
	}
	else {
		return true;
	}
}
