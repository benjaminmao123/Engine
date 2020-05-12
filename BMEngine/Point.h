#pragma once

#include <SFML\Graphics.hpp>

#include "Renderer2D.h"

namespace bme
{
	class Point : public Renderer2D
	{
	public:
		Point(GameObject *owner, Context &context);

		virtual void Render() override;
		virtual Point *Clone(GameObject *owner) override;

		sf::CircleShape &GetPoint();

	private:
		sf::CircleShape point;
	};
}