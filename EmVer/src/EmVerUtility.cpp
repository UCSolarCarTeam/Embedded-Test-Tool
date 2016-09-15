#include <string.h>

#include "mbed.h"

#include "EmVerUtility.hpp"

bool assertPin(PinName pinName, bool expect, int timeout) { // timeout in ms
    Timer t;
    DigitalIn pin(pinName);
    t.start();
    while(t.read_ms() < timeout) {
        if(pin == expect) {
            return true;
        }
    }
    return false;
}

bool assertPinToggle(PinName pinName, unsigned int expectOccurences, int timeout) { // timeout in ms
    Timer t;
    DigitalIn pin(pinName);
    t.start();
    bool prevStatus = pin;
    unsigned int occurences = 0;
    while(t.read_ms() < timeout) {
        if(pin != prevStatus) {
            prevStatus = pin;
            occurences++;
        }
    }
    return occurences == expectOccurences;
}

bool assertCan(PinName p1, PinName p2, unsigned int expectId, const int* expectData, const int expectLen, int timeout) { // timeout in ms
    Timer t;
    CANMessage msg;
    CAN can(p1, p2);
    t.start();
    while(t.read_ms() < timeout) {
        if(can.read(msg) && msg.id == expectId) {
            if(expectLen != msg.len) {
                return false;
            }
            for(int i = 0; i < msg.len; i++) {
                if(msg.data[i] != expectData[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
