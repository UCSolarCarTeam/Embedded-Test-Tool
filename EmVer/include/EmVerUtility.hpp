#include "mbed.h"

bool assertPin(PinName pinName, bool expectedState, int timeoutMs);
bool assertPinToggle(PinName pinName, unsigned int expectedOccurrences, int timeoutMs);
bool assertCan(CAN& can, unsigned int expectedId, const char* expectedData, const int expectedLen, int timeoutMs);
