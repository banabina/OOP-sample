#pragma once
#include <algorithm>
#include "SprayBody.h"
#include "SprayHead.h"
#include "EBottleSize.h"
#include "ESprayHeadSpeed.h"

class WaterSpray {
public:
	WaterSpray(SprayHead* head, SprayBody* body);
	WaterSpray(eSprayHeadSpeed speed, eBottleSize size);
	WaterSpray(const WaterSpray& other);
	WaterSpray& operator=(const WaterSpray& rhs);
	~WaterSpray();
	SprayHead* GetHead();
	SprayBody* GetBody();
	void SetHead(SprayHead* head);
	void SetBody(SprayBody* body);
	void Spray();
	int GetCapacity() const;
	int GetRemainingWater() const;
	int GetSprayAmount() const;
	void FillUp();
	void AddWater(int water);
	
private:
	SprayHead* mHead;
	SprayBody* mBody;
};