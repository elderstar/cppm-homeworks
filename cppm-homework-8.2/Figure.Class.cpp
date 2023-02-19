#include <iostream>
#include "Figure.Class.h"
#include "FigureCreationExeption.Class.h"

Figure::Figure()
{
	side_count = 0;
	name = "Фигура";
	if (!check()) {
		throw WrongShape("Сторон больше 0");
	}
}

int Figure::getSideCount()
{
	return side_count;
}

std::string Figure::getName()
{
	return name;
}

Figure::~Figure() {}

void Figure::print() {
	std::cout << "\n" << getName() << ":";
	
}

int side_count;
std::string name;

bool Figure::check() {
	if (side_count > 0) {
		return false;
	}
	else {
		return true;
	}
}
