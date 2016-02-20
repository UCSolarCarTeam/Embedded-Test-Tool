#ifndef TEST_ASSERTIONS_HPP
#define TEST_ASSERTIONS_HPP

#include "mbed.h"
#include "Defines.hpp"

static const int OUTPUT_LO = 0;
static const int OUTPUT_HI = 1;
static const int SAMPLE_TIMEOUT = 2;

extern const PinName pinNameArray[NUMBER_OF_PINS];

// Used for pin-number to array-index conversion
extern const int PIN_OFFSET;

bool assertOn(int pinNumber);
bool assertOff(int pinNumber);
bool assertToggling(int pinNumber);

#ifdef DELTA
#include "DeltaPinNames.hpp"
#endif

#endif // TEST_ASSERTIONS_HPP
