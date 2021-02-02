#pragma once
#include <string>
#include <vector>

#include "Component.h"

using namespace std;

class GameObject
{
public:
	GameObject(string name);
	GameObject(const GameObject& other);
	GameObject& operator=(const GameObject& rhs);
	~GameObject();
	void AddComponent(Component* component);
	void Update(void);
private:
	string mName;
	vector<Component> mComponents;
};