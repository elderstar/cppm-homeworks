#pragma once
#include "GroundClass.h"

class Centaur : public Ground {
public:
    Centaur();
    ~Centaur();
    double calculateMovementTime(double length) override;
private:
};