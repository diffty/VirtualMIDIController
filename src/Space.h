//
//  Space.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__Space__
#define __TouchPadTest__Space__

#include <stdio.h>
#include <vector.h>
#include "MacTypes.h"
#include "Controller.h"
#include "SpaceManager.h"
#include "appTypes.h"

#endif /* defined(__TouchPadTest__Space__) */


class SpaceManager;

class Space {
  public:
    Space(int nDiv, SpaceManager* parentManager);
    
    void addController(Controller ctrl);
    
    Controller* getController(int n);
    Rect getDivRect(int n);
    Rect getSingleDivRect();
    int getDivCount();
    Controller* getCtrlAt(ofVec2f pt);
    SpaceManager* getParentManager();
    
  private:
    vector<Controller> ctrlList_;
    int nDiv;
    SpaceManager* parentManager_;
};