#include "EagleClass.h"

Eagle::Eagle() {
	name = "���";
	velocity = 8;
};
Eagle::~Eagle() {};

double Eagle::calculateMovementTime(double length) {

	return (length * (1 - 0.06)) / velocity;
};
