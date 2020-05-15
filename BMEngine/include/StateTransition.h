#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>

namespace bme
{
	class State;
	class StateCondition;

	/// <summary>
	///		Transitions for the StateMachine.
	///		Each State object will have a list of StateTransitions.
	///		A transition consists of a starting state, ending state,
	///		and a list of conditions.
	///	</summary>
	class DLLEXPORT StateTransition
	{
	public:
		StateTransition(State *start, State *dest);
		StateTransition(const StateTransition &rhs);

		State *Evaluate();
		void AddCondition(StateCondition *condition);

	private:
		std::vector<StateCondition *> conditions;
		State *start;
		State *dest;
	};
}