#pragma once
#include "GroundClass.h"

class Camel : public Ground {
public:
    Camel();
    ~Camel();
    double calculateMovementTime(double length) override;

private:
};