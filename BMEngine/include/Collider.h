#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

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
	class DLLEXPORT Collider : public Component
	{
	public:
		Collider(GameObject *owner, Context &context);

		virtual bool Intersects() const = 0;
	};
}