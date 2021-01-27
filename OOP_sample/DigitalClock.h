#pragma once
#include "Clock.h"

class DigitalClock : public Clock
{
public:
	DigitalClock() = default;
	~DigitalClock() = default;
	DigitalClock(unsigned int seconds);
	bool IsBeforeMidday();
private:
};