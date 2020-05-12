#include "AudioManager.h"
#include "GameObject.h"
#include "Context.h"
#include "AudioSource.h"

AudioManager::AudioManager(bme::GameObject *owner, bme::Context &context)
	: Component(owner, context), currentSong("")
{
	
}

AudioManager *AudioManager::Clone(bme::GameObject *owner) 
{
	AudioManager *clone = new AudioManager(owner, GetContext());
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->SetIsEnabled(GetIsEnabled());
	clone->sounds = sounds;

	return clone;
}

void AudioManager::AddSound(const std::string &path, const std::string &name)
{
	bme::AudioSource *source = GetOwner()->AddComponent<bme::AudioSource>();
	source->Load(path);

	sounds.insert(std::make_pair(name, source));
}

void AudioManager::RemoveSound(const std::string &name)
{
	sounds.erase(name);
}

sf::Sound *AudioManager::GetSound(const std::string &name)
{
	auto it = sounds.find(name);

	return &it->second->GetClip();
}

