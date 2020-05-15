#include "bmepch.h"
#include "StateTransition.h"
#include "State.h"
#include "StateCondition.h"

///	<summary>
///		Parameterized constructor.
///		Initializes the starting and ending State.
///	</summary>
///	<param name="start">
///		A pointer to the starting State.
/// </param>
///	<param name="dest">
///		A pointer to the destination State.
///	</param>
///	<return>
///		void
///	</return>
bme::StateTransition::StateTransition(State *start, State *dest)
	: start(start), dest(dest)
{

}

///	<summary>
///		Checks whether or not the conditions are met to
///		go to the next state.
///	</summary>
///	<return>
///		If the conditions are met to transition to another
///		state, a State pointer to the next State is returned,
///		else nullptr.
///	</return>
bme::State *bme::StateTransition::Evaluate()
{
	if (conditions.empty()) 
		return dest;

	for (auto &condition : conditions)
	{
		if (!condition->Evaluate())
			return dest;
	}

	return nullptr;
}

///	<summary>
///		Adds a StateCondition to the list of StateConditions.
///	</summary>
///	<param name="condition">
///		The StateCondition pointer to add.
///	<return>
///		void
///	</return>
void bme::StateTransition::AddCondition(StateCondition *condition)
{
	conditions.push_back(condition);
}
