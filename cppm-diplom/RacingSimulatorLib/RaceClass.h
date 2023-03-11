#pragma once
#include <string>
#include"VehicleClass.h"
#include"APIExports.h"

class Race {

public:
	RACINGSIMULATORLIB_API Race();
	RACINGSIMULATORLIB_API ~Race();

	RACINGSIMULATORLIB_API bool checkNewParticipant(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count);

	RACINGSIMULATORLIB_API bool virtual checkVehicleType(std::unique_ptr<Vehicle>& vehicle);

	RACINGSIMULATORLIB_API Vehicle* registerVehicle(Vehicle*& participants, std::unique_ptr<Vehicle>& vehicle, size_t& participants_count);

	RACINGSIMULATORLIB_API void setLength(unsigned int _length);

	RACINGSIMULATORLIB_API unsigned int getLength();

	RACINGSIMULATORLIB_API std::string getTitle();

protected:
	unsigned int length;
	std::string title;
};