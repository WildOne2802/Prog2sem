//
//  Trapeze.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef Trapeze_hpp
#define Trapeze_hpp

#include "IGeoFig.hpp"
#include "CVector2D.hpp"
#include "IPrintable.hpp"
#include "IPhysObject.hpp"
#include "IDialogInitable.hpp"
#include "BaseCObject.hpp"

#include <stdio.h>
class Trapeze : IPhysObject,IGeoFig,IPrintable,IDialogInitiable,BaseCObject{
public:
    CVector2D left_top_corner, left_bottom_corner, right_top_corner, right_bottom_corner;
    double height,top_line, bottom_line, mas;
    
    Trapeze();
    Trapeze(CVector2D &left_top_corner, CVector2D &left_bottom_corner, CVector2D &right_top_corner, CVector2D &right_bottom_corner, double &mas);
    ~Trapeze();
    
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
#endif /* Trapeze_hpp */
