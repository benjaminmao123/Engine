#pragma once

#include "Vector.h"

namespace bme
{
	class State;
	class StateCondition;

	class StateTransition
	{
	public:
		StateTransition(State *start, State *dest);

		State *Evaluate();
		void AddCondition(StateCondition *condition);

	private:
		vector<StateCondition *> conditions;

		State *start;
		State *dest;
	};
}