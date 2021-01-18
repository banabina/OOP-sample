#pragma once
#include <algorithm>

class SprayBody {
public:
	SprayBody(int capacity);
	int GetCapacity();
	int GetRemainingWater();
	void FillUp();
	void AddWater(int water);
	void ReduceWater(int water);
private:
	int mCapacity;
	int mRemainingWater;
};