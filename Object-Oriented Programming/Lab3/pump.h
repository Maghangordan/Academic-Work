#pragma once
#include "wheel.h"
#include "car.h"
#include <string>
#include <iostream>
using namespace std;
#ifndef _pump_
#define _pump_
class Pump
{

public:
    friend class Wheel;
    Pump()
    {

    }
    Pump(int rad)
    {

    }
    friend class Wheel;
    void setPressure(Wheel& someWheel, double somePressure)
    {
        someWheel.pressure = somePressure;

    }
};



#endif _pump_
