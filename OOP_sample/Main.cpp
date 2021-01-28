#include "FlowerPot.h"
#include "WaterSpray.h"
#include "EBottleSize.h"
#include "ESprayHeadSpeed.h"

#include "Song.h"
#include "Playlist.h"
#include "JkTunes.h"

#include "Clock.h"
#include "AnalogClock.h"
#include "DigitalClock.h"

#include <cassert>
#include <iostream>
#include <cstdio>

void WaterSprayTest(void);
void FlowerPotTest(void);
void SprayToFlowerPotTest(void);

void SongAndPlayListTest(void);

void ClockTest(void);

using namespace std;

int main(void)
{
	// 1 FlowerPot and WaterSpray Test code
	//WaterSprayTest();
	//FlowerPotTest();
	//SprayToFlowerPotTest();

	// 2 Jk Tunes Test code
	SongAndPlayListTest();

	// 3 Clock
	ClockTest();


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
	WaterSpray spray2(spray);

	assert(spray2.GetBody()->GetCapacity() == 500);
	assert(spray2.GetHead()->GetSprayAmount() == 50);

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

void SongAndPlayListTest(void)
{
	Song* song1 = new Song("name : song1", "atom", 180000);
	song1->Play();

	Song* song2 = new Song("name : song2", "tom", 180000);
	Song* song3 = new Song("name : song3", "atom", 180000);

	vector<Song*> songs;
	songs.push_back(song1);
	songs.push_back(song2);
	songs.push_back(song3);

	PlayList* playList = new PlayList(songs, "goodMusic");
	Song* song4 = new Song("name : song4", "atom", 180000);

	assert(playList->RemoveSong("name : song1"));
	assert(!playList->RemoveSong("name : song4"));

	playList->AddSong(song4);
}

void ClockTest(void)
{

	AnalogClock* analogClock = new AnalogClock();

	analogClock->AddSeconds((short)8219);
	printf("%d:%d:%d\n", analogClock->GetHours(), analogClock->GetMinutes(), analogClock->GetSeconds());
	analogClock->Tick();
	printf("%d:%d:%d\n", analogClock->GetHours(), analogClock->GetMinutes(), analogClock->GetSeconds());

	DigitalClock* digitalClock = new DigitalClock(98219);
	digitalClock->Tick();

	digitalClock->SetHours(10);
	assert(digitalClock->GetHours() == 10);

	digitalClock->SetMinutes(30);
	assert(digitalClock->GetMinutes() == 30);

	digitalClock->SetSeconds(25);
	assert(digitalClock->GetSeconds() == 25);

	digitalClock->SetIsBeforeMidday(false);
	assert(digitalClock->IsBeforeMidday() == false);

	digitalClock->SetTimes(14, 28, 45);
	assert(digitalClock->GetHours() == 14);
	assert(digitalClock->GetMinutes() == 28);
	assert(digitalClock->GetSeconds() == 45);
	assert(digitalClock->IsBeforeMidday() == false);
}