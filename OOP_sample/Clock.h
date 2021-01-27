#pragma once
class Clock
{
public:
	Clock();
	Clock(unsigned int seconds);
	Clock(const Clock& other) = default;
	~Clock() = default;
	Clock& operator=(const Clock& rhs);
	unsigned char GetHours();
	unsigned char GetMinutes();
	unsigned char GetSeconds();
	void Tick();
	void Mount();
protected:
	unsigned int mSeconds;
	const int DAY_IN_SECONDS = 60 * 60 * 24;
};