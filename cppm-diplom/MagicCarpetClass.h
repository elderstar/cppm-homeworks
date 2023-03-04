#pragma once
#include "AircraftClass.h"

class MagicCarpet : public Aircraft {
public:
    MagicCarpet();
    ~MagicCarpet();
    double calculateMovementTime(double length) override;
private:
};