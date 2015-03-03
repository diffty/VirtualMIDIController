#include "ofApp.h"

//--------------------------------------------------------------
ofApp::ofApp() {
    inputManager_ = new InputManager();
    inputManager_->setInputInterface(new MTInterface());
    midiInterface_ = new MIDIInterface();

    ui_ = new UI(inputManager_);
    spaceManager_ = new SpaceManager(inputManager_);
    
    spaceManager_->addSpace(new Space(4, spaceManager_));
    
    Space* curSpace = spaceManager_->getSpace(0);
    
    MIDIChannel c1_high = {0x80, 0x02};
    MIDIChannel c1_play = {0x80, 0x05};
    MIDIChannel c2_play = {0x90, 0x01};
    MIDIChannel c2_high = {0x90, 0x02};
    
    MIDIChannel c1_low = {0x80, 0x03};
    MIDIChannel c2_low = {0x90, 0x03};
    
    curSpace->addController(Controller(CTRL_SLIDER, curSpace, midiInterface_, c1_high));
    curSpace->addController(Controller(CTRL_TAP,    curSpace, midiInterface_, c1_play));
    curSpace->addController(Controller(CTRL_TAP,    curSpace, midiInterface_, c2_play));
    curSpace->addController(Controller(CTRL_SLIDER, curSpace, midiInterface_, c2_high));
    
    ui_->setSpaceManager(spaceManager_);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_SILENT);
    
    ofSetBackgroundAuto(false); // nicing up, maybe....
    ofBackground(0,0,0);
    
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    /*CGPoint point;
    point.x = ofGetWidth() / 2;
    point.y = ofGetHeight() / 2;
    CGWarpMouseCursorPosition(point);*/
}

//--------------------------------------------------------------
void ofApp::draw(){
    ui_->draw();
}

//--------------------------------------------------------------
InputManager* ofApp::getInputManager() {
    return inputManager_;
}

SpaceManager* ofApp::getSpaceManager() {
    return spaceManager_;
}

UI* ofApp::getUI() {
    return ui_;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f')
    {
        ofToggleFullscreen();
        ofBackground(0,0,0);
    }
    else if(key == 'c') {
        ctrlMode = 0;    // Mode CROSSFADER
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ctrlMode = -1;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
