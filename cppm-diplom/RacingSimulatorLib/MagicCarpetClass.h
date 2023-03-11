#pragma once
#include "AircraftClass.h"
#include"APIExports.h"

class MagicCarpet : public Aircraft {
public:
    RACINGSIMULATORLIB_API MagicCarpet();
    RACINGSIMULATORLIB_API ~MagicCarpet();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};