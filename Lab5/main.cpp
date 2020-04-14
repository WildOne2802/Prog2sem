//
//  main.cpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#include <iostream>
#include "Trapeze.hpp"
#include "Circle.hpp"
#include "System.hpp"
using namespace std;

int main() {
    System system;

    system.addFigure();             //Динамическое добавление фигур пользователем.
    system.addFigure();
    system.addFigure();
    system.addFigure();

    system.showSummSize();          //Память, занимаемая всеми экземплярами классов.

    system.showSummSquare();        //Суммарная площадь всех фигур.

    system.showSummPerimeter();     //Суммарный периметр всех фигур.

    system.showAll();               //Отобразить все фигуры.

    system.sortByMass();            //Сортировка фигур по массе.

    system.showAll();

    system.showCentreMass();        //Центр масс всей системы.

   return 0;
}
