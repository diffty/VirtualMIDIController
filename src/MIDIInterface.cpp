//
//  MIDIInterface.cpp
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#include "MIDIInterface.h"



MIDIInterface::MIDIInterface() {
    std::vector<unsigned char> message;
    int nPorts;
    
    try {
        midiOut = new RtMidiOut();
    }
    catch (RtMidiError &error) {
        // Handle the exception here
        error.printMessage();
    }
    
    nPorts = midiOut->getPortCount();
    
    std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";
    
    midiOut->openPort(0);
}

void MIDIInterface::sendCmd(MIDIChannel midiChan, int value) {
    sendMidi(midiChan.status, midiChan.channel, value);
}

void MIDIInterface::sendMidi(int status, int channel, int value) {
    std::vector<unsigned char> message;
    
    message.push_back(status);     // 0xB0
    message.push_back(channel);     // 0x01
    message.push_back(value);
    
    midiOut->sendMessage( &message );
}