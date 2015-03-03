//
//  InputManager.h
//  TouchPadTest
//
//  Created by DiFFtY on 23/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__InputManager__
#define __TouchPadTest__InputManager__

#include <stdio.h>
//#include "MTInterface.h"

#endif /* defined(__TouchPadTest__InputManager__) */

class MTInterface;

class ofApp;

class InputManager {
  public:
    InputManager();
    
    void setInputInterface(MTInterface* interface);
    MTInterface* getInputInterface();
    
  private:
    MTInterface* interface_;
    ofApp* app_;
};