//
//  InputManager.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 23/02/2015.
//
//

#include "InputManager.h"
#include "ofApp.h"
#include "Controller.h"


InputManager::InputManager() {
    
}

void InputManager::setInputInterface(MTInterface* interface) {
    interface_ = interface;
}

MTInterface* InputManager::getInputInterface() {
    return interface_;
}
