#pragma once
#include "GroundClass.h"
#include"APIExports.h"

class AllTerrainBoots : public Ground {
public:
    RACINGSIMULATORLIB_API AllTerrainBoots();
    RACINGSIMULATORLIB_API ~AllTerrainBoots();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};