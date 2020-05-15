#include "bmepch.h"
#include "SoundResource.h"

///	<summary>
///		Loads a sound from a given path into a SoundBuffer
///		object.
/// </summary>
///	<param name="path">
///		The path that the sound file is located at.
///	</param>
///	<return>
///		True if loading was successful, false otherwise.
///	</return>
bool bme::SoundResource::Load(const std::string &path)
{
	return buffer.loadFromFile(path);
}

///	<summary>
///		Retrieves the SoundBuffer object associated with this
///		Resource.
/// </summary>
///	<return>
///		A const reference to the SoundBuffer object.
///	</return>
const sf::SoundBuffer &bme::SoundResource::Get() const
{
	return buffer;
}
