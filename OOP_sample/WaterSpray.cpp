#include "WaterSpray.h"

WaterSpray::WaterSpray(SprayHead* head, SprayBody* body)
	: mHead(head)
	, mBody(body)
{
}

WaterSpray::WaterSpray(eSprayHeadSpeed speed, eBottleSize size)
	: mBody(nullptr)
	, mHead(nullptr)
{
	switch (speed)
	{
	case eSprayHeadSpeed::SLOW:
		mHead = new SprayHead(1);
		break;
	case eSprayHeadSpeed::MEDIUM:
		mHead = new SprayHead(5);
		break;
	case eSprayHeadSpeed::FAST:
		mHead = new SprayHead(50);
		break;
	}

	switch (size)
	{
	case eBottleSize::SMALL:
		mBody = new SprayBody(100);
		break;
	case eBottleSize::MEDIUM:
		mBody = new SprayBody(500);
		break;
	case eBottleSize::LARGE:
		mBody = new SprayBody(1000);
		break;
	}
}

WaterSpray::~WaterSpray()
{
	if (mHead != nullptr)
	{
		delete mHead;
	}

	if (mBody != nullptr)
	{
		delete mBody;
	}
}


void WaterSpray::Spray()
{
	mBody->ReduceWater(mHead->GetSprayAmount());
}

int WaterSpray::GetCapacity()
{
	return mBody->GetCapacity();
}

int WaterSpray::GetRemainingWater()
{
	return mBody->GetRemainingWater();
}

int WaterSpray::GetSprayAmount()
{
	return mHead->GetSprayAmount();
}

void WaterSpray::FillUp()
{
	mBody->FillUp();
}

void WaterSpray::AddWater(int water)
{
	mBody->AddWater(water);
}

SprayHead* WaterSpray::GetHead()
{
	return mHead;
}

SprayBody* WaterSpray::GetBody()
{
	return mBody;
}

void WaterSpray::SetHead(SprayHead* head)
{
	mHead = head;
}

void WaterSpray::SetBody(SprayBody* body)
{
	mBody = body;
}
