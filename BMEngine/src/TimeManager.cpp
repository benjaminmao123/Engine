#include "bmepch.h"
#include "TimeManager.h"

///	<summary>
///		Default constructor.
///		Initializes deltaTime to 0.
///	</summary>
///	<return>
///		void
///	</return>
bme::TimeManager::TimeManager()
	: deltaTime(0)
{

}

///	<summary>
///		Computes to the deltaTime every frame.
///	</summary>
///	<return>
///		void
///	</return>
void bme::TimeManager::Update()
{
	deltaTime = clock.restart().asSeconds();
}

///	<summary>
///		Retrieves the delta time.
///	</summary>
///	<return>
///		Float representing the delta time.
///	</return>
float bme::TimeManager::GetDeltaTime() const
{
	return deltaTime;
}
