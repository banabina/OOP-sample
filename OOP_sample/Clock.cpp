#include "Clock.h"

Clock::Clock()
	: mSeconds(0)
{
}

Clock::Clock(unsigned int seconds)
	: mSeconds(seconds)
{
}

Clock& Clock::operator=(const Clock& rhs)
{
	mSeconds = rhs.mSeconds;
	return *this;
}

unsigned char Clock::GetHours()
{
	int hours = mSeconds / 60 / 60;

	return hours == 0 ? 12 : (unsigned char)hours;
}

unsigned char Clock::GetMinutes()
{

	return (unsigned char)(mSeconds / 60 % 60);
}

unsigned char Clock::GetSeconds()
{
	return (unsigned char)(mSeconds % 60);
}

void Clock::Tick()
{
	mSeconds = (mSeconds + 1) % DAY_IN_SECONDS;
}

void Clock::Mount()
{
}
