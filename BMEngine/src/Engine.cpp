/// <summary>
///		The core class for the engine. 
///		Handles initializing the Context, window information, 
///		event polling, Start, Update, and Render for the scenes.
/// </summary>

#include "bmepch.h"
#include "Engine.h"

/// <summary>
///		Parameterized constructor. 
///		Initializes window to a given width, height, 
///		the color to clear the screen with, and the name
///		of the application. 
///		Initializes the Context object to be passed to
///		other classes.
/// </summary>
/// <param name="sWidth">
///		The width to initialize the window.
///	</param>
/// <param name="sHeight">
///		The height to initialize the window.
///	</param>
/// <param name="appName">
///		The name to set the application to.
///	</param>
/// <param name="sClearColor">
///		The color to clear the screen with.
///	</param>
///	<returns>
///		void
///	</returns>
bme::Engine::Engine(unsigned int sWidth, unsigned int sHeight, 
					const std::string &appName, const sf::Color &sClearColor)
	: window(sf::VideoMode(sWidth, sHeight), appName), inputManager(window),
	  context(window, sceneManager, timeManager, inputManager, resourceManager), 
	  appName(appName), screenClearColor(sClearColor), event()
{

}

/// <summary>
///		Runs the main game loop and calls the 
///		Start() method of the sceneManager.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Engine::Start()
{
	sceneManager.Start();

	while (window.isOpen())
	{
		Update();
		LateUpdate();
		Render();
	}
}

/// <summary>
///		Calls the Update() methods of the
///		manager classes.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Engine::Update()
{
	timeManager.Update();
	PollEvents();
	sceneManager.Update();
}

/// <summary>
///		Calls the LateUpdate() methods of the
///		manager classes.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Engine::LateUpdate()
{
	sceneManager.LateUpdate();
}

/// <summary>
///		Calls the Render() methods of the
///		manager classes.
///		Clears the screen to a certain color
///		and displays the window.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Engine::Render()
{
	window.clear(screenClearColor);
	sceneManager.Render();
	window.display();
}

/// <summary>
///		Polls for an event.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Engine::PollEvents()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseWheelMoved:
			inputManager.SetMouseWheelData(event);
		default:
			break;
		}
	}
}

/// <summary>
///		Adds a scene to the SceneManager.
/// </summary>
///	<param name="scene">
///		The scene pointer to add to the SceneManager.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Engine::AddScene(Scene *scene)
{
	sceneManager.AddScene(scene);
}

/// <summary>
///		Getter function for the Context object.
/// </summary>
///	<returns>
///		The Context object.
///	</returns>
bme::Context &bme::Engine::GetContext()
{
	return context;
}
