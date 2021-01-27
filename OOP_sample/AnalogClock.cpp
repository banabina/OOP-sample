#include "AnalogClock.h"

AnalogClock::AnalogClock()
	: Clock()
{
}

unsigned int AnalogClock::GetSecondHandAngle()
{
	return 0;
}

unsigned int AnalogClock::GetMinuteHandAngle()
{
	return (unsigned int)(GetSeconds() * 6);
}

unsigned int AnalogClock::GetHourHandAngle()
{
	const int ANGLE_PER_HOUR = 360 / 12;
	unsigned int hours = GetHours() % 12;
	return (unsigned int)(hours * ANGLE_PER_HOUR + GetMinutes() * ANGLE_PER_HOUR / 60);
}

void AnalogClock::AddSeconds(short seconds)
{
	int value = mSeconds + seconds;
	while (value < 0)
	{
		value += HALF_DAY_IN_SECONDS;
	}

	mSeconds = value % HALF_DAY_IN_SECONDS;
}



