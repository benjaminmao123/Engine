#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <string>

namespace bme
{
	/// <summary>
	///		Base class for all resources that are managed by
	///		the ResourceManager. Each resource contains a unique id
	///		and path.
	/// </summary>
	class DLLEXPORT Resource
	{
	public:
		Resource();
		virtual ~Resource();

		virtual bool Load(const std::string &path) = 0;

		const std::string &Path() const;
		int ID() const;

	private:
		int id;
		static int nextID;
		std::string path;
	};
}