#include "BroomClass.h"

Broom::Broom() {
	name = "Метла";
	velocity = 20;
};

Broom::~Broom() {};

double Broom::calculateMovementTime(double length) {

	return length * (1 - (static_cast<int>(length) / 1000 / 100.00)) / velocity;
};