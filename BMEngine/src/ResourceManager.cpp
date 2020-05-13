#include "bmepch.h"
#include "ResourceManager.h"

bme::ResourceManager::~ResourceManager()
{
	for (auto &i : resources)
		delete i.second;
}

void bme::ResourceManager::Remove(int id)
{
	for (auto &i : resources)
	{
		if (i.second->ID() == id)
		{
			delete i.second;
			resources.erase(i.first);
		}
	}
}