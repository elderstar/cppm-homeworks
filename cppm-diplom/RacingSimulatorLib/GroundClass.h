#pragma once
#include "VehicleClass.h"
#include"APIExports.h"

class Ground : public Vehicle {

public:
    RACINGSIMULATORLIB_API Ground();
    RACINGSIMULATORLIB_API ~Ground();

protected:
    unsigned int stamina;
};