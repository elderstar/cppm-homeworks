#pragma once
#include <string>

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