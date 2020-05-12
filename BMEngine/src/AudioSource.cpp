/// <summary>
///		Class provides a way for the user to get sound
///		into their game.
/// </summary>

#include "AudioSource.h"
#include "SoundResource.h"
#include "ResourceManager.h"
#include "Context.h"
#include "GameObject.h"

/// <summary>
///		Overloaded constructor. Initializes owner of the class and context.
/// </summary>
/// <param name="owner">
///		The GameObject that owns this component.
///	</param>
/// <param name="context>
///		Context object that contains relevant information
///		needed by the class.
///	</param>
///	<returns>
///		void
///	</returns>
bme::AudioSource::AudioSource(GameObject *owner, Context &context)
	: Component(owner, context)
{

}

/// <summary>
///		Method to clone the component. Creates a deep copy of the component.
/// </summary>
/// <param name="owner">
///		The GameObject that owns this component.
///	</param>
///	<returns>
///		A pointer to the clone.
///	</returns>
bme::AudioSource *bme::AudioSource::Clone(GameObject *owner)
{
	AudioSource *clone = new AudioSource(owner, GetContext());
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->SetIsEnabled(GetIsEnabled());
	clone->GetClip() = audioClip;

	return clone;
}

/// <summary>
///		Loads a given sound into the AudioSource.
/// </summary>
/// <param name="path">
///		The path of the sound.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::AudioSource::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<SoundResource>(path);
	SoundResource *sound = GetContext().GetResourceManager().Get<SoundResource>(assetID);

	if (sound)
		audioClip.setBuffer(sound->Get());
}

/// <summary>
///		Loads a sound into the AudioSource from the ResourceManager if it already exists.
/// </summary>
/// <param name="id">
///		The id of the sound to load.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::AudioSource::Load(int id)
{
	SoundResource *sound = GetContext().GetResourceManager().Get<SoundResource>(id);

	if (sound)
		audioClip.setBuffer(sound->Get());
}

/// <summary>
///		Retrieves the sf::Sound associated with the AudioSource.
/// </summary>
///	<returns>
///		Returns a reference to the sf::Sound object.
///	</returns>
sf::Sound &bme::AudioSource::GetClip()
{
	return audioClip;
}
