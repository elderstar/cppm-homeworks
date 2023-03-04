#pragma once

#ifdef DYNAMICLIBHOMEWORK_EXPORTS
	#define DYNAMICLIBHOMEWORK_API __declspec(dllexport)
#else
	#define DYNAMICLIBHOMEWORK_API __declspec(dllimport)
#endif // DYNAMICLIBHOMEWORK_EXPORTS

#include<string>

class Leaver {
public:
	DYNAMICLIBHOMEWORK_API std::string leave(std::string _str);
	DYNAMICLIBHOMEWORK_API ~Leaver();
private:
	std::string str = "";
};
