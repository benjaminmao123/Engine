#pragma once

#include <SFML\Audio.hpp>

#include "Resource.h"

namespace bme
{
	class SoundResource : public Resource
	{
	public:
		virtual bool Load(const std::string &path) override;

		const sf::SoundBuffer &Get() const;

	private:
		sf::SoundBuffer buffer;
	};
}