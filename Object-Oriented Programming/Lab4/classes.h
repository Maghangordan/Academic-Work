
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#ifndef _WHEEL_H_
#define _WHEEL_H_
class Wheel;
class Pump;
class Car;

class Vehicle
{
public:
    virtual void print()
    {
        std::cout << "Vehicle" << endl;
    }
};

class Car : virtual public Vehicle
{
private:

    class Wheel { double radius, rpm, angle, pressure; };
    Wheel* flWheel;
    Wheel* frWheel;
    Wheel* rlWheel;
    Wheel* rrWheel;

public:
    void print()
    {
        std::cout << "Car" << endl;
    }

};

class Bike : public Vehicle
{
public:
    void print()
    {
        std::cout << "Bike" << endl;
    }
};

class Boat : virtual public Vehicle
{
    void print()
    {
        std::cout << "Boat" << endl;
    }
};

class Amphicar : public Boat, public Car
{
    void print()
    {
        std::cout << "Amphicar" << endl;
    }
};

class Wheel
{
    friend class Pump;
private:
    double radius, rpm, angle, pressure;
public:
    Wheel()
    {
        radius = rpm = angle = pressure = 1;
    }
    Wheel(double rad)
    {
        radius = rad;
        rpm = angle = pressure = 1;
    }
    bool setRpm(double r)
    {
        rpm = r;
        if (rpm == r)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    double getRpm()
    {
        return rpm;
    }
    bool setAngle(double a)
    {
        angle = a;
        if (angle == a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    double getRadius()
    {
        return radius;
    }

};
class Pump
{
public:

    double setPressure(Wheel& w, double p)
    {
        w.pressure = p;
        return p;
    }
};


#endif // _WHEEL_H_