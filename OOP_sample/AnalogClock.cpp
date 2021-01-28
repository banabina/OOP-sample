#include "AnalogClock.h"

AnalogClock::AnalogClock()
	: Clock()
{
}

AnalogClock::AnalogClock(unsigned int seconds)
	: Clock(seconds)
{
}

unsigned int AnalogClock::GetSecondHandAngle() const
{
	return 0;
}

unsigned int AnalogClock::GetMinuteHandAngle() const
{
	return (unsigned int)(GetSeconds() * 6);
}

unsigned int AnalogClock::GetHourHandAngle() const
{
	const int ANGLE_PER_HOUR = 360 / 12;
	unsigned int hours = GetHours() % 12;
	return (unsigned int)(hours * ANGLE_PER_HOUR + GetMinutes() * ANGLE_PER_HOUR / 60);
}

unsigned char AnalogClock::GetHours12hourClock()
{
	int hours = GetHours() % 12;
	return (unsigned char)(hours == 0 ? 12 : hours);
}

void AnalogClock::AddSeconds(short seconds)
{
	int value = mSeconds + seconds;
	while (value < 0)
	{
		value += DAY_IN_SECONDS;
	}

	mSeconds = value % DAY_IN_SECONDS;
}



