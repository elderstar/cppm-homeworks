#pragma once
#include <string>

class Greeter {
public:
    ~Greeter();
    std::string greet(std::string _str);
private:
    std::string str = "";
};