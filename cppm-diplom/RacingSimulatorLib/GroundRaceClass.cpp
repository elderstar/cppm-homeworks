#include"GroundRaceClass.h"

GroundRace::GroundRace() {
	title = "����� ��� ��������� ����������";
};
GroundRace::~GroundRace() {};

bool GroundRace::checkVehicleType(std::unique_ptr<Vehicle>& vehicle) {

	return dynamic_cast<Ground*>(&*vehicle);
	/*if (dynamic_cast<Ground*>(&*vehicle)) {
		return true;
	}
	else {
		return false;
	};*/
}
