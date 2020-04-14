//
// Created by Timur Oshnokov on 2019-04-22.
//

#include "Circle.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle() {
    this->centre = CVector2D(0,0);
    this->radius = 0.0;
    this->mas=0;
}

Circle::Circle(CVector2D &centre, double & radius){
    this->centre = centre;
    this->radius = radius;
}

Circle::~Circle(){

}

const char *Circle::classname()
{
    return "Circle";
}

unsigned int Circle::size()
{
    return sizeof(Circle);
}

void Circle::initFromDialog(){

    cout<<"Enter x and y for centre \n";
    cin>>this->centre.x>>this->centre.y;
    cout<<"Enter radius\n";
    cin>>this->radius;
    cout<<"Enter mass\n";
    cin>>this->mas;
}

double Circle::square(){
    return (M_PI*radius*radius);
}

double Circle::mass(){
    return this->mas;
}

bool Circle::operator==(IPhysObject &ob)
{
    if (mas == ob.mass())
        return true;
    else
        return false;
}

bool Circle::operator<(IPhysObject &ob)
{
    if (mas < ob.mass())
        return true;
    else
        return false;
}

void Circle::draw()
{
    cout << "Classname: " << classname()
         << "\nSquare: " << square()
         << "\nPerimeter: " << perimeter()
         << "\nMass: " << mass()
         << "\nSize: " << size() << " bytes\n"
         << "Position: " << "x:" << position().x << " y:"
         << position().y << endl;
}

double Circle::perimeter()
{
    return (2.0 * M_PI * radius);
}

CVector2D Circle::position()
{
    return this->centre;
}
