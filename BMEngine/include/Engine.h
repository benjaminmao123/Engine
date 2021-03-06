#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <string>
#include <SFML\Graphics.hpp>

#include "Context.h"
#include "Scene.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

namespace bme
{
	/// <summary>
	///		The core class for the engine. 
	///		Handles initializing the Context, window information, 
	///		event polling, and calling Start(), Update(), and Render() for the 
	///		scenes.
	/// </summary>
	class DLLEXPORT Engine
	{
	public:
		Engine(unsigned int sWidth, unsigned int sHeight,
			   const std::string &appName, const sf::Color &sClearColor);

		void Run();
		void Update();
		void LateUpdate();
		void Render();

		void PollEvents();
		void AddScene(Scene *scene);
		Context &GetContext();

	private:
		std::string appName;
		Context context;
		sf::RenderWindow window;
		SceneManager sceneManager;
		TimeManager timeManager;
		InputManager inputManager;
		ResourceManager resourceManager;
		sf::Event event;
		sf::Color screenClearColor;
	};
}