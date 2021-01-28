#pragma once
#include "Clock.h"
#include <algorithm>

class DigitalClock : public Clock
{
public:
	DigitalClock() = default;
	~DigitalClock() = default;
	DigitalClock(unsigned int seconds);
	void SetIsBeforeMidday(bool isAm);
	void SetTimes(int hours, int minutes, int seconds);
	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);
	bool IsBeforeMidday();
private:
};