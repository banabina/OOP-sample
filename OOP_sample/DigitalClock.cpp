#include "DigitalClock.h"

DigitalClock::DigitalClock(unsigned int seconds)
    : Clock(seconds)
{
}

void DigitalClock::SetIsBeforeMidday(bool isAm)
{
    if (isAm == true)
    {
        if (IsBeforeMidday())
        {
            return;
        }
        else
        {
            mSeconds -= DAY_IN_SECONDS / 2;
        }
    }
    else
    {
        if (IsBeforeMidday() == false)
        {
            return;
        }
        else
        {
            mSeconds += DAY_IN_SECONDS / 2;
        }
    }
}

void DigitalClock::SetTimes(int hours, int minutes, int seconds)
{
    SetSeconds(seconds);
    SetMinutes(minutes);
    SetHours(hours);
}

void DigitalClock::SetHours(int hours)
{
    const int HOUR_IN_SECONDS = 60 * 60;
    
    mSeconds -= GetHours() * HOUR_IN_SECONDS;
    mSeconds += std::max(int(std::min(23, (int)hours)), 0) * HOUR_IN_SECONDS;
}

void DigitalClock::SetMinutes(int minutes)
{
    const int MINUTE_IN_SECONDS = 60;
    mSeconds -= GetMinutes() * MINUTE_IN_SECONDS;
    mSeconds += std::max(int(std::min(59, (int)minutes)), 0) * MINUTE_IN_SECONDS;
}

void DigitalClock::SetSeconds(int seconds)
{
    mSeconds -= GetSeconds();
    mSeconds += std::max(int(std::min(59, (int)seconds)), 0);
}

bool DigitalClock::IsBeforeMidday()
{
    return ((mSeconds / (DAY_IN_SECONDS / 2)) == 0);
}
