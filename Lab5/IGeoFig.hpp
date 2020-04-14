//
//  IGeoFig.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef IGeoFig_hpp
#define IGeoFig_hpp

class IGeoFig {
public:
    // Площадь.
    virtual double square() = 0;
    // Периметр.
    virtual double perimeter() = 0;
};

#endif /* IGeoFig_h */
