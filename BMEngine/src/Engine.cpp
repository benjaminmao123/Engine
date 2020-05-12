#include "Engine.h"

bme::Engine::Engine(unsigned int sWidth, unsigned int sHeight, 
					const std::string &appName, const sf::Color &sClearColor)
	: window(sf::VideoMode(sWidth, sHeight), appName), inputManager(window),
	  context(window, sceneManager, timeManager, inputManager, resourceManager), 
	  appName(appName), screenClearColor(sClearColor), event()
{

}

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

void bme::Engine::Update()
{
	timeManager.Update();
	PollEvents();
	sceneManager.Update();
}

void bme::Engine::LateUpdate()
{
	sceneManager.LateUpdate();
}

void bme::Engine::Render()
{
	window.clear(screenClearColor);
	sceneManager.Render();
	window.display();
}

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

void bme::Engine::AddScene(Scene *scene)
{
	sceneManager.AddScene(scene);
}

bme::Context &bme::Engine::GetContext()
{
	return context;
}
