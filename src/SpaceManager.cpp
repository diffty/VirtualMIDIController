//
//  SpaceManager.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "SpaceManager.h"
#include "MTInterface.h"


SpaceManager::SpaceManager(InputManager* inputManager) {
    inputManager_ = inputManager;
    currentSpaceId_ = -1;
    navBarSize_ = 30;
    
    ofAddListener(inputManager_->getInputInterface()->getPad()->touchAdded, this, &SpaceManager::onNewTouch);
    ofAddListener(inputManager_->getInputInterface()->getPad()->touchRemoved, this, &SpaceManager::onRemoveTouch);
    ofAddListener(inputManager_->getInputInterface()->getPad()->update, this, &SpaceManager::onUpdateTouch);
}

void SpaceManager::addSpace(Space* space) {
    spaces_.push_back(space);
    
    if(spaces_.size() == 1) {
        currentSpaceId_ = 0;
    }
}

Space* SpaceManager::getSpace(int n) {
    return spaces_.at(n);
}

int SpaceManager::getCurrentSpaceId() {
    return currentSpaceId_;
}

Space* SpaceManager::getCurrentSpace() {
    if(spaces_.size() > 0) {
        return spaces_.at(currentSpaceId_);
    }
    return NULL;
}

int SpaceManager::getSpaceCount() {
    return spaces_.size();
}

int SpaceManager::getNavBarSize() {
    return navBarSize_;
}

Rect SpaceManager::getNavBarRect() {
    Rect navBarRect;
    
    navBarRect.top = 0;
    navBarRect.left = 0;
    navBarRect.right = ofGetWidth();
    navBarRect.bottom = navBarSize_;
    
    return navBarRect;
}

void SpaceManager::setNavBarSize(int size) {
    navBarSize_ = size;
}

void SpaceManager::setCurrentSpace(int spaceId) {
    if(0 <= spaceId && spaceId < getSpaceCount()) {
        std::cout << "Switching to space " << spaceId << std::endl;
        currentSpaceId_ = spaceId;
    }
}

void SpaceManager::onNavBarTouch(const MTFinger& finger) {
    float navBarTouchDelta = finger.currentTouch->x - finger.firstTouch.x;

    if(navBarTouchDelta >= 0.1) {
        setCurrentSpace(currentSpaceId_ + 1);
    }
    else if(navBarTouchDelta <= -0.1 && currentSpaceId_ - 1 >= 0) {
        setCurrentSpace(currentSpaceId_ - 1);
    }
}

// NE PAS OUBLIER LE &. . . .
void SpaceManager::onNewTouch(int &n) {
    inputManager_->getInputInterface()->refreshFingers();
}

void SpaceManager::onRemoveTouch(int &n) {
    inputManager_->getInputInterface()->refreshFingers();
}

void SpaceManager::onUpdateTouch(int &n) {
    inputManager_->getInputInterface()->refreshFingers();

    vector<Touch> touches = inputManager_->getInputInterface()->getTouches();
    vector<MTFinger>* fingers = inputManager_->getInputInterface()->getFingers();

    for (vector<MTFinger>::iterator it = fingers->begin(); it != fingers->end(); ++it) {
        Controller* ctrl = getCurrentSpace()->getCtrlAt(ofVec2f(it->firstTouch.x, it->firstTouch.y));
        
        Rect navBarRect = getNavBarRect();
        ofVec2f ptInScreen = ofVec2f(it->firstTouch.x * ofGetWidth(), it->firstTouch.y * ofGetHeight());
        
        if(navBarRect.left <= ptInScreen.x
           && navBarRect.right >= ptInScreen.x
           && navBarRect.top <= ptInScreen.y
           && navBarRect.bottom >= ptInScreen.y) {

            onNavBarTouch(*it);
        }
        else if(ctrl) {
            ctrl->receiveInput(&(*it));
        }
    }
}