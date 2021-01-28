#pragma once
class Clock
{
public:
	Clock();
	Clock(unsigned int seconds);
	Clock(const Clock& other) = default;
	~Clock() = default;
	Clock& operator=(const Clock& rhs);
	unsigned char GetHours() const;
	unsigned char GetMinutes() const;
	unsigned char GetSeconds() const;
	void Tick();
	void Mount() const;
protected:
	unsigned int mSeconds;
	const int DAY_IN_SECONDS = 60 * 60 * 24;
};