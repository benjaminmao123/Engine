#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <unordered_map>
#include <string>

#include "Resource.h"

namespace bme
{
	///	<summary>
	///		Handles all of the Resource management.
	///		Resources are stored as pointers in a std::unordered_map
	///		with the path as the key.
	/// </summary>
	class DLLEXPORT ResourceManager
	{
	public:
		~ResourceManager();

		void Remove(int id);

		template <typename T>
		int Add(const std::string &path);
		template<typename T>
		T *Get(int id);

	private:
		std::unordered_map<std::string, Resource *> resources;
	};
}

///	<summary>
///		Adds a Resource to the ResourceManager from a given path.
///		If the path already exists, then the id is returned, otherwise
///		the Resource is added and -1 is returned.
/// </summary>
///	<param name="path">
///		The path of the Resource to add.
///	</param>
///	<return>
///		The id of the Resource if it already exists. Otherwise -1.
///	</return>
template <typename T>
inline int bme::ResourceManager::Add(const std::string &path)
{
	auto it = resources.find(path);

	if (it != resources.end())
		return it->second->ID();

	static_assert(std::is_base_of<Resource, T>::value,
		"T must derive from component!");

	Resource *resource = new T;

	if (!resource->Load(path))
	{
		delete resource;
		return -1;
	}

	resources.insert(std::make_pair(path, resource));

	return resource->ID();
}

///	<summary>
///		Retrieves a Resource from the ResourceManager with the
///		given id.
/// </summary>
///	<param name="id">
///		The id of the Resource to retrieve.
///	</param>
///	<return>
///		A pointer to the Resource.
///	</return>
template <typename T>
inline T *bme::ResourceManager::Get(int id)
{
	for (auto i : resources)
	{
		if (i.second->ID() == id)
		{
			T *resource = dynamic_cast<T *>(i.second);

			return resource;
		}
	}

	return nullptr;
}