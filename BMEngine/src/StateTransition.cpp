#include "StateTransition.h"
#include "State.h"
#include "StateCondition.h"

bme::StateTransition::StateTransition(State *start, State *dest)
	: start(start), dest(dest)
{

}

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

void bme::StateTransition::AddCondition(StateCondition *condition)
{
	conditions.push_back(condition);
}
