#pragma once
#include <algorithm>

class SprayBody {
public:
	SprayBody(int capacity);
	SprayBody(const SprayBody& other) = default;
	~SprayBody() = default;
	int GetCapacity();
	int GetRemainingWater();
	void FillUp();
	void AddWater(int water);
	void ReduceWater(int water);
private:
	int mCapacity;
	int mRemainingWater;
};