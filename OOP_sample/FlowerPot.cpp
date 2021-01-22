#include "FlowerPot.h"

FlowerPot::FlowerPot(int minDailyWater)
    : mMinDailyWater(minDailyWater)
    , mbAlive(true)
    , mDailyWaterReceived(0)
{
}

void FlowerPot::LiveAnotherDay(void)
{
    if (mMinDailyWater > mDailyWaterReceived)
    {
        mbAlive = false;
    }
    mDailyWaterReceived = 0;
}

int FlowerPot::GetMinDailyWater() const
{
    return mMinDailyWater;
}

int FlowerPot::GetDailyWaterReceived() const
{
    return mDailyWaterReceived;
}

bool FlowerPot::IsAlive() const
{
    return mbAlive;
}

void FlowerPot::AddWater(WaterSpray& spray)
{
    int water = spray.GetRemainingWater();
    spray.Spray();
    water -= spray.GetRemainingWater();
    assert(water >= 0);
    mDailyWaterReceived += water;
}
