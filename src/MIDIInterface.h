//
//  MIDIInterface.h
//  TouchPadTest
//
//  Created by DiFFtY on 21/02/2015.
//
//

#pragma once

#ifndef __TouchPadTest__MIDIInterface__
#define __TouchPadTest__MIDIInterface__

#include <stdio.h>
#include "RtMidi.h"

#endif /* defined(__TouchPadTest__MIDIInterface__) */


struct MIDIChannel {
    int status;
    int channel;
};


class MIDIInterface {
public:
    MIDIInterface();
    void sendCmd(MIDIChannel midiChan, int value);
    void sendMidi(int status, int channel, int value);
    
private:
    RtMidiOut *midiOut;
};