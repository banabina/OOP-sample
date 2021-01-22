#include "SprayBody.h"

SprayBody::SprayBody(int capacity)
	: mCapacity(capacity)
	, mRemainingWater(0)
{
}

int SprayBody::GetCapacity() const
{
	return mCapacity;
}

int SprayBody::GetRemainingWater() const
{
	return mRemainingWater;
}

void SprayBody::FillUp()
{
	mRemainingWater = mCapacity;
}

void SprayBody::AddWater(int water)
{
	mRemainingWater = std::min(mCapacity, mRemainingWater + water);
}

void SprayBody::ReduceWater(int water)
{
	mRemainingWater = std::max(0, mRemainingWater - water);
}
