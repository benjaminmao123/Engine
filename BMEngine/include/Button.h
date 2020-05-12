/*
	Author: Benjamin Mao
	Project: BMEngine
	Purpose: Serves as the Button Component for users to
		use when creating UI.
	Notes: None.
 */

#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>

#include "Selectable.h"
#include "Renderer2D.h"

namespace bme
{
	class TextRenderer;

	class DLLEXPORT Button : public Renderer2D, public Selectable
	{
	public:
		Button(GameObject *owner, Context &context);
		
		virtual void Start() override;
		virtual void Update() override;
		virtual void Render() override;
		virtual Button *Clone(GameObject *owner) override;

		void Load(const std::string &path);
		void Load(int id);
		sf::RectangleShape &GetFrame();

	private:
		void ComputeBounds();
		virtual void CheckSelection() override;

		sf::RectangleShape frame;
		sf::FloatRect bounds;
		TextRenderer *text;
	};
}