#include "AllTerrainBootsClass.h"

AllTerrainBoots::AllTerrainBoots() {
	name = "Ботинки-вездеходы";
	velocity = 6;
	stamina = 60;
};
AllTerrainBoots::~AllTerrainBoots() {};

double AllTerrainBoots::calculateMovementTime(double length) {
	double time = length / velocity;

	int cooldowns = ceil(time / stamina) - 1;

	for (int i = 0; i < cooldowns; ++i) {
		if (i == 0) {
			time += 10;
		}
		else {
			time += 5;
		}
	}
	return time;
};