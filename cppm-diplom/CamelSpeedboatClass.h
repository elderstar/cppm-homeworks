#pragma once
#include "GroundClass.h"

class CamelSpeedboat : public Ground {
public:
    CamelSpeedboat();
    ~CamelSpeedboat();
    double calculateMovementTime(double length) override;

private:
};