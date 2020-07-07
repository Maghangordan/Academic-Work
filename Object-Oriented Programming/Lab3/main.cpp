#include <iostream>
#include "wheel.h"
#include "car.h"
#include "pump.h"

int main(int argc, char* argv[])
{
    /*
	//Ex 2
	Wheel newWheel = Wheel();
    

	//Ex 3
	
    Pump newPump = Pump();
	newPump.setPressure(newWheel, 5);
    */

    //Ex 4 1pt
    /*
    Wheel wheelA = Wheel(1);
    wheelA.setRpm(1);

    Wheel wheelB = Wheel(1);
    wheelB.setRpm(1);

    Wheel wheelC = Wheel(3);
    wheelA.setRpm(1);

    Wheel wheelD = Wheel(1);
    wheelD.setRpm(7);

    //Speed = rad*rpm
    wheelA.operator==(wheelB);  //WheelA speed = 1, Wheel B = 4. 
    wheelA.operator!=(wheelB);
    wheelA.operator<(wheelB);
    wheelA.operator>(wheelB);
    wheelA.operator<=(wheelB);
    wheelA.operator>=(wheelB);
    */

    //Ex 4 2pt
    /*
    Car defCar,aCar;  //default c-tor
    aCar = defCar; //copy assignment c-tor
    
    Car cCar = defCar; //copy c-tor
    //Angular and linear velocities are 1.00000000000000 after going through any of the constructors
    */
    
    //Ex 5
    /*
    Car defCar = Car(); //default constructor
    
    defCar.setName("Default car");
    std::cout << defCar.getName() << "\n";
    Car copyCar = defCar; //Copy constructor
    
    copyCar.setName("Copy car");
    std::cout << copyCar.getName() << "\n";
    Car moveCar(std::move(defCar)); //Move c-tor
    
    moveCar.setName("Move car");
    std::cout << moveCar.getName() << "\n";
    */
    
    //Ex 6
    /*
    Car aCar = Car(); //default constructor
    Car copyCar = aCar; //Using copy constructor

    aCar.setSpeed(123);
    aCar.setTurningAngle(456);

    copyCar.setSpeed(60);
    copyCar.setTurningAngle(45);

    aCar.getRPM();
    aCar.getAngle();

    copyCar.getRPM();
    copyCar.getAngle(); 
    //They are the same. Why? :o

    Car* ptrCar = new Car();
    Car ptrCopyCar = *ptrCar;
    delete ptrCar;
    ptrCopyCar.getAngle(ptrCopyCar); //Works just fine
    ptrCopyCar.getRPM(ptrCopyCar); //Works just fine
    */

    //Ex 6
    /*
   Car* car = new Car();
   Car* carCopy = new Car(*car); //Deep copy syntax?
   
   car->setSpeed(678);
   carCopy->setSpeed(200);
   car->getRPM();
   carCopy->getRPM();
    */
}