#include "GameObject.h"
#include <iostream>

GameObject::GameObject(string name)
	: mName(name)
{
}

void GameObject::AddComponent(Component* component)
{
	mComponents.emplace_back(component);
}

void GameObject::Update(void)
{
	std::cout << "Update GaneObject " << mName << std::endl;
	for (auto& component : mComponents)
	{
		component.Update();
	}
	std::cout << "Updating " << mName << " complete" << std::endl;
}
