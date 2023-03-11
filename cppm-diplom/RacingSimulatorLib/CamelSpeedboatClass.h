#pragma once
#include "GroundClass.h"
#include"APIExports.h"

class CamelSpeedboat : public Ground {
public:
    RACINGSIMULATORLIB_API CamelSpeedboat();
    RACINGSIMULATORLIB_API ~CamelSpeedboat();
    RACINGSIMULATORLIB_API double calculateMovementTime(double length) override;
};