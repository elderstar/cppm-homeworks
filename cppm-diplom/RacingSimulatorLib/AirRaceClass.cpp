#include"AirRaceClass.h"

AirRace::AirRace() {
	title = "����� ��� ���������� ����������";
};
AirRace::~AirRace() {};

bool AirRace::checkVehicleType(std::unique_ptr<Vehicle>& vehicle) {

	return dynamic_cast<Aircraft*>(&*vehicle);
	/*if (dynamic_cast<Aircraft*>(&*vehicle)) {
		return true;
	}
	else {
		return false;
	};*/
}
