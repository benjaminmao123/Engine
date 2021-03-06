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
	///		Premade UI button object.
	/// </summary>
	class DLLEXPORT ButtonObject : public GameObject
	{
	public:
		ButtonObject(Context &context, GameObject *parent, const sf::Vector2f &pos, const std::string &name);
		ButtonObject(Context &context);
		ButtonObject(Context &context, GameObject *parent);
		ButtonObject(Context &context, GameObject *parent, const sf::Vector2f &pos);
		ButtonObject(Context &context, const sf::Vector2f &pos);
		ButtonObject(Context &context, const sf::Vector2f &pos, const std::string &name);
		ButtonObject(Context &context, const std::string &name);
	};
}