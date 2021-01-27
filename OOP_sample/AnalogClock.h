#pragma once
#include "Clock.h"

class AnalogClock : public Clock
{
public:
	AnalogClock();
	AnalogClock(unsigned int seconds);
	~AnalogClock() = default;
	unsigned int GetSecondHandAngle();
	unsigned int GetMinuteHandAngle();
	unsigned int GetHourHandAngle();
	unsigned char GetHours12hourClock();
	void AddSeconds(short seconds);
private:
};