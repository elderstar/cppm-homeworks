#pragma once
#include "string"
#include <vector>
#include <iostream>
class Vehicle {

public:

    Vehicle();

    ~Vehicle();
    
    std::string getVehicleName();
    
    double virtual calculateMovementTime(double length);
    
    bool operator> (Vehicle& right);
    
    std::unique_ptr<Vehicle>* getParChildPtr();

    void setParChildPtr(std::unique_ptr<Vehicle>* _par_child);

    void setResult(double _result);

    double getResult();

protected:
    unsigned int velocity;
    std::string name;
    std::unique_ptr<Vehicle>* par_child;
    double result;
};