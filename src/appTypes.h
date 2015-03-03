#pragma once

//
//  appTypes.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#ifndef TouchPadTest_ofTypes_h
#define TouchPadTest_ofTypes_h


#endif



typedef struct Touch {
    int id, frame;
    float angle, size, x, y;
    Touch(): id(-1), frame(0), x(0), y(0), angle(0.f), size(0.f) {}
} Touch;

template<class CallbackClass>
struct CallbackFunc {
    CallbackClass* callbackObj;
    void (CallbackClass::*callbackMethod)(int);
    CallbackFunc() : callbackObj(NULL), callbackMethod(NULL) {}
};

struct MTFinger {
    int id;
    Touch* currentTouch;
    int nbFrames;
    std::time_t birthTime;
    bool used;
    
    MTFinger(): id(-1), birthTime(std::time(0)), currentTouch(NULL), used(false) {}
};