#ifndef TEST_ASSERTIONS_HPP
#define TEST_ASSERTIONS_HPP

#include "mbed.h"
#ifdef DELTA
#include "DeltaPinNames.hpp"
#endif

static const int OUTPUT_LO = 0;
static const int OUTPUT_HI = 1;
static const int SAMPLE_TIMEOUT = 2;

bool assertOn(int pinNumber);
bool assertOff(int pinNumber);
bool assertToggling(int pinNumber);

#endif // TEST_ASSERTIONS_HPP
