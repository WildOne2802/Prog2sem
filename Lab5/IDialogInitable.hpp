//
//  IDialogInitable.hpp
//  Lab5
//
//  Created by Timur Oshnokov on 21/04/2019.
//  Copyright © 2019 Timur Oshnokov. All rights reserved.
//

#ifndef IDialogInitable_hpp
#define IDialogInitable_hpp

class IDialogInitiable {
    
public:
    
    // Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};

#endif /* IDialogInitable_h */
