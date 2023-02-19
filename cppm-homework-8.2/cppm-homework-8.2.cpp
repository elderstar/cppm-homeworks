#include <iostream>
#include "FigureCreationExeption.Class.h"
#include "Figure.Class.h"
#include "Triangle.Class.h"
#include "Quadrilateral.Class.h"
#include "RightTriangle.Class.h"
#include "IsoscelesTriangle.Class.h"
#include "EquilateralTriangle.Class.h"
#include "Parallelogram.Class.h"
#include "Rectangle.Class.h"
#include "Square.Class.h"
#include "Rhombus.Class.h"
#include <iostream>

void print_info(Figure* figure) {

	figure->print();
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		Triangle triangle(10, 10, 30, 60, 60, 60);
		Figure* par_triangle = &triangle;
		print_info(par_triangle);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		RightTriangle right_triangle(10, 20, 30, 45, 45, 90);
		Triangle* par_right_triangle = &right_triangle;
		print_info(par_right_triangle);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		IsoscelesTriangle isosceles_triangle(30, 20, 30, 70, 40, 70);
		Triangle* par_isosceles_triangle = &isosceles_triangle;
		print_info(par_isosceles_triangle);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		EquilateralTriangle equilateral_triangle(30, 30, 30, 60, 60, 60);
		Triangle* par_equilateral_triangle = &equilateral_triangle;
		print_info(par_equilateral_triangle);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		Quadrilateral quadrilateral(10, 20, 30, 40, 100, 80, 100, 80);
		Figure* par_quadrilateral = &quadrilateral;
		print_info(par_quadrilateral);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		Rectangle rectangle(10, 20, 10, 20, 89, 91, 90, 90);
		Parallelogram* par_rectangle = &rectangle;
		print_info(par_rectangle);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		Square square(20, 20, 20, 20, 90, 90, 90, 90);
		Rectangle* par_square = &square;
		print_info(par_square);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		Parallelogram parallelogram(10, 20, 10, 20, 100, 80, 100, 80);
		Quadrilateral* par_parallelogram = &parallelogram;
		print_info(par_parallelogram);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	try {
		Rhombus rhombus(10, 10, 10, 10, 100, 80, 100, 80);
		Parallelogram* par_rhombus = &rhombus;
		print_info(par_rhombus);
	}
	catch (WrongShape& e) {
		std::cout << e.what() << "\n";
	}
	

	return 0;
}