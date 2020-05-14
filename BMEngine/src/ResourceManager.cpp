#include "bmepch.h"
#include "ResourceManager.h"

///	<summary>
///		Destructor. Cleans up all dynamically allocated
///		Resources.
/// </summary>
///	<return>
///		void
///	</return>
bme::ResourceManager::~ResourceManager()
{
	for (auto &i : resources)
		delete i.second;
}

///	<summary>
///		Removes a Resource with the given id and
///		deletes it.
/// </summary>
///	<param name="id">
///		The id of the Resource to remove.
///	</param>
///	<return>
///		void
///	</return>
void bme::ResourceManager::Remove(int id)
{
	for (auto &i : resources)
	{
		if (i.second->ID() == id)
		{
			delete i.second;
			resources.erase(i.first);
		}
	}
}