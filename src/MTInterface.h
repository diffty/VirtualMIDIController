//
//  MTInterface.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__MTInterface__
#define __TouchPadTest__MTInterface__

#include <stdio.h>
#include <ctime>
#include "ofxMultiTouchPad.h"
#include "appTypes.h"


#endif /* defined(__TouchPadTest__MTInterface__) */


class InputManager;
class SpaceManager;


class MTInterface {
  public:
    MTInterface();
    
    vector<Touch> getTouches();
    Touch getTouch(int n);
    Touch getTouchFromId(int id);
    ofxMultiTouchPad* getPad();
    MTFinger* getFinger(int id);
    int getFingerCount();
    vector<MTFinger>* getFingers();

    
    void onNewTouch(int &n);
    void onRemoveTouch(int &n);

    void refreshFingers();
    
  private:
    ofxMultiTouchPad pad_;
    InputManager* inputManager_;
    vector<MTFinger> fingers_;
};