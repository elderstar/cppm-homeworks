#include "MagicCarpetClass.h"

MagicCarpet::MagicCarpet() {
	name = "Ковёр-самолёт";
	velocity = 10;
};
MagicCarpet::~MagicCarpet() {};


double MagicCarpet::calculateMovementTime(double length) {
	double multiplier = 0;

	if (length >= 1000) {
		multiplier = 0.03;
	}

	if (length >= 5000) {
		multiplier = 0.1;
	}

	if (length >= 10000) {
		multiplier = 0.05;
	}
	return length * (1 - multiplier) / velocity;
};