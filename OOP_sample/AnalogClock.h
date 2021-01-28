#pragma once
#include "Clock.h"

class AnalogClock : public Clock
{
public:
	AnalogClock();
	AnalogClock(unsigned int seconds);
	~AnalogClock() = default;
	unsigned int GetSecondHandAngle() const;
	unsigned int GetMinuteHandAngle() const;
	unsigned int GetHourHandAngle() const;
	unsigned char GetHours12hourClock();
	void AddSeconds(short seconds);
private:
};