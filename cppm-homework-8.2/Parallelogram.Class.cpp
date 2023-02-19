#include "Parallelogram.Class.h"
#include "FigureCreationExeption.Class.h"

Parallelogram::Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		name = "��������������";
		if (!check()) {
			throw WrongShape("������ �������� ������. �������: ������� a,c � b,d ������� �� �����, \
���� A,C � B,D ������� �� �����");
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