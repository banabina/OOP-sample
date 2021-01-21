#pragma once
#include "WaterSpray.h"
#include <cassert>

class FlowerPot {
public:
	FlowerPot(int minDailyWater);
	FlowerPot(const FlowerPot& other) = default;
	~FlowerPot() = default;
	void LiveAnotherDay(void);
	int GetMinDailyWater();
	int GetDailyWaterReceived();
	bool IsAlive();
	void AddWater(WaterSpray& spray);
private:
	bool mbAlive;
	int mMinDailyWater;
	int mDailyWaterReceived;
};