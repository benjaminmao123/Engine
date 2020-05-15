#include "bmepch.h"
#include "StateCondition.h"

///	<summary>
///		virtual destructor.
///	</summary>
///	<return>
///		void
///	</return>
bme::StateCondition::~StateCondition()
{

}

///	<summary>
///		virtual Evaluate function to be overriden
///		by all child classes.
///	</summary>
///	<return>
///		True if conditions are met, false otherwise.
///	</return>
bool bme::StateCondition::Evaluate()
{
	return true;
}
