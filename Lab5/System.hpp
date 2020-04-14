//
// Created by Timur Oshnokov on 2019-04-24.
//

#ifndef PROGRAMMING_SYSTEM_HPP
#define PROGRAMMING_SYSTEM_HPP

#include <vector>
#include "Circle.hpp"
#include "Trapeze.hpp"
#include "CVector2D.hpp"

using namespace std;

class System {
public:
    CVector2D *centreMass = new CVector2D(0.0, 0.0);

    vector<Circle> circleArray;
    vector<Trapeze> trapezeArray;

    void addFigure();

    void showAll();

    void showSummSquare();

    void showSummPerimeter();

    void showSummSize();

    void sortByMass();

    void showCentreMass();

};


#endif //PROGRAMMING_SYSTEM_HPP
