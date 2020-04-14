//
//  IPrintable.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef IPrintable_hpp
#define IPrintable_hpp

class IPrintable {
public:
    // Отобразить на экране
    // (выводить в текстовом виде параметры фигуры).
    virtual void draw() = 0;
};

#endif /* IPrintable_h */
