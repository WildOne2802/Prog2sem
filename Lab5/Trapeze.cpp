//
//  Trapeze.cpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#include "Trapeze.hpp"
#include "Circle.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Trapeze::Trapeze(){
    this->left_top_corner = CVector2D(0,0);
    this->left_bottom_corner = CVector2D(0,0);
    this->right_top_corner = CVector2D(0,0);
    this->right_bottom_corner = CVector2D(0,0);
    this->mas=0;
}

Trapeze::Trapeze(CVector2D &left_top_corner, CVector2D &left_bottom_corner, CVector2D &right_top_corner, CVector2D &right_bottom_corner, double &mas){
    this->left_top_corner = left_bottom_corner;
    this->left_bottom_corner = left_bottom_corner;
    this->right_top_corner = right_top_corner;
    this->right_bottom_corner = right_bottom_corner;
    this->mas = mas;

    height = abs((right_top_corner.y) - (right_bottom_corner.y));
    top_line = abs((right_top_corner.x) - (left_top_corner.x));
    bottom_line = abs((right_bottom_corner.x) - (left_bottom_corner.x));
}

Trapeze::~Trapeze(){

}

const char *Trapeze::classname()
{
    return "Trapeze";
}

unsigned int Trapeze::size()
{
    return sizeof(Trapeze);
}

void Trapeze::initFromDialog(){

    cout<<"Enter x and y for left top corner\n";
    cin>>this->left_top_corner.x>>this->left_top_corner.y;

    cout<<"Enter x and y for left bottom corner\n";
    cin>>this->left_bottom_corner.x>>this->left_bottom_corner.y;

    cout<<"Enter x and y for right top corner\n";
    cin>>this->right_top_corner.x>>this->right_top_corner.y;

    cout<<"Enter x and y for right bottom corner\n";
    cin>>this->right_bottom_corner.x>>this->right_bottom_corner.y;

    cout<<"Enter mass\n";
    cin>>this->mas;

    height = abs((this->right_top_corner.y) - (this->right_bottom_corner.y));
    top_line = abs((this->right_top_corner.x) - (this->left_top_corner.x));
    bottom_line = abs((this->right_bottom_corner.x) - (this->left_bottom_corner.x));
}

double Trapeze::square(){
    return ((this->top_line + this->bottom_line) / 2 * this->height);
}

double Trapeze::mass(){
    return this->mas;
}

bool Trapeze::operator==(IPhysObject &ob)
{
    if (mas == ob.mass())
        return true;
    else
        return false;
}

bool Trapeze::operator<(IPhysObject &ob)
{
    if (mas < ob.mass())
        return true;
    else
        return false;
}

void Trapeze::draw()
{
    cout << "Classname: " << classname()
         << "\nSquare: " << square()
         << "\nHeight: " << height
         << "\nPerimeter: " << perimeter()
         << "\nMass:" << mass()
         << "\nSize: " << size() << " bytes\n"
         << "Position:" << "x:" << position().x << " y:"
         << position().y << endl;
}

double Trapeze::perimeter()
{
    return top_line + bottom_line +
           sqrt(pow(abs(left_top_corner.x) - abs(left_bottom_corner.x), 2) + pow(height, 2)) +
           sqrt(pow(abs(right_top_corner.x) - abs(right_bottom_corner.x), 2) + pow(height, 2));
}

CVector2D Trapeze::position()
{
    return CVector2D(top_line != bottom_line ?
                     (height / 3) * (2 * max(top_line, bottom_line) + min(top_line, bottom_line)) /
                     (top_line + bottom_line) : pow(top_line,2), left_bottom_corner.x/2);
}


