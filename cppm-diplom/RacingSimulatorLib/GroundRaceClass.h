#pragma once
#include"RaceClass.h"
#include"GroundClass.h"
#include"APIExports.h"

class GroundRace : public Race {

public:
	RACINGSIMULATORLIB_API GroundRace();
	RACINGSIMULATORLIB_API ~GroundRace();

	RACINGSIMULATORLIB_API bool checkVehicleType(std::unique_ptr<Vehicle>& vehicle) override;
};