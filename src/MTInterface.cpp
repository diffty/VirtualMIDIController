//
//  MTInterface.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "MTInterface.h"


MTInterface::MTInterface() {
    // --- add the listeners
    //ofAddListener(getPad()->touchAdded, this, &MTInterface::onNewTouch);
    //ofAddListener(pad_.touchAdded, this, &MTInterface::onNewTouch);
    //ofAddListener(pad_.touchRemoved, this, &MTInterface::onRemoveTouch);
    //ofAddListener(pad_.update, this, &MTInterface::onUpdateTouch);
}

vector<Touch> MTInterface::getTouches() {
    int tCount = pad_.getTouchCount();
    vector<Touch> touches;
    
    for (int i=0; i < tCount; i++) {
        // get a single touch as MTouch struct....
        MTouch t;
        Touch touch = Touch();

        pad_.getTouchAt(i,&t);
        
        touch.id = t.ID;
        touch.frame = t.frame;
        touch.x = t.x;
        touch.y = t.y;
        touch.angle = t.angle;
        touch.size = t.size;
        
        touches.push_back(touch);
    }
    
    return touches;
}

// @Freddy du futur : PAS COOL LA GESTION DES ERREURS
Touch MTInterface::getTouch(int n) {
    // get a single touch as MTouch struct....
    Touch touch = Touch();
    MTouch t;
    
    pad_.getTouchAt(n,&t);
    
    if(t.ID < 0) {
        std::cout <<  "Warning: Trying to access touch n=" << n << " that doesn't exists." << "\n";
    }
    std::cout << "id:" << t.ID << std::endl;
    touch.id = t.ID;
    touch.frame = t.frame;
    touch.x = t.x;
    touch.y = t.y;
    touch.angle = t.angle;
    touch.size = t.size;
    
    return touch;
}

// Note pour le Freddy du futur : appelation de fonction ? :/
Touch MTInterface::getTouchFromId(int id) {
    Touch touch = Touch();
    
    int tCount = pad_.getTouchCount();
    
    for (int i=0; i < tCount; i++) {
        MTouch t;
        pad_.getTouchAt(i,&t);
        
        if(t.ID == id) {
            touch.id = t.ID;
            touch.frame = t.frame;
            touch.x = t.x;
            touch.y = t.y;
            touch.angle = t.angle;
            touch.size = t.size;
            break;
        }
    }
    return touch;
}

MTFinger* MTInterface::getFinger(int id) {
    for(vector<MTFinger>::iterator it = fingers_.begin(); it != fingers_.end(); ++it) {
        if(it->id == id) {
            return &(*it);
        }
    }
    return NULL;
}

int MTInterface::getFingerCount() {
    return fingers_.size();
}

vector<MTFinger>* MTInterface::getFingers() {
    return &fingers_;
}

ofxMultiTouchPad* MTInterface::getPad() {
    return &pad_;
}

void MTInterface::onNewTouch(int &n) {

}

void MTInterface::onRemoveTouch(int &n) {

}

void MTInterface::refreshFingers() {
    vector<Touch> touches = getTouches();
    
    for(vector<Touch>::iterator itT = touches.begin(); itT != touches.end(); ++itT) {
        int touchId = itT->id;
        
        if(!getFinger(touchId)) {
            MTFinger newFinger = MTFinger();
            newFinger.firstTouch = *itT;
            newFinger.currentTouch = &(*itT);
            newFinger.id = itT->id;
            
            fingers_.push_back(newFinger);
            
            std::cout << "New finger id: " << newFinger.id << std::endl;
            break;
        }
    }
    
    for(vector<MTFinger>::iterator itF = fingers_.begin(); itF != fingers_.end(); ++itF) {
        int touchId = itF->id;
        
        Touch* fingerTouch = new Touch(getTouchFromId(touchId));
        
        if(fingerTouch->id < 0) {
            std::cout << "Removing finger id:" << touchId << std::endl;
            fingers_.erase(itF);
            break;
        }
        else {
            itF->currentTouch = fingerTouch;
        }
    }
}
