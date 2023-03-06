#pragma once
#include "VehicleClass.h"

class Aircraft : public Vehicle {

public:
    Aircraft();
    ~Aircraft();
    std::unique_ptr<Vehicle>* getParChildPtr();

protected:
};