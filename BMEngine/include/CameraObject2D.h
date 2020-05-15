#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>
#include <string>

#include "GameObject.h"

namespace bme
{
	/// <summary>
	///		A premade Camera Object for 2D rendering which can be initialized
	///		to a specific viewport.
	/// </summary>
	class DLLEXPORT CameraObject2D : public GameObject
	{
	public:
		CameraObject2D(Context &context, GameObject *parent, const sf::Vector2f &pos, const std::string &name);
		CameraObject2D(Context &context);
		CameraObject2D(Context &context, GameObject *parent);
		CameraObject2D(Context &context, GameObject *parent, const sf::Vector2f &pos);
		CameraObject2D(Context &context, const sf::Vector2f &pos);
		CameraObject2D(Context &context, const sf::Vector2f &pos, const std::string &name);
		CameraObject2D(Context &context, const std::string &name);
	};
}