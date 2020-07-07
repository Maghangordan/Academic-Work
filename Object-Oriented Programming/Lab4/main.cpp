#include <iostream>
#include "classes.h"
#include <fstream>
#include <string>
int main(int argc, char* argv[])
{

    /*
    Vehicle * v1 = new Car();
    Vehicle * v2 = new Bike();
    Vehicle * v3 = new Vehicle();
    v1->print();
    v2->print();
    v3->print();
    */
    /* Ex. 4
    Vehicle * v4 = new Boat();
    Vehicle * v5 = new Amphicar();
    v4->print();
    v5->print();
    */
    
    Vehicle* obj[7] = { new Amphicar(),new Amphicar(), new Amphicar(), new Amphicar(), new Amphicar(), new Amphicar(), new Amphicar() };
    int temp = 0;
    string str;
    ifstream inFile;
    inFile.open("vehicles.txt");
    while (getline(inFile, str))
    {
        if (str == "car")
        {
            obj[temp] = new Car(); temp++;
        }
        if (str == "amphicar")
        {
            obj[temp] = new Amphicar(); temp++;
        }
        if (str == "bike")
        {
            obj[temp] = new Bike(); temp++;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        obj[i]->print();
        delete obj[i];
    }

    inFile.close();


    return 0;

}