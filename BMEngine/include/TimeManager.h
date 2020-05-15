#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

namespace bme
{
	///	<summary>
	///		Handles all of the calculations related to time.
	///	</summary>
	class DLLEXPORT TimeManager
	{
	public:
		TimeManager();

		void Update();

		float GetDeltaTime() const;

	private:
		float deltaTime;
		sf::Time time;
		sf::Clock clock;
	};
}