#include "FlowerPot.h"
#include "WaterSpray.h"
#include "EBottleSize.h"
#include "ESprayHeadSpeed.h"

#include "Song.h"

#include <cassert>
#include <iostream>

void WaterSprayTest(void);
void FlowerPotTest(void);
void SprayToFlowerPotTest(void);

int main(void)
{
	// 1 FlowerPot and WaterSpray Test code
	//WaterSprayTest();
	//FlowerPotTest();
	//SprayToFlowerPotTest();

	// 2 Jk Tunes Test code
	Song* song = new Song("Is good", "atom", 180000);
	song->play();

}

void WaterSprayTest(void)
{
	// spray amount = 5, bottle capacity = 500
	WaterSpray* spray1 = new WaterSpray(eSprayHeadSpeed::MEDIUM, eBottleSize::MEDIUM);
	assert(spray1->GetCapacity() == 500);
	assert(spray1->GetRemainingWater() == 0);
	assert(spray1->GetSprayAmount() == 5);

	spray1->FillUp();
	assert(spray1->GetCapacity() == spray1->GetRemainingWater());

	spray1->Spray();
	assert(spray1->GetRemainingWater() == 500 - 5);

	spray1->AddWater(100);
	assert(spray1->GetRemainingWater() == spray1->GetCapacity());

	for (int i = 0; i < 150; ++i)
	{
		spray1->Spray();
	}
	assert(spray1->GetRemainingWater() == 0);

	delete spray1;
}

void FlowerPotTest(void)
{
	FlowerPot* flower1 = new FlowerPot(100);
	assert(flower1->GetMinDailyWater() == 100);
	assert(flower1->GetDailyWaterReceived() == 0);
	assert(flower1->IsAlive() == true);

	flower1->LiveAnotherDay();

	assert(flower1->IsAlive() == false);
	delete flower1;
}

void SprayToFlowerPotTest(void)
{

	FlowerPot flower(100);

	WaterSpray spray(eSprayHeadSpeed::FAST, eBottleSize::MEDIUM);

	spray.AddWater(500);

	assert(spray.GetRemainingWater() == 500);

	for (int i = 0; i < 2; ++i)
	{
		flower.AddWater(spray);
		std::cout << "water received : " << flower.GetDailyWaterReceived() << std::endl;
	}

	flower.LiveAnotherDay();
	assert(flower.IsAlive());

	flower.AddWater(spray);
	assert(flower.GetDailyWaterReceived() == 50);

	flower.LiveAnotherDay();
	assert(!flower.IsAlive());
}