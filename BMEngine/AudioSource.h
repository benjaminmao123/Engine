#pragma once

#include <SFML\Audio.hpp>

#include "Component.h"
#include "ResourceManager.h"

namespace bme
{
	class AudioSource : public Component
	{
	public:
		AudioSource(GameObject *owner, Context &context);

		virtual AudioSource *Clone(GameObject *owner) override;

		void Load(const std::string &path);
		void Load(int id);

		sf::Sound &GetClip();

	private:
		sf::Sound audioClip;
	};
}