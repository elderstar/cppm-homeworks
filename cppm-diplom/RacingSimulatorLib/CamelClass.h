#pragma once
#include "GroundClass.h"
#include"APIExports.h"

class Camel : public Ground {
public:
    RACINGSIMULATORLIB_API Camel();
    RACINGSIMULATORLIB_API ~Camel();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};