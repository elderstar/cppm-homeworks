#include "CamelClass.h"

Camel::Camel() {
	name = "Верблюд";
	velocity = 10;
	stamina = 30;
};
Camel::~Camel() {};

double Camel::calculateMovementTime(double length) {
	double time = length / velocity;

	int cooldowns = ceil(time / stamina) - 1;
	
	for (int i = 0; i < cooldowns; ++i) {
		if (i == 0) {
			time += 5;
		}
		else {
			time += 8;
		}
	}
	return time;
};
