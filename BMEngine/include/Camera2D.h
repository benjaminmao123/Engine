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
	///		Camera component for the 2D world.
	///		Renders the scene to a specific viewport that can be
	///		set by the user.
	/// </summary>
	class DLLEXPORT Camera2D : public Component
	{
	public:
		Camera2D(GameObject *owner, Context &context);

		virtual void Update() override;
		Camera2D *Clone(GameObject *owner) override;

	private:
		void ComputeViewBounds();

		sf::View view;
		sf::FloatRect viewBounds;
	};
}