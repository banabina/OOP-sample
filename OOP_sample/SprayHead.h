#pragma once
#include "SprayBody.h"

class SprayHead {
public:
	SprayHead(int sprayAmount);
	SprayHead(const SprayHead& other) = default;
	~SprayHead() = default;
	int GetSprayAmount() const;
	void sprayFrom(SprayBody body) const;
private:
	int mSprayAmount;
};