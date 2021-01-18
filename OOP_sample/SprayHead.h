#pragma once
#include "SprayBody.h"

class SprayHead {
public:
	SprayHead(int sprayAmount);
	int GetSprayAmount();
	void sprayFrom(SprayBody body);
private:
	int mSprayAmount;
};