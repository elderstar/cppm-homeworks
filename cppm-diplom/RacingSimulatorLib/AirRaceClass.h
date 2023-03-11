#pragma once
#include"APIExports.h"
#include"RaceClass.h"
#include"AircraftClass.h"

class AirRace : public Race {

public:
	RACINGSIMULATORLIB_API AirRace();
	RACINGSIMULATORLIB_API ~AirRace();

	RACINGSIMULATORLIB_API bool checkVehicleType(std::unique_ptr<Vehicle>& vehicle) override;
};