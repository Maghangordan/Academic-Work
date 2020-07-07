#include <iostream>
#include <algorithm>
#include <string>
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include <cstdlib>
using namespace std;
int main(int argc, char** argv)
{
    //Ex 1:
    //cout<<"Result: "<<inPiRange(3.149)<<endl;

    //Ex 2:
    /*
    float a[5]={50,12,33,4,2};
    int sizeOfA=sizeof(a)/sizeof(a[0]);
    bSort(a,sizeOfA);
    cout << "Sorted: "; 
    for (int i = 0; i < sizeOfA; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl; 
    */
   
    //Ex 3:
    list<node<double>> myList;
    std::cout<<"Is list empty? "<<myList.empty()<<endl;
    myList.print();
    myList.push_front(new node<double>(6));
    myList.push_front(new node<double>(4));
    myList.push_front(new node<double>(3));
    myList.push_front(new node<double>(2));
    myList.push_front(new node<double>(1));
    std::cout<<"Is list empty? "<<myList.empty()<<endl;
    std::cout<<"No of elements :"<<myList.size()<<endl;
    myList.print();
    std::cout<<"First element : "<<myList.begin()->key<<","<<myList.front().key<<endl;
    std::cout<<"Last element : "<<myList.end()->key<<","<<myList.back().key<<endl;
    myList.clear();
    myList.print();
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(1),0);
    myList.insert(new node<double>(9),1);
    myList.erase(5);
    
    myList.print();
    
    
    
    
    
    

    
    

    
    
    
    

    return 0;
}