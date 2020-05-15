#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <SFML\Graphics.hpp>
#include <string>

#include "Resource.h"

namespace bme
{
	///	<summary>
	///		Resource class that handles textures.
	///		Uses sf::Texture objects to store loaded
	///		textures.
	/// </summary>
	class DLLEXPORT TextureResource : public Resource
	{
	public:
		virtual bool Load(const std::string &path) override;

		const sf::Texture &Get() const;

	private:
		sf::Texture texture;
	};
}