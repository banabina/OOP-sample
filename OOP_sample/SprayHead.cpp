#include "SprayHead.h"

SprayHead::SprayHead(int sprayAmount)
	: mSprayAmount(sprayAmount)
{
}

int SprayHead::GetSprayAmount() const
{
	return mSprayAmount;
}

void SprayHead::sprayFrom(SprayBody body) const
{
	body.ReduceWater(mSprayAmount);
}
