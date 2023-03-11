#pragma once
#include "string"
#include <vector>
#include <iostream>
#include"APIExports.h"

class Vehicle {

public:

    RACINGSIMULATORLIB_API Vehicle();

    RACINGSIMULATORLIB_API ~Vehicle();
    
    RACINGSIMULATORLIB_API std::string getVehicleName();
    
    RACINGSIMULATORLIB_API double virtual calculateMovementTime(double length);
    
    RACINGSIMULATORLIB_API bool operator> (Vehicle& right);
    
    RACINGSIMULATORLIB_API std::unique_ptr<Vehicle>* getParChildPtr();

    RACINGSIMULATORLIB_API void setParChildPtr(std::unique_ptr<Vehicle>* _par_child);

    RACINGSIMULATORLIB_API void setResult(double _result);

    RACINGSIMULATORLIB_API double getResult();

protected:
    unsigned int velocity;
    std::string name;
    std::unique_ptr<Vehicle>* par_child = nullptr;
    double result = 0.0;
};