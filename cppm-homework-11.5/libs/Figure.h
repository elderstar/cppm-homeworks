#pragma once
#include <string>
#include "Figure.h"



class Figure
{
public:

	 Figure();

	 int getSideCount();

	 std::string getName();

	 ~Figure();

	 void virtual print();

protected:
	int side_count;
	std::string name;
};