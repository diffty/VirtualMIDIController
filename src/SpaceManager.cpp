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
        Controller* ctrl = getCurrentSpace()->getCtrlAt(ofVec2f(it->currentTouch->x, it->currentTouch->y));
        
        if(ctrl) {
            ctrl->receiveInput(&(*it));
        }
    }
}