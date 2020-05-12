#include "AudioSource.h"
#include "SoundResource.h"
#include "ResourceManager.h"
#include "Context.h"
#include "GameObject.h"

bme::AudioSource::AudioSource(GameObject *owner, Context &context)
	: Component(owner, context)
{

}

bme::AudioSource *bme::AudioSource::Clone(GameObject *owner)
{
	AudioSource *clone = new AudioSource(owner, GetContext());
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->SetIsEnabled(GetIsEnabled());
	clone->GetClip() = audioClip;

	return clone;
}

void bme::AudioSource::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<SoundResource>(path);
	SoundResource *sound = GetContext().GetResourceManager().Get<SoundResource>(assetID);

	if (sound)
		audioClip.setBuffer(sound->Get());
}

void bme::AudioSource::Load(int id)
{
	SoundResource *sound = GetContext().GetResourceManager().Get<SoundResource>(id);

	if (sound)
		audioClip.setBuffer(sound->Get());
}

sf::Sound &bme::AudioSource::GetClip()
{
	return audioClip;
}
