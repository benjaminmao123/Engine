#pragma once

#include <SFML\Graphics.hpp>
#include <string>

#include "GameObject.h"

namespace bme
{
	/// <summary>
	///		Premade 2D Point Object.
	/// </summary>
	class DLLEXPORT PointObject2D : public GameObject
	{
	public:
		PointObject2D(Context &context, GameObject *parent, const sf::Vector2f &pos, const std::string &name);
		PointObject2D(Context &context);
		PointObject2D(Context &context, GameObject *parent);
		PointObject2D(Context &context, GameObject *parent, const sf::Vector2f &pos);
		PointObject2D(Context &context, const sf::Vector2f &pos);
		PointObject2D(Context &context, const sf::Vector2f &pos, const std::string &name);
		PointObject2D(Context &context, const std::string &name);
	};
}