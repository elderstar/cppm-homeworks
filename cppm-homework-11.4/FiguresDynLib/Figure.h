#pragma once
#include <string>
#include "Figure.h"

#ifdef FIGURESDYNLIB_EXPORTS
	#define FIGURESDYNLIB_API __declspec(dllexport)
#else
	#define FIGURESDYNLIB_API __declspec(dllimport)
#endif // DEBUG

class Figure
{
public:

	FIGURESDYNLIB_API Figure();

	FIGURESDYNLIB_API int getSideCount();

	FIGURESDYNLIB_API std::string getName();

	FIGURESDYNLIB_API ~Figure();

	FIGURESDYNLIB_API void virtual print();

protected:
	int side_count;
	std::string name;
};