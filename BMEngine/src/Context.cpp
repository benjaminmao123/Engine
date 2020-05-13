/// <summary>
///		Context class is used to provide necessary arguments that are used
///		by Scenes, GameObjects, and Components.
/// </summary>

#include "bmepch.h"
#include "Context.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

/// <summary>
///		Parameterized constructor. 
///		Initializes window, sceneManager, time, and inputManager.
/// </summary>
/// <param name="window">
///		The sf::RenderWindow that is being drawn to.
///	</param>
/// <param name="sceneManager">
///		The SceneManager object.
///	</param>
/// <param name="timeManager">
///		The TimeManager object.
///	</param>
/// <param name="inputManager">
///		The InputManager object.
///	</param>
/// <param name="resourceManager">
///		The ResourceManager object.
///	</param>
///	<returns>
///		void
///	</returns>
bme::Context::Context(sf::RenderWindow &window, SceneManager &sceneManager, 
					  const TimeManager &timeManager, InputManager &inputManager,
					  ResourceManager &resourceManager)
	: window(window), sceneManager(sceneManager), 
	  timeManager(timeManager), inputManager(inputManager),
	  resourceManager(resourceManager)
{

}

/// <summary>
///		Getter function for the sf::RenderWindow.
/// </summary>
///	<returns>
///		The sf::RenderWindow object.
///	</returns>
sf::RenderWindow &bme::Context::GetWindow()
{
	return window;
}

/// <summary>
///		Getter function for the SceneManager.
/// </summary>
///	<returns>
///		The SceneManager object.
///	</returns>
bme::SceneManager &bme::Context::GetSceneManager()
{
	return sceneManager;
}

/// <summary>
///		Getter function for the TimeManager.
/// </summary>
///	<returns>
///		The TimeManager object.
///	</returns>
const bme::TimeManager &bme::Context::GetTimeManager() const
{
	return timeManager;
}

/// <summary>
///		Getter function for the InputManager.
/// </summary>
///	<returns>
///		The InputManager object.
///	</returns>
bme::InputManager &bme::Context::GetInputManager()
{
	return inputManager;
}

/// <summary>
///		Getter function for the ResourceManager.
/// </summary>
///	<returns>
///		The ResourceManager object.
///	</returns>
bme::ResourceManager &bme::Context::GetResourceManager()
{
	return resourceManager;
}
