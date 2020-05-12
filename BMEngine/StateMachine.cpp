#include "StateMachine.h"
#include "State.h"
#include "StateTransition.h"
#include "Context.h"
#include "GameObject.h"

bme::StateMachine::StateMachine(GameObject *owner, Context &context)
	: Component(owner, context)
{

}

void bme::StateMachine::Start()
{
	OnStateEnter();
}

void bme::StateMachine::Update()
{
	
}

void bme::StateMachine::OnStateEnter()
{
	if (activeState)
		activeState->OnStateEnter();
}

void bme::StateMachine::OnStateExit()
{
	if (activeState)
		activeState->OnStateExit();
}

void bme::StateMachine::OnStateUpdate()
{
	if (activeState)
		activeState->OnStateUpdate();
}

void bme::StateMachine::SwitchState()
{
	//if (activeState->)
}

void bme::StateMachine::AddState(State *state)
{
	states.insert(std::make_pair(state->GetID(), state));
}

void bme::StateMachine::AddTransition(State *start, State *end)
{
	start->AddTransition(StateTransition(start, end));
}

bme::State *bme::StateMachine::GetState(int id)
{
	return states[id];
}