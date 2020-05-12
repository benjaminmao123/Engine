#include "StateMachine.h"
#include "State.h"
#include "StateTransition.h"
#include "Context.h"
#include "GameObject.h"

bme::StateMachine::StateMachine(GameObject *owner, Context &context)
	: Component(owner, context), activeState(nullptr)
{

}

void bme::StateMachine::Start()
{
	activeState = states[0];

	if (activeState)
		activeState->OnStateEnter();
}

void bme::StateMachine::Update()
{
	Evaluate();
}

void bme::StateMachine::Evaluate()
{
	if (activeState)
	{
		State *next = activeState->Evaluate();

		if (next)
		{
			activeState->OnStateExit();
			activeState = next;
			activeState->OnStateEnter();
		}
		else
			activeState->OnStateUpdate();
	}
}

void bme::StateMachine::AddState(State *state)
{
	states.insert(std::make_pair(state->GetID(), state));
}

void bme::StateMachine::AddTransition(State *start, State *end)
{
	start->AddTransition(StateTransition(start, end));
}

bme::State *bme::StateMachine::GetState(unsigned int id)
{
	return states[id];
}