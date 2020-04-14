//
//  BaseCObject.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef BaseCObject_hpp
#define BaseCObject_hpp

class BaseCObject {
public:
    // Имя класса (типа данных).
    virtual const char *classname() = 0;

    // Размер занимаемой памяти.
    virtual unsigned int size() = 0;
};

#endif /* BaseCObject_h */
