#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include "Resource.h"

namespace bme
{
	class DLLEXPORT TextureResource : public Resource
	{
	public:
		virtual bool Load(const std::string &path) override;

		const sf::Texture &Get() const;

	private:
		sf::Texture texture;
	};
}