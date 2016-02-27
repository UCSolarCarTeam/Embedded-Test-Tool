#include "TestAssertions.hpp"

bool assertOn(int pinNumber)
{
#ifdef DELTA
    DigitalIn input(pinNameArray[pinNumber - PIN_OFFSET]);
    return (input == OUTPUT_HI);
#else
    // Not defined yet
    return false;
#endif
}

bool assertOff(int pinNumber)
{
#ifdef DELTA
    DigitalIn input(pinNameArray[pinNumber - PIN_OFFSET]);
    return (input == OUTPUT_LO);
#else
    // Not defined yet
    return false;
#endif
}

bool assertToggling(int pinNumber)
{
    bool lowSeen = false;
    bool highSeen = false;
    time_t currentTime = time(NULL);
    time_t checkedTime;

    do
    {
    #ifdef DELTA
        DigitalIn input(pinNameArray[pinNumber - PIN_OFFSET]);
        if (input)
        {
            highSeen = true;
        }
        else if (!input)
        {
            lowSeen = true;
        }
    #else
    #endif
        checkedTime = time(NULL);
    } while ( (checkedTime - currentTime) < SAMPLE_TIMEOUT);

    return (lowSeen & highSeen);
}
