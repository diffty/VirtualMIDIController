
//
//  SpaceManager.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__SpaceManager__
#define __TouchPadTest__SpaceManager__

#include <iostream>
#include <vector>
#include "UI.h"
#include "Space.h"
#include "appTypes.h"
#include "InputManager.h"

#endif /* defined(__TouchPadTest__SpaceManager__) */


class Space;
class UI;
class MTInterface;

class SpaceManager {
  public:
    SpaceManager(InputManager* inputManager);
    
    void addSpace(Space* space);
    
    Space* getSpace(int n);
    Space* getCurrentSpace();
    int getCurrentSpaceId();
    int getSpaceCount();
    Space* getSpaceAt(ofVec2f pt);
    
    UI* getParentUI();
    
    void onNewTouch(int &n);
    void onRemoveTouch(int &n);
    void onUpdateTouch(int &n);
    
  private:
    vector<Space*> spaces_;
    int currentSpaceId_;
    InputManager* inputManager_;
    vector<int> touchesFirstUse;
};