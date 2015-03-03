//
//  Controller.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__Controller__
#define __TouchPadTest__Controller__

#include <iostream>
#include <string>
#include "ofMain.h"
#include "appTypes.h"
#include "MIDIInterface.h"

#endif /* defined(__TouchPadTest__Controller__) */


enum CONTROLLER_TYPE {
    CTRL_SLIDER,
    CTRL_KNOB,
    CTRL_TAP,
    CTRL_XY
};

enum POSITION_MODE {
    CTRL_ABSOLUTE,
    CTRL_RELATIVE
};


class Space;

class Controller {
  public:
    Controller(int type, Space* parentSpace, MIDIInterface* midiInterface, MIDIChannel midiChan);
    
    ofColor getColor();
    void setColor(ofColor color);
    void receiveInput(MTFinger* f);
    Space* getParentSpace();
    
  private:
    string name_;
    int type_;
    int commandId_;
    Space* parentSpace_;
    ofColor color_;
    MIDIInterface* midiInterface_;
    MIDIChannel midiChannel_;
    
    void _sliderBehaviourOnInput(Touch t);
    void _knobBehaviourOnInput(Touch t);
    void _tapBehaviourOnInput(Touch t);
    void _xyBehaviourOnInput(Touch t);

};
