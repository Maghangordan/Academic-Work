#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef _WHEEL_H_
#define _WHEEL_H_

class Wheel
{
private:
	double radius, rpm, angle, pressure;
public:
    friend class Pump;
    friend class Car;
    Wheel() //Default constructor
    {
        radius = rpm = angle = pressure = 1;
    }; 
    Wheel(int rad) //Non-default constructor
    {
        radius = rad;
        rpm = angle = pressure = 1;
    };

    double getRpm()
    {
        return rpm;
    }
    bool setRpm(int someRpm)
    {
        rpm = someRpm;
        if (rpm == someRpm)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    double getAngle()
    {
        return angle;
    }
    
    bool setAngle(int someAngle)
    {
        this->angle = someAngle;
        if (this->angle == someAngle)
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
    
    bool operator==(const Wheel& secondWheel) const
    {
        
        if ((this->radius*this->rpm) == (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First and second ARE Equal\n";
            return true;
        }
        else
        {
            std::cout << "First and second are NOT Equal\n";
            return false;
        }

    }
    bool operator!=(const Wheel& secondWheel) const
    {
        
        if ((this->radius * this->rpm) != (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First and second NOT Equal\n";
            return true;
        }
        else
        {
            std::cout << "First and second ARE Equal\n";
            return false;
        }

    }
    bool operator<(const Wheel& secondWheel) const
    {
       
        if ((this->radius * this->rpm) < (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First IS smaller than second wheel\n";
            return true;
        }
        else
        {
            std::cout << "First is NOT smaller than second wheel\n";
            return false;
        }
    }
    bool operator>(const Wheel& secondWheel) const
    {
        
        if ((this->radius * this->rpm) > (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First IS greater than second wheel\n";
            return true;
        }
        else
        {
            std::cout << "First is NOT greater than second wheel\n";
            return false;
        }
    }
    bool operator<=(const Wheel& secondWheel) const
    {
        
        if ((this->radius * this->rpm) <= (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First IS less-or-equal to second wheel\n";
            return true;
        }
        else
        {
            std::cout << "First is NOT less-or-equal to second wheel\n";
            return false;
        }
    }
    bool operator>=(const Wheel& secondWheel) const
    {
        
        if ((this->radius * this->rpm) >= (secondWheel.radius * secondWheel.rpm))
        {
            std::cout << "First IS greater-or-equal to second wheel\n";
            return true;
        }
        else
        {
            std::cout << "First is NOT greater-or-equal to second wheel\n";
            return true;
        }
    }
};



#endif // _WHEEL_H_