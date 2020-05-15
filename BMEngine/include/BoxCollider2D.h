#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

#include "Collider.h"

namespace bme
{
	class DLLEXPORT BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D(GameObject *owner, Context &context);
		
		virtual void Update();
		virtual bool Intersects() const override;
		virtual BoxCollider2D *Clone(GameObject *owner) override;
		
		void SetBounds(float width, float height);
		void SetBounds(const sf::Vector2f &dims);

	private:
		sf::FloatRect rect;
	};
}