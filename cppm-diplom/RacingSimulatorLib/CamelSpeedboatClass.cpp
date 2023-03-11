#include "CamelSpeedboatClass.h"

CamelSpeedboat::CamelSpeedboat() {
	name = "Верблюд-быстроход";
	velocity = 40;
	stamina = 10;
};
CamelSpeedboat::~CamelSpeedboat() {};

double CamelSpeedboat::calculateMovementTime(double length) {
	double time = length / velocity;

	int cooldowns = ceil(time / stamina) - 1;

	for (int i = 0; i < cooldowns; ++i) {
		if (i < 2) {
			if (i == 0) {
				time += 5;
			}
			else {
				time += 6.5;
			}
		}
		else {
			time += 8;
		}
	}
	return time;
};
