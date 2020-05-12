#pragma once

#include <SFML\Graphics.hpp>
#include <string>

#include "AudioSource.h"
#include "HashMap.h"
#include "Component.h"

class AudioManager : public bme::Component
{
public:
	AudioManager(bme::GameObject *owner, bme::Context &context);

	virtual AudioManager *Clone(bme::GameObject *owner) override;

	void AddSound(const std::string &path, const std::string &name);
	void RemoveSound(const std::string &name);
	sf::Sound *GetSound(const std::string &name);

private:
	unordered_map<std::string, bme::AudioSource *> sounds;
	std::string currentSong;
};