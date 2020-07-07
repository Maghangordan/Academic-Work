#pragma once
#include "wheel.h"
#include "pump.h"
#include <string>
#include <iostream>
using namespace std;
#ifndef _car_
#define _car_

class Car
{
private:
    int weight;
    std::string model;
    double linearVelocity;
    double angularVelocity;
    Wheel* flWheel;
    Wheel* frWheel;
    Wheel* rlWheel;
    Wheel* rrWheel;

public:
    enum Color { red, green, blue };

private:
    Car::Color carColor;

public:

    Car::Color setColor(Color c)
    {
        carColor = c;
        return carColor;
    }
    Car::Color getColor()
    {
        return carColor;
    }
    Car() //default constructor
    {
        weight = 1000;
        linearVelocity = 1;
        angularVelocity = 1;
        this->flWheel = new Wheel();
        this->frWheel = new Wheel();
        this->rlWheel = new Wheel();
        this->rrWheel = new Wheel();
        carColor = red;
        model = "Volvo";
        printf("Default c-tor called\n");
    };
    ~Car()
    {
        delete flWheel;
        delete frWheel;
        delete rlWheel;
        delete rrWheel;
        printf("Destructor is called\n");
    }
    Car(const Car& someCar) //copy constructor
    {
        weight = someCar.weight;
        model = someCar.model;
        linearVelocity = someCar.linearVelocity;
        angularVelocity = someCar.angularVelocity;
        flWheel = new Wheel(someCar.flWheel->getRadius());
        frWheel = new Wheel(someCar.frWheel->getRadius());
        rlWheel = new Wheel(someCar.rlWheel->getRadius());
        rrWheel = new Wheel(someCar.rrWheel->getRadius());
        carColor = someCar.carColor;
        printf("Copy C-tor called\n");
    }
    Car& operator= (const Car& someCar) //copy assignment operator
    {
        if (this != &someCar)
        {
            delete flWheel;
            delete frWheel;
            delete rlWheel;
            delete rrWheel;

            weight = someCar.weight;
            model = someCar.model;
            linearVelocity = someCar.linearVelocity;
            angularVelocity = someCar.angularVelocity;

            flWheel = new Wheel(someCar.flWheel->getRadius());
            frWheel = new Wheel(someCar.frWheel->getRadius());
            rlWheel = new Wheel(someCar.rlWheel->getRadius());
            rrWheel = new Wheel(someCar.rrWheel->getRadius());
        }
        

        std::cout << "Copy assignment operator called\n";
        return *this;
    }
    Car(Car&& obj) noexcept // Move constructor
    {
        weight = obj.weight;
        model = obj.model;
        linearVelocity = obj.linearVelocity;
        angularVelocity = obj.angularVelocity;
        flWheel = obj.flWheel;
        frWheel = obj.frWheel;
        rlWheel = obj.rlWheel;
        rrWheel = obj.rrWheel;
        carColor = obj.carColor;

        obj.weight = 1000;
        obj.linearVelocity = 1;
        obj.angularVelocity = 1;
        obj.flWheel = nullptr;
        obj.frWheel = nullptr;
        obj.rlWheel = nullptr;
        obj.rrWheel = nullptr;
        carColor = red;
        model = "Volvo";
        printf("MC-tor called\n");
        
    }
    
    Car& operator=(Car&& obj) noexcept //Move assignment operator
    {
        if (this != &obj) //We don't want to move assign it to itself
        {
            delete flWheel;
            delete frWheel;
            delete rlWheel;
            delete rrWheel;

            weight = obj.weight;
            model = obj.model;
            linearVelocity = obj.linearVelocity;
            angularVelocity = obj.angularVelocity;
            flWheel = obj.flWheel;
            frWheel = obj.frWheel;
            rlWheel = obj.rlWheel;
            rrWheel = obj.rrWheel;
            carColor = obj.carColor;

            obj.weight = 1000;
            obj.linearVelocity = 1;
            obj.angularVelocity = 1;
            obj.flWheel = nullptr;
            obj.frWheel = nullptr;
            obj.rlWheel = nullptr;
            obj.rrWheel = nullptr;
            carColor = red;
            model = "Volvo";
        }
        std::cout<<"MA-OP called\n";
        return *this;
    }

    Car(int w, string mod, double linVel, double angVel, Color c) //non-default constructor
    {
        weight = w;
        model = mod;
        linearVelocity = linVel;
        angularVelocity = angVel;
        carColor = c;
        printf("Non-default constructor called\n");
    }
    void setName(string name)
    {
        model = name;
    }
    string getName()
    {
        return this->model;
    }

    bool setSpeed(double speed)
    {
        this->linearVelocity = speed;
        this->flWheel->setRpm(speed);
        this->frWheel->setRpm(speed);
        this->rlWheel->setRpm(speed);
        this->rrWheel->setRpm(speed);
        return true;
    }
    double getRPM()
    {
        std::cout << "FL Wheel RPM: " << this->flWheel->getRpm() << "\n";
        std::cout << "FR Wheel RPM: " << this->frWheel->getRpm() << "\n";
        std::cout << "RL Wheel RPM: " << this->rlWheel->getRpm() << "\n";
        std::cout << "RR Wheel RPM: " << this->rrWheel->getRpm() << "\n";
        return 0;

    }
    bool setTurningAngle(double angle)
    {
        angularVelocity = angle;
        this->flWheel->setAngle(angle);
        this->frWheel->setAngle(angle);
        this->rlWheel->setAngle(angle);
        this->rrWheel->setAngle(angle);
        return true;
    }
    double getAngle()
    {
        std::cout << "FL Wheel Angle: " << this->flWheel->getAngle() << "\n";
        std::cout << "FR Wheel Angle: " << this->frWheel->getAngle() << "\n";
        std::cout << "RL Wheel Angle: " << this->rlWheel->getAngle() << "\n";
        std::cout << "RR Wheel Angle: " << this->rrWheel->getAngle() << "\n";
        return 0;
    }

};



#endif _car_
