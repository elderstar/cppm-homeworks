#pragma once
#include "AircraftClass.h"

class Eagle : public Aircraft {
public:
    Eagle();
    ~Eagle();
    double calculateMovementTime(double length) override;
private:
};