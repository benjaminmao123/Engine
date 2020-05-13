/// <summary>
///		Handles invoking events, adding, and removing
///		events.
/// </summary>

#include "bmepch.h"
#include "EventHandler.h"
#include "Event.h"

/// <summary>
///		Default constructor.
///	</summary>
///	<return>
///		void
///	</return>
bme::EventHandler::EventHandler()
{

}

/// <summary>
///		Copy constructor.
///	</summary>
///	<return>
///		void
///	</return>
bme::EventHandler::EventHandler(const EventHandler &other)
{
	for (auto &e : events)
		operator+=(e);
}

/// <summary>
///		Destructor.
///	</summary>
///	<return>
///		void
///	</return>
bme::EventHandler::~EventHandler()
{
	for (auto &e : events)
		delete e;
}

/// <summary>
///		Invokes all of the events in the list of
///		events.
///	</summary>
///	<return>
///		void
///	</return>
void bme::EventHandler::Invoke()
{
	for (auto &e : events)
		e->Invoke();
}

/// <summary>
///		Overloaded addition assignment operator.
///		Adds an event to the list of events.
///	</summary>
///	<param name="event">
///		Event pointer to add to the list of events.
///	</param>
///	<return>
///		void
///	</return>
bme::EventHandler &bme::EventHandler::operator+=(Event *event)
{
	for (const auto &e : events)
	{
		if (e == event)
			return *this;
	}

	events.push_back(event);

	return *this;
}

/// <summary>
///		Overloaded subtraction assignment operator.
///		Removes an event from the list of events.
///	</summary>
///	<param name="event">
///		Event pointer to remove from the list of events.
///	</param>
///	<return>
///		void
///	</return>
bme::EventHandler &bme::EventHandler::operator-=(Event *event)
{
	int index = 0;

	for (auto &e : events)
	{
		if (e == event)
		{
			events.erase(events.begin() + index);
			break;
		}

		++index;
	}

	return *this;
}
