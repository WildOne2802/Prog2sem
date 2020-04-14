//
//  IPhysObject.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef IPhysObject_hpp
#define IPhysObject_hpp

#include "CVector2D.hpp"

class IPhysObject {
public:
    // Масса, кг.
    virtual double mass() = 0;
    // Координаты центра масс, м.
    virtual CVector2D position() = 0;
    // Сравнение по массе.
    virtual bool operator==(IPhysObject& ob ) = 0;
    // Сравнение по массе.
    virtual bool operator<(IPhysObject& ob ) = 0;
};

#endif /* IPhysObject_h */
