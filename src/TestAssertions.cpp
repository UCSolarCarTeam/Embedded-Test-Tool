#include "TestAssertions.hpp"

bool assertOn(int pinNumber)
{
#ifdef DELTA
    return (DigitalIn input(pinNameArray(pinNumber - 5)) == 1);
#else
    // Not defined yet
    return false;
#endif
}

bool assertOff(int pinNumber)
{
#ifdef DELTA
    return (DigitalIn input(pinNameArray(pinNumber - 5)) == 0);
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
        DigitalIn input(pinNameArray(pinNumber - 5));
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
    } while ( (checkedTime - currentTime) < 2);

    return (lowSeen & highSeen);
}
