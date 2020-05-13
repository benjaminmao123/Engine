#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include "Component.h"

namespace bme
{
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