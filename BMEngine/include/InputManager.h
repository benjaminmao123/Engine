#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

namespace bme
{
	/// <summary>
	///		Handles all of the input polling and 
	///		as well as button/axis.
	/// </summary>
	class DLLEXPORT InputManager
	{
	private:
		struct WheelData
		{
			int delta;
			int x, y;
		};

	public:
		InputManager(const sf::RenderWindow &window);

		void Update();

		bool GetKeyDown(sf::Keyboard::Key key);
		bool GetKeyDown(sf::Mouse::Button button);
		bool GetKey(sf::Keyboard::Key key);
		bool GetKey(sf::Mouse::Button button);
		bool GetKeyUp(sf::Keyboard::Key key);
		bool GetKeyUp(sf::Mouse::Button button);
		const WheelData &GetMouseWheelData() const;
		void SetMouseWheelData(const sf::Event &event);
		const sf::Vector2i GetMousePosition() const;
		const sf::Vector2f GetMousePositionWorld() const;

	private:
		void ResetMouseWheelData();

		const sf::RenderWindow &window;
		WheelData wheelData;
	};
}