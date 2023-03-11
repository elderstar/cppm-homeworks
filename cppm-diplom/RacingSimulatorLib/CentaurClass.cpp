#include "CentaurClass.h"

Centaur::Centaur() {
	name = "Кентавр";
	velocity = 15;
	stamina = 8;
};
Centaur::~Centaur() {};

double Centaur::calculateMovementTime(double length) {
	double time = length / velocity;

	int cooldowns = ceil(time / stamina) - 1;

	for (int i = 0; i < cooldowns; ++i) {
		time += 2;
	}
	return time;
};