#include "bmepch.h"
#include "TextureResource.h"

///	<summary>
///		Loads a sound from a given path into a Texture
///		object.
/// </summary>
///	<param name="path">
///		The path that the texture file is located at.
///	</param>
///	<return>
///		True if loading was successful, false otherwise.
///	</return>
bool bme::TextureResource::Load(const std::string &path)
{
	return texture.loadFromFile(path);
}

///	<summary>
///		Retrieves the Texture object associated with this
///		Resource.
/// </summary>
///	<return>
///		A const reference to the Texture object.
///	</return>
const sf::Texture &bme::TextureResource::Get() const
{
	return texture;
}
