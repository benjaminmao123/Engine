#pragma once

#include <SFML\Graphics.hpp>

#include "Component.h"

namespace bme
{
	struct Collision
	{
		bool colliding = false;
	};

	class Collider : public Component
	{
	public:
		Collider(GameObject *owner, Context &context);


	};
}