#include <iostream>
#include "libs/Figures.h"

void print_info(Figure* figure) {

	figure->print();
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//	создаем фигуры с минимальными данными для построения фигур (защита от ввода неверных данных)

	Triangle triangle(10, 20, 30, 50, 60, 60);
	Figure* par_triangle = &triangle;
	print_info(par_triangle);

	RightTriangle right_triangle(10, 20, 30, 50, 60);
	Triangle* par_right_triangle = &right_triangle;
	print_info(par_right_triangle);

	IsoscelesTriangle isosceles_triangle(10, 90);
	Triangle* par_isosceles_triangle = &isosceles_triangle;
	print_info(par_isosceles_triangle);

	EquilateralTriangle equilateral_triangle(100);
	Triangle* par_equilateral_triangle = &equilateral_triangle;
	print_info(par_equilateral_triangle);

	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* par_quadrilateral = &quadrilateral;
	print_info(par_quadrilateral);

	Rectangle rectangle(10, 20);
	Parallelogram* par_rectangle = &rectangle;
	print_info(par_rectangle);

	Square square(10);
	Rectangle* par_square = &square;
	print_info(par_square);

	Parallelogram parallelogram(10, 30, 40, 50);
	Quadrilateral* par_parallelogram = &parallelogram;
	print_info(par_parallelogram);

	Rhombus rhombus(30, 30, 40);
	Parallelogram* par_rhombus = &rhombus;
	print_info(par_rhombus);

	return 0;
}