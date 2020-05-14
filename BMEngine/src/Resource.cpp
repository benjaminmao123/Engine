#include "bmepch.h"
#include "Resource.h"

int bme::Resource::nextID = 0;

///	<summary>
///		Default constructor. Initializes id to a unique value.
/// </summary>
///	<return>
///		void
///	</return>
bme::Resource::Resource()
	: id(nextID++)
{

}

///	<summary>
///		Destructor.
/// </summary>
///	<return>
///		void
///	</return>
bme::Resource::~Resource()
{

}

///	<summary>
///		Getter function for the path this Resource is located
///		at.
/// </summary>
///	<return>
///		An std::string representing the path.
///	</return>
const std::string &bme::Resource::Path() const
{
	return path;
}

///	<summary>
///		Getter function for the id of this Resource.
/// </summary>
///	<return>
///		An int representing the id.
///	</return>
int bme::Resource::ID() const
{
	return id;
}
