//
// Created by Timur Oshnakov on 2019-04-24.
//

#include <iostream>
#include <algorithm>
#include "System.hpp"
#include "Trapeze.hpp"
#include "Circle.hpp"
#include "CVector2D.hpp"
#include <cmath>

using namespace std;

void System::showAll() {
    cout<<"Here are your Circles\n";
    for (Circle c : circleArray){
        c.draw();
        cout<<endl;
    }
    cout<<"Here are your Trapezes\n";
    for (Trapeze t: trapezeArray){
        t.draw();
        cout<<endl;
    }
}

void System::addFigure() {
    int command;

    while (true) {
        cout << "What type of figure do you want to add?\n[1] Circle\n[2] Trapeze\n";
        cin >> command;
        if (command == 1) {
            Circle newCircle;
            newCircle.initFromDialog();
            circleArray.push_back(newCircle);
            return;
        }
        if (command == 2) {
            Trapeze newTrapeze;
            newTrapeze.initFromDialog();
            trapezeArray.push_back(newTrapeze);
            return;
        }
        if (command > 2) {
            cout << "wrong input, try again";
        }
    }
}

void System::showSummPerimeter() {
    double perimeter = 0.0;
    for (Circle c : circleArray)
        perimeter += c.perimeter();
    for (Trapeze t : trapezeArray)
        perimeter += t.perimeter();
    cout<<"Here is summ of perimeters of all figures: "<<perimeter<<endl;
}

void System::showSummSquare() {
    double square = 0.0;
    for (Circle c : circleArray)
        square += c.square();
    for (Trapeze t : trapezeArray)
        square += t.square();
    cout<<"Here is summ of squares of all figures: "<<square<<endl;
}

void System::showSummSize() {
    int size = 0;
    for (Circle c : circleArray)
        size += c.size();
    for (Trapeze t : trapezeArray)
        size += t.size();
    cout<<"Here is summ of sizes of all figures: "<<size<<endl;

}

void System::sortByMass() {
    int j = 0;
    Circle tmp;
    for(int i=0; i<circleArray.size(); i++) {
        j = i;
        for (int k = i; k < circleArray.size(); k++) {
            if (circleArray[j].mass() > circleArray[k].mass()) {
                j = k;
            }
        }
        tmp = circleArray[i];
        circleArray[i] = circleArray[j];
        circleArray[j] = tmp;
    };
    cout<<"Circles are sorted"<<endl<<endl;

    j=0;
    Trapeze tmp1;
    for(int i=0; i<trapezeArray.size(); i++) {
        j = i;
        for (int k = i; k < trapezeArray.size(); k++) {
            if (trapezeArray[j].mass() > trapezeArray[k].mass()) {
                j = k;
            }
        }
        tmp1 = trapezeArray[i];
        trapezeArray[i] = trapezeArray[j];
        trapezeArray[j] = tmp1;
    }
    cout<<"Trapezes are sorted"<<endl<<endl;

}

void System::showCentreMass() {
    double summMassMultPositionX = 0;
    double summMassMultPositionY = 0;
    double summMass = 0;

    for (Trapeze t : trapezeArray)
    {
        summMass += t.mass();
        summMassMultPositionX += t.mass() * t.position().x;
        summMassMultPositionY += t.mass() * t.position().y;
    }

    for (Circle c : circleArray)
    {
        summMass += c.mass();
        summMassMultPositionX += c.mass() * c.position().x;
        summMassMultPositionY += c.mass() * c.position().y;
    }

    centreMass->x = summMassMultPositionX/summMass;
    centreMass->y = summMassMultPositionY/summMass;

    cout<<"Here are coordinates of Mass Centre of your system\n";

    cout<<"x: "<<centreMass->x<<endl;
    cout<<"y:"<<centreMass->y<<endl;


}