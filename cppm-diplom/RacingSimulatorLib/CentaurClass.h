#pragma once
#include "GroundClass.h"
#include"APIExports.h"

class Centaur : public Ground {
public:
    RACINGSIMULATORLIB_API Centaur();
    RACINGSIMULATORLIB_API ~Centaur();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};