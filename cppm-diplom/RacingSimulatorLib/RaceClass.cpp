#include"RaceClass.h"

Race::Race() {
	length = 0;
	title = "Гонка для наземного и воздушного транспорта";
};

Race::~Race() {};

bool Race::checkNewParticipant(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count) {
	std::string new_participant_name = vehicle->getVehicleName();

	for (int i = 0; i < participants_count; ++i) {
		if (participants[i].getVehicleName() == new_participant_name)
			return false;
	}
	return true;
}

bool Race::checkVehicleType(std::unique_ptr<Vehicle>& vehicle) {
	return true;
}

Vehicle* Race::registerVehicle(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count) {

	if (!checkNewParticipant(participants, vehicle, participants_count))
		throw std::domain_error(vehicle->getVehicleName() + " уже зрегистрирован!");
	if (!this->checkVehicleType(vehicle))
		throw std::domain_error("Попытка зарегистрировать неправильный тип транспортного средства!");

	vehicle->setParChildPtr(&vehicle);

	if (participants_count > 0) {

		Vehicle* temp_participants = new Vehicle[++participants_count];

		for (int i = 0; i < participants_count - 1; ++i)
		{
			temp_participants[i] = participants[i];
		}

		delete[] participants;
		participants = temp_participants;
		participants[participants_count - 1] = *vehicle;
	}
	else {
		delete[] participants;
		participants = new Vehicle[++participants_count];
		participants[participants_count - 1] = *vehicle;
	}
	return participants;
}

void Race::setLength(unsigned int _length) {

	length = _length;
}

unsigned int Race::getLength() {

	return length;
}

std::string Race::getTitle() {

	return title;
}