#include "bmepch.h"
#include "SoundResource.h"

bool bme::SoundResource::Load(const std::string &path)
{
	return buffer.loadFromFile(path);
}

const sf::SoundBuffer &bme::SoundResource::Get() const
{
	return buffer;
}
