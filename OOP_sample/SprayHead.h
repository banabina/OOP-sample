#pragma once
#include "SprayBody.h"

class SprayHead {
public:
	SprayHead(int sprayAmount);
	SprayHead(const SprayHead& other) = default;
	~SprayHead() = default;
	int GetSprayAmount();
	void sprayFrom(SprayBody body);
private:
	int mSprayAmount;
};