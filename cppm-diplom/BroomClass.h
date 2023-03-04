#pragma once
#include "AircraftClass.h"

class Broom : public Aircraft {
public:
    Broom();
    ~Broom();
    double calculateMovementTime(double length) override;
private:
};