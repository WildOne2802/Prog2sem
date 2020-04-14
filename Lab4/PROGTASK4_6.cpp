//
// Created by timur on 10.04.2019.
//

#include <iostream>
#include <vector>
#include "task4_6.h"
using namespace std;
int main (){
    Vehicle test;
    test.changeDirection();
    cout<<"Enter time:"<<endl;
    int time;
    cin>>time;
    test.run(time);
    cout<<"Current coordinates:"<<endl;
    cout<<"("<<test.get_coordinates().x<<","<<test.get_coordinates().y<<","<<test.get_coordinates().z<<")"<<endl;
    test.turnONRecording();
    cout<<"Enter new time:"<<endl;
    cin>>time;
    test.run(time);
    test.turnOFFRecording();
    test.getPath();

    Car test1;
    test1.getFuelValue();
    test1.changeDirection();
    int gasoline;
    cout<<"Refill gasoline:"<<endl;
    cin>>gasoline;
    test1.refillFuel(gasoline);
    test1.getFuelValue();
    test1.setFuelConsumption();
    test1.Car::run(10);
    cout<<"Coords"<<endl;
    cout<<test1.get_coordinates().x<<" "<<test1.get_coordinates().y<<" "<<test1.get_coordinates().z<<endl;

    return 0;
}