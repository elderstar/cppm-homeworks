#include "Figure.Class.h"

Figure::Figure()
{
	side_count = 0;
	name = "Фигура";
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

void Figure::print() {}