#ifndef TEST_ASSERTIONS_HPP
#define TEST_ASSERTIONS_HPP

#include "mbed.h"
#include "Defines.hpp"

bool assertOn(int pinNumber);
bool assertOff(int pinNumber);
bool assertToggling(int pinNumber);

extern const PinName pinNameArray[NUMBER_OF_PINS];

#ifdef DELTA
#include "DeltaPinNames.hpp"
#endif

#endif // TEST_ASSERTIONS_HPP
