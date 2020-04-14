//
// Created by Timur Oshnokov on 2019-04-22.
//

#ifndef PROGRAMMING_CIRCLE_HPP
#define PROGRAMMING_CIRCLE_HPP

#include "IGeoFig.hpp"
#include "CVector2D.hpp"
#include "IPrintable.hpp"
#include "IPhysObject.hpp"
#include "IDialogInitable.hpp"
#include "BaseCObject.hpp"

class Circle : IPhysObject,IGeoFig,IPrintable,IDialogInitiable,BaseCObject,CVector2D {
public:
    CVector2D centre;
    double radius;
    double mas;

    Circle ();
    Circle (CVector2D &centre, double &radius);
    ~Circle ();

    const char *classname();
    unsigned int size();
    void initFromDialog();
    double square();
    double perimeter();
    CVector2D position();
    double mass();
    bool operator == (IPhysObject &ob);
    bool operator < (IPhysObject &ob);
    void draw();

};


#endif //PROGRAMMING_CIRCLE_H
