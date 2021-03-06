#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

#include "Renderer.h"

namespace bme
{
	/// <summary>
	///		Base Renderer2D class which supports rendering
	///		for all 2D objects.
	/// </summary>
	class DLLEXPORT Renderer2D : public Renderer
	{
	public:
		Renderer2D(GameObject *owner, Context &context, int zOrder = 0);

		virtual void OnRender() override final;
		virtual Renderer2D *Clone(GameObject *owner) = 0;

		int GetZOrder() const;
		void SetZOrder(int value);
		void SetView(const sf::View *view);
		const sf::View *const GetView() const;

	protected:
		virtual void Render() override;

	private:
		int zOrder;
		const sf::View *view;
	};
}