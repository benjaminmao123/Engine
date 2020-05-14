#pragma once

#include <SFML\Graphics.hpp>
#include <string>

#include "GameObject.h"

namespace bme
{
	/// <summary>
	///		Premade 2D Point Object.
	/// </summary>
	class DLLEXPORT Point2DObject : public GameObject
	{
	public:
		Point2DObject(Context &context, GameObject *parent, const sf::Vector2f &pos, const std::string &name);
		Point2DObject(Context &context);
		Point2DObject(Context &context, GameObject *parent);
		Point2DObject(Context &context, GameObject *parent, const sf::Vector2f &pos);
		Point2DObject(Context &context, const sf::Vector2f &pos);
		Point2DObject(Context &context, const sf::Vector2f &pos, const std::string &name);
		Point2DObject(Context &context, const std::string &name);
	};
}