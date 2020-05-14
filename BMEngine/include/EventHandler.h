#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>

namespace bme
{
	class Event;

	/// <summary>
	///		Handles invoking events, adding, and removing
	///		events.
	/// </summary>
	class EventHandler
	{
	public:
		DLLEXPORT EventHandler();
		DLLEXPORT EventHandler(const EventHandler &other);
		DLLEXPORT ~EventHandler();

		DLLEXPORT void Invoke();
		
		DLLEXPORT EventHandler &operator+=(Event *event);
		DLLEXPORT EventHandler &operator-=(Event *event);

	private:
		std::vector<Event *> events;
	};
}