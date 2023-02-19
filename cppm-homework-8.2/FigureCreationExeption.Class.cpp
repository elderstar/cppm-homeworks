#include "FigureCreationExeption.Class.h"

WrongShape::WrongShape(const char* _reason) : domain_error(_reason) {
};
