#include"Greeter.h"

Greeter::~Greeter() {};
std::string Greeter::greet(std::string _str) {

    return "Здравствуйте, " + _str + "!";
}