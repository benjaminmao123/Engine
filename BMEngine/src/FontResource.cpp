/// <summary>
///		Handles loading and retrieving font resources.
/// </summary>

#include "bmepch.h"
#include "FontResource.h"

/// <summary>
///		Loads a resource from file.
///	</summary>
///	<param name="path">
///		File path of the resource to load.
///	</param>
///	<return>
///		True if load was successful, false otherwise.
///	</return>
bool bme::FontResource::Load(const std::string &path)
{
	return font.loadFromFile(path);
}

/// <summary>
///		Gets the resource that was loaded.
///	</summary>
///	<return>
///		Returns the resource that was loaded.
///	</return>
const sf::Font &bme::FontResource::Get() const
{
	return font;
}
