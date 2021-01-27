#pragma once
#include "Clock.h"

class AnalogClock : public Clock
{
public:
	AnalogClock();
	~AnalogClock() = default;
	unsigned int GetSecondHandAngle();
	unsigned int GetMinuteHandAngle();
	unsigned int GetHourHandAngle();
	void AddSeconds(short seconds);
private:
};