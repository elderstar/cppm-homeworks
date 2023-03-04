#pragma once
#include "GroundClass.h"

class AllTerrainBoots : public Ground {
public:
    AllTerrainBoots();
    ~AllTerrainBoots();
    double calculateMovementTime(double length) override;
private:
};