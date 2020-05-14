#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace bme
{
	/// <summary>
	///		Base Event class which can be
	///		overriden by the user to create
	///		custom events.
	/// </summary>
	class DLLEXPORT Event
	{
	public:
		Event();
		virtual ~Event();

		virtual void Invoke() = 0;

		bool operator==(const Event &rhs) const;
		bool operator!=(const Event &rhs) const;

	private:
		int id;
		static int nextID;
	};
}