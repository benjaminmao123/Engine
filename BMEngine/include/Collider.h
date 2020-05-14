#pragma once

#include "Component.h"

namespace bme
{
	class Collider : public Component
	{
	public:
		Collider(GameObject *owner, Context &context);


	};
}