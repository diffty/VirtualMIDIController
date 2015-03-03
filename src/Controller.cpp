//
//  Controller.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "Controller.h"

#include "Space.h"


Controller::Controller(int type, Space* parentSpace, MIDIInterface* midiInterface, MIDIChannel midiChan) {
    color_ = ofColor(0, 0, 0);
    type_ = type;
    midiInterface_ = midiInterface;
    midiChannel_ = midiChan;
}

void Controller::setColor(ofColor color) {
    color_ = color;
}

ofColor Controller::getColor() {
    return color_;
}

void Controller::receiveInput(MTFinger* f) {
    switch(type_) {
        case CTRL_SLIDER:
            _sliderBehaviourOnInput(*f->currentTouch);
            break;
            
        case CTRL_KNOB:
            _knobBehaviourOnInput(*f->currentTouch);
            break;
            
        case CTRL_TAP:
            if(!f->used) {
                _tapBehaviourOnInput(*f->currentTouch);
            }
            break;
            
        case CTRL_XY:
            _xyBehaviourOnInput(*f->currentTouch);
            break;
    }
    f->used = true;
}

Space* Controller::getParentSpace() {
    return parentSpace_;
}

void Controller::_sliderBehaviourOnInput(Touch t) {
    setColor(ofColor(0, t.y * 255., 255));
    midiInterface_->sendCmd(midiChannel_, t.y * 127);
}

void Controller::_knobBehaviourOnInput(Touch t) {
    setColor(ofColor(0, t.y * 255., 255));
    midiInterface_->sendCmd(midiChannel_, t.angle * 127);
}

void Controller::_tapBehaviourOnInput(Touch t) {
    setColor(ofColor(0, t.y * 255., 255));
    midiInterface_->sendCmd(midiChannel_, 127);
    std::cout << "BOB SAGET" << std::endl;
}

void Controller::_xyBehaviourOnInput(Touch t) {
    setColor(ofColor(0, t.y * 255., 255));
    midiInterface_->sendCmd(midiChannel_, t.y * 127);
}