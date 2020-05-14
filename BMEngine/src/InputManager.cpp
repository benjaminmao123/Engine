#include "bmepch.h"
#include "InputManager.h"

/// <summary>
///		Default constructor.
///		Initializes window and wheelData.
/// </summary>
///	<param name="window">
///		The sf::RenderWindow object to initialize with.
///	</param>
///	<return>
///		void
///	</return>
bme::InputManager::InputManager(const sf::RenderWindow &window)
	: window(window), wheelData{ 0, 0, 0 }
{

}

/// <summary>
///		Resets the WheelData every frame.
/// </summary>
///	<return>
///		void
///	</return>
void bme::InputManager::Update()
{
	ResetMouseWheelData();
}

/// <summary>
///		Checks to see if a key is pressed on a specific frame.
/// </summary>
///	<param name="key">
///		The key to check for.
///	</param>
///	<return>
///		True for the frame that the key is pressed.
///	</return>
bool bme::InputManager::GetKeyDown(sf::Keyboard::Key key)
{
	static bool keyPressed = false;
	static sf::Keyboard::Key lastKey = key;

	if (!keyPressed)
	{
		if (sf::Keyboard::isKeyPressed(key))
		{
			keyPressed = true;
			lastKey = key;

			return true;
		}
	}
	else
	{
		if (!sf::Keyboard::isKeyPressed(key) && key == lastKey)
			keyPressed = false;
	}

	return false;
}

/// <summary>
///		Checks to see if a mouse button is pressed on a specific frame.
/// </summary>
///	<param name="button">
///		The button to check for.
///	</param>
///	<return>
///		True for the frame that the button is pressed.
///	</return>
bool bme::InputManager::GetKeyDown(sf::Mouse::Button button)
{
	static bool keyPressed = false;
	static sf::Mouse::Button lastButton = button;

	if (!keyPressed)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			keyPressed = true;
			lastButton = button;

			return true;
		}
	}
	else
	{
		if (!sf::Mouse::isButtonPressed(button) && lastButton == button)
			keyPressed = false;
	}

	return false;
}

/// <summary>
///		Checks to see if a key is pressed.
/// </summary>
///	<param name="key">
///		The key to check for.
///	</param>
///	<return>
///		True if the key is being pressed.
///	</return>
bool bme::InputManager::GetKey(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

/// <summary>
///		Checks to see if a mouse button is pressed.
/// </summary>
///	<param name="button">
///		The mouse button to check for.
///	</param>
///	<return>
///		True if the button is being pressed.
///	</return>
bool bme::InputManager::GetKey(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

/// <summary>
///		Checks to see if a key is released on a specific frame.
/// </summary>
///	<param name="key">
///		The key to check for.
///	</param>
///	<return>
///		True for the frame that the key is released.
///	</return>
bool bme::InputManager::GetKeyUp(sf::Keyboard::Key key)
{
	static bool keyPressed = false;

	if (!keyPressed)
	{
		if (sf::Keyboard::isKeyPressed(key))
			keyPressed = true;
	}
	else
	{
		if (!sf::Keyboard::isKeyPressed(key))
		{
			keyPressed = false;

			return true;
		}
	}

	return false;
}

/// <summary>
///		Checks to see if a mouse button is released on a specific frame.
/// </summary>
///	<param name="button">
///		The button to check for.
///	</param>
///	<return>
///		True for the frame that the button is released.
///	</return>
bool bme::InputManager::GetKeyUp(sf::Mouse::Button button)
{
	static bool keyPressed = false;

	if (!keyPressed)
	{
		if (sf::Mouse::isButtonPressed(button))
			keyPressed = true;
	}
	else
	{
		if (!sf::Mouse::isButtonPressed(button))
		{
			keyPressed = false;

			return true;
		}
	}

	return false;
}

/// <summary>
///		Getter function for the WheelData.
/// </summary>
///	<return>
///		The WheelData object.
///	</return>
const bme::InputManager::WheelData &bme::InputManager::GetMouseWheelData() const
{
	return wheelData;
}

/// <summary>
///		Setter function for the WheelData.
/// </summary>
///	<param name="event">
///		The event data to set the WheelData.
///	</param>
///	<return>
///		void
///	</return>
void bme::InputManager::SetMouseWheelData(const sf::Event &event)
{
	wheelData.delta = event.mouseWheel.delta;
	wheelData.x = event.mouseWheel.x;
	wheelData.y = event.mouseWheel.y;
}

/// <summary>
///		Retrieves the mouse position on the window.
/// </summary>
///	<return>
///		An sf::Vector2i object containing the mouse coordinates.
///	</return>
const sf::Vector2i bme::InputManager::GetMousePosition() const
{
	return sf::Mouse::getPosition(window);
}

/// <summary>
///		Retrieves the absolute mouse position on the window.
/// </summary>
///	<return>
///		An sf::Vector2f object containing the mouse coordinates.
///	</return>
const sf::Vector2f bme::InputManager::GetMousePositionWorld() const
{
	return window.mapPixelToCoords(GetMousePosition());
}

/// <summary>
///		Clears the WheelData object.
/// </summary>
///	<return>
///		void
///	</return>
void bme::InputManager::ResetMouseWheelData()
{
	wheelData.delta = 0;
	wheelData.x = 0;
	wheelData.y = 0;
}

