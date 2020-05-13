#include "bmepch.h"
#include "TimeManager.h"

bme::TimeManager::TimeManager()
	: deltaTime(0)
{

}

void bme::TimeManager::Update()
{
	deltaTime = clock.restart().asSeconds();
}

float bme::TimeManager::GetDeltaTime() const
{
	return deltaTime;
}
