//
// Created by timur on 10.04.2019.
//

#ifndef PROGRAMMING_2_SEMESTER_TASK4_6_H
#define PROGRAMMING_2_SEMESTER_TASK4_6_H

#include <vector>
using namespace std;

typedef struct{
    double x,y,z;
}v;

class Vehicle{
private:
    v direction;
    v coordinates{0,0,0};
    vector <v> path;
    bool record = false;
    int interval = 0;
    int intervalRec = 0;
public:
    void changeDirection();
    void run (int time);
    void turnONRecording ();
    void turnOFFRecording ();
    void getPath();
    v get_direction();
    v get_coordinates();
    vector <v> get_path();
    bool get_record();
    int get_interval();
    int get_intervalRec();
    void set_coordinates(v coords);
    void set_intervalRec(int rec);
    Vehicle (){};
    Vehicle (v direction, v coordinates, bool record, int interval, int intervalRec){
      this -> direction = direction;
      this -> coordinates = coordinates;
      this -> record = record;
      this -> interval = interval;
      this -> intervalRec = intervalRec;
    };
};

class Car:public Vehicle{
private:
    double fuel=0;
    double fuelConsumption=0;
public:
    void getFuelValue();
    void refillFuel(int gasoline);
    void run(int time);
    void setFuelConsumption();
    Car (){};
};


#endif //PROGRAMMING_2_SEMESTER_TASK4_6_H
