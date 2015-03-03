//
//  Space.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "Space.h"


Space::Space(int nDiv, SpaceManager* parentManager) {
    parentManager_ = parentManager;
}

void Space::addController(Controller ctrl) {
    ctrlList_.push_back(ctrl);
}

Controller* Space::getController(int n) {
    return &ctrlList_.at(n);
}

Rect Space::getDivRect(int n) {
    Rect divRect;
    Rect singleDivRect = getSingleDivRect();
    
    divRect.top = singleDivRect.top;
    divRect.left = singleDivRect.right * (float) n;
    divRect.right = singleDivRect.right * (float) (n+1);
    divRect.bottom = singleDivRect.bottom;
    
    return divRect;
}

int Space::getDivCount() {
    return ctrlList_.size();
}

Rect Space::getSingleDivRect() {
    int nDiv = getDivCount();
    
    Rect singleDivRect;
    singleDivRect.top = 0.;
    singleDivRect.left = 0.;
    singleDivRect.right = (float) ofGetWidth() / (float) nDiv;
    singleDivRect.bottom = ofGetHeight();
    
    return singleDivRect;
}

Controller* Space::getCtrlAt(ofVec2f pt) {
    Controller* ctrl = NULL;
    for(int i = 0; i < getDivCount(); i++) {
        ofVec2f ptInScreen = ofVec2f(pt.x * ofGetWidth(), pt.y * ofGetHeight());
        Rect currentDivRect = getDivRect(i);
        
        if(currentDivRect.left <= ptInScreen.x
                && currentDivRect.right >= ptInScreen.x
                && currentDivRect.top <= ptInScreen.y
                && currentDivRect.bottom >= ptInScreen.y) {
            
            ctrl = &ctrlList_.at(i);
            break;
        }
    }
    
    return ctrl;
}

SpaceManager* Space::getParentManager() {
    return parentManager_;
}