#pragma once
#include "VehicleClass.h"

class Ground : public Vehicle {

public:
    Ground();
    ~Ground();
protected:
    unsigned int stamina;

};