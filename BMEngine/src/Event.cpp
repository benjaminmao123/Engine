/// <summary>
///		Base Event class which can be
///		overriden by the user to create
///		custom events.
/// </summary>

#include "bmepch.h"
#include "Event.h"

int bme::Event::nextID = 0;

/// <summary>
///		Default constructor. Simply assigns an ID
///		to the Event.
///	</summary>
///	<return>
///		void
///	</return>
bme::Event::Event()
	: id(nextID++)
{

}

/// <summary>
///		Destructor.
///	</summary>
///	<return>
///		void
///	</return>
bme::Event::~Event()
{

}

/// <summary>
///		Overloaded equality operator.
///	</summary>
///	<return>
///		True if the IDs of both Events match.
///	</return>
bool bme::Event::operator==(const Event &rhs) const
{
	return id == rhs.id;
}

/// <summary>
///		Overloaded inequality operator.
///	</summary>
///	<return>
///		True if the IDs of both Events do not match.
///	</return>
bool bme::Event::operator!=(const Event &rhs) const
{
	return id != rhs.id;
}
