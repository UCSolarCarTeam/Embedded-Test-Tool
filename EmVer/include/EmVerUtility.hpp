#include "mbed.h"

bool assertPin(PinName pinName, bool expected, int timeout);
bool assertPinToggle(PinName pinName, int expectedOccurences, int timeout);
bool assertCan(PinName p1, PinName p2, int expectedId, const char* expectedData, int expectedLen, int timeout);
