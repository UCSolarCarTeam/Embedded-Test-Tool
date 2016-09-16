#include <string.h>

#include "mbed.h"

#include "EmVerUtility.hpp"

bool assertPin(PinName pinName, bool expectedState, int timeoutMs)
{
    Timer t;
    DigitalIn pin(pinName);
    t.start();
    while(t.read_ms() < timeoutMs)
    {
        if(pin == expectedState)
        {
            return true;
        }
    }
    return false;
}

bool assertPinToggle(PinName pinName, unsigned int expectedOccurrences, int timeoutMs)
{
    Timer t;
    DigitalIn pin(pinName);
    t.start();
    bool prevStatus = pin;
    unsigned int occurrences = 0;
    while(t.read_ms() < timeoutMs)
    {
        if(pin != prevStatus)
        {
            prevStatus = pin;
            occurrences++;
        }
    }
    return occurrences == expectedOccurrences;
}

bool assertCan(CAN& can, unsigned int expectedId, const int* expectedData, const int expectedLen, int timeoutMs)
{
    Timer t;
    CANMessage msg;
    t.start();
    while(t.read_ms() < timeoutMs)
    {
        if(can.read(msg) && msg.id == expectedId)
        {
            if(expectedLen != msg.len)
            {
                return false;
            }
            return std::memcmp(msg.data, expectedData, msg.len);
        }
    }
    return false;
}
