//
// Created by timur on 10.04.2019.
//

#include "task4_6.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void Vehicle::changeDirection() {
    cout<<"Enter vector:"<<endl;
    cin>>this->direction.x>>this->direction.y>>this->direction.z;
}
void Vehicle::run (int time){
    if (this->record){
        this->path.push_back(this->coordinates);                // начало пути
        if (this->intervalRec==0)
            this->intervalRec = this->interval;                 // итератор интервала
        while (time!=0) {
            this->coordinates.x = this->coordinates.x + this->direction.x;
            this->coordinates.y = this->coordinates.y + this->direction.y;
            this->coordinates.z = this->coordinates.z + this->direction.z;
            time--;
            intervalRec--;
            if (this->intervalRec==0){
                this->path.push_back(this->coordinates);    //запись координат
                this->intervalRec=this->interval;
            }
        }
    }
    else{
        while (time!=0){
            this->coordinates.x = this->coordinates.x + this->direction.x;
            this->coordinates.y = this->coordinates.y + this->direction.y;
            this->coordinates.z = this->coordinates.z + this->direction.z;
            time--;
        }
    }
}
void Vehicle::turnONRecording (){
    this->record=true;
    cout<<"Enter interval:"<<endl;
    cin>>this->interval;
}
void Vehicle::turnOFFRecording(){
    this->record=false;
    this->intervalRec=0;
    this->interval=0;
}
void Vehicle::getPath(){
    cout<<"Here is your path:"<<endl;
    for(int i=0;i<path.size();i++){
        cout<<"("<<path[i].x<<","<<path[i].y<<","<<path[i].z<<")"<<endl;
    }
}

v Vehicle::get_direction(){
    return this->direction;
};
v Vehicle::get_coordinates(){
    return this->coordinates;
};
vector <v> Vehicle::get_path(){
    return this->path;
};
bool Vehicle::get_record(){
    return this->record;
};
int Vehicle::get_interval(){
    return this->interval;
};
int Vehicle::get_intervalRec(){
    return this->intervalRec;
};
void Vehicle::set_coordinates(v coords) {
    this->coordinates.x = coords.x;
    this->coordinates.y = coords.y;
    this->coordinates.z = coords.z;
}
void Vehicle::set_intervalRec(int rec){
    this->intervalRec = rec;
};

void Car::run(int time) {

    double Scalar = sqrt((get_direction().x * get_direction().x) + (get_direction().y * get_direction().y) + (get_direction().z * get_direction().z));
    cout<<"Scalar "<<Scalar<<endl;

    if (this->fuel==0){
        cout<<"No fuel"<<endl;
        return;
    }

    if (get_record()){
        get_path().push_back(get_coordinates());                // начало пути
        if (get_intervalRec()==0)
            set_intervalRec(get_interval());                 // итератор интервала
        while (time!=0&&this->fuel>0) {
            double x = get_coordinates().x + get_direction().x;
            double y = get_coordinates().y + get_direction().y;
            double z = get_coordinates().z + get_direction().z;
            v coords{x,y,z};
            time--;
            set_intervalRec(get_intervalRec()-1);
            if (get_intervalRec()==0){
                get_path().push_back(coords);    //запись координат
                set_intervalRec(get_interval());
            }
            this->fuel = this->fuel - Scalar*this->fuelConsumption;
        }
    }

    else{
        while (time!=0 && this->fuel>0){
            double x = get_coordinates().x + get_direction().x;
            double y = get_coordinates().y + get_direction().y;
            double z = get_coordinates().z + get_direction().z;
            v coords{x,y,z};
            set_coordinates(coords);
            time--;
            this->fuel= this->fuel - Scalar * this->fuelConsumption;
        }
    }
}
void Car::getFuelValue(){
    cout<<"Fuel level: "<<this->fuel<<" litres"<<endl;
}
void Car::refillFuel(int gasoline){
    this->fuel=this->fuel+gasoline;
}
void Car::setFuelConsumption() {
    cout<<"Enter Fuel consumption: "<<endl;
    cin>>this->fuelConsumption;
}