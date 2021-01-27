#include "DigitalClock.h"

DigitalClock::DigitalClock(unsigned int seconds)
    : Clock(seconds)
{
}

bool DigitalClock::IsBeforeMidday()
{
    return ((mSeconds / (DAY_IN_SECONDS / 2)) == 0);
}
