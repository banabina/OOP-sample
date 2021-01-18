#include "SprayHead.h"

SprayHead::SprayHead(int sprayAmount)
	: mSprayAmount(sprayAmount)
{
}

int SprayHead::GetSprayAmount()
{
	return mSprayAmount;
}

void SprayHead::sprayFrom(SprayBody body)
{
	body.ReduceWater(mSprayAmount);
}
