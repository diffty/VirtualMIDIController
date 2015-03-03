#pragma once

#include "ofMain.h"
#include "ofxMultiTouchPad.h"
#include "RtMidi.h"
#include "UI.h"
#include "MTInterface.h"
#include "InputManager.h"
#include "SpaceManager.h"
#include "Space.h"
#include "Controller.h"
#include "MIDIInterface.h"
#include "appTypes.h"


class ofApp : public ofBaseApp {
  public:
    ofApp();
    
    void sendCtrl(int value);
    void sendMidi(int status, int midiNo, int value);
    
    // OF Stuff
	void setup();
	void update();
    void draw();
    
    InputManager* getInputManager();
    SpaceManager* getSpaceManager();
    UI* getUI();
    
   	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
  private:
    ofxMultiTouchPad pad;
    int ctrlMode = 0;
    UI* ui_;
    InputManager* inputManager_;
    SpaceManager* spaceManager_;
    MIDIInterface* midiInterface_;
};
