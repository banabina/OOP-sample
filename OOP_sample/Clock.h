#pragma once
class Clock
{
public:
	Clock();
	~Clock() = default;
	unsigned char GetHours();
	unsigned char GetMinutes();
	unsigned char GetSeconds();
	void Tick();
	void Mount();
protected:
	unsigned int mSeconds;
	const int HALF_DAY_IN_SECONDS = 60 * 60 * 12;
};