//
//  UI.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "UI.h"
#include "SpaceManager.h"
#include "InputManager.h"


UI::UI(InputManager* inputManager) {
    inputManager_ = inputManager;
}

void UI::draw() {
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    ofSetColor(0,0,0,16);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    if(spaceManager_->getSpaceCount() >= 0) {
        drawSpace(spaceManager_->getCurrentSpace());
    }
    
    drawNavBar();
    
    ofSetColor(255,255,255);
    //ofDrawBitmapString("TouchCount: " + ofToString(touch_->getPad()->getTouchCount(), 0), 20, 20);
}

void UI::drawSpace(Space* space) {
    for(int i = 0; i < space->getDivCount(); i++) {
        Rect divRect = space->getDivRect(i);
        
        Controller* ctrl = space->getController(i);
        
        ofSetColor(ctrl->getColor());
        ofRect(divRect.left, divRect.top, divRect.right-divRect.left, divRect.bottom-divRect.top);
    }
}

void UI::drawNavBar() {
    Space* currentSpace = spaceManager_->getCurrentSpace();
    for(int i = 0; i < currentSpace->getDivCount(); i++) {
        Rect divRect = currentSpace->getDivRect(i);
        
        Controller* ctrl = currentSpace->getController(i);
        
        ofSetColor(0, 255, 0);
        ofRect(divRect.left+1, 1, divRect.right-divRect.left-1, spaceManager_->getNavBarSize()-1);
    }
}

void UI::setSpaceManager(SpaceManager* spaceManager) {
    spaceManager_ = spaceManager;
}

Rect UI::getWindowRect() {
    Rect screenSize;
    
    screenSize.top = 0.;
    screenSize.left = 0.;
    screenSize.right = (float) ofGetWidth();
    screenSize.bottom = (float) ofGetHeight();
    
    return screenSize;
}

SpaceManager* UI::getSpaceManager() {
    return spaceManager_;
}