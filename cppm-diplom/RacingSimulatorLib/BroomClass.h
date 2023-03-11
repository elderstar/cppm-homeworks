#pragma once
#include "AircraftClass.h"
#include"APIExports.h"

class Broom : public Aircraft {
public:
    RACINGSIMULATORLIB_API Broom();
    RACINGSIMULATORLIB_API ~Broom();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};