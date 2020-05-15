#pragma once

#include <SFML\Graphics.hpp>

#include "Component.h"

namespace bme
{
	/// <summary>
	///		Contains information about collisions.
	///	</summary>
	struct Collision
	{
		bool colliding = false;
	};

	/// <summary>
	///		The base class for all Collider Components.
	///	</summary>
	class Collider : public Component
	{
	public:
		Collider(GameObject *owner, Context &context);


	};
}