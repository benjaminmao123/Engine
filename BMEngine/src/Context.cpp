#include "Context.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

bme::Context::Context(sf::RenderWindow &window, SceneManager &sceneManager, 
					  const TimeManager &time, InputManager &inputManager,
					  ResourceManager &resourceManager)
	: window(window), sceneManager(sceneManager), 
	  timeManager(time), inputManager(inputManager),
	  resourceManager(resourceManager)
{

}

sf::RenderWindow &bme::Context::GetWindow()
{
	return window;
}

bme::SceneManager &bme::Context::GetSceneManager()
{
	return sceneManager;
}

const bme::TimeManager &bme::Context::GetTimeManager() const
{
	return timeManager;
}

bme::InputManager &bme::Context::GetInputManager()
{
	return inputManager;
}

bme::ResourceManager &bme::Context::GetResourceManager()
{
	return resourceManager;
}
