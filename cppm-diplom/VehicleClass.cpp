#include "VehicleClass.h"
#include <vector>
#include <iostream>
Vehicle::Vehicle() {
	velocity = 0;
};

Vehicle::~Vehicle() {};

std::string Vehicle::getVehicleName() {
	return name;
};

bool Vehicle::operator> (Vehicle& right) {

	if (this->getResult() > right.getResult()) {
		return true;
	}
	else {
		return false;
	}
};

double Vehicle::calculateMovementTime(double length) {
	
	return length / velocity;
};

std::unique_ptr<Vehicle>* Vehicle::getParChildPtr() {
	return par_child;
}

void Vehicle::setParChildPtr(std::unique_ptr<Vehicle>* _par_child) {
	par_child = _par_child;
}

void Vehicle::setResult(double _result) {

	result = _result;
}

double Vehicle::getResult() {

	return result;
}