//
//  UI.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__UI__
#define __TouchPadTest__UI__

#include <stdio.h>
#include "ofMain.h"
#include "MacTypes.h"
#include "MTInterface.h"
#include "Space.h"

#endif /* defined(__TouchPadTest__UI__) */

class InputManager;
class SpaceManager;
class Space;

class UI {
  public:
    UI(InputManager* inputManager);
    
    void draw();
    
    void drawSpace(Space* space);

    void setSpaceManager(SpaceManager* spaceManager);
    
    Rect getWindowRect();
    SpaceManager* getSpaceManager();
    
  private:
    SpaceManager* spaceManager_;
    InputManager* inputManager_;
};