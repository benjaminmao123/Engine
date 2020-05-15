#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

#include "Renderer2D.h"

namespace bme
{
	/// <summary>
	///		Point component that renders a point 
	///		primitive onto the screen.
	/// </summary>
	class DLLEXPORT Point2D : public Renderer2D
	{
	public:
		Point2D(GameObject *owner, Context &context, int zOrder = 0);

		virtual Point2D *Clone(GameObject *owner) override;

		sf::CircleShape &GetPoint();

	protected:
		virtual void Render() override;

	private:
		sf::CircleShape point;
	};
}