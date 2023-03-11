#pragma once
#include "AircraftClass.h"
#include"APIExports.h"

class Eagle : public Aircraft {
public:
    RACINGSIMULATORLIB_API Eagle();
    RACINGSIMULATORLIB_API ~Eagle();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
private:
};