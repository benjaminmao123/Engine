#include "bmepch.h"
#include "StateMachine.h"
#include "State.h"
#include "StateTransition.h"
#include "Context.h"
#include "GameObject.h"

/// <summary>
///		Parameterized constructor.
///		Initialzies the owner of this Component and the context as well
///		as the current active state.
/// </summary>
/// <param name="owner">
///		The owner of this Component.
///	</param>
///	<param name="context">
///		The Context object.
///	</param>
///	<return>
///		void
///	</return>
bme::StateMachine::StateMachine(GameObject *owner, Context &context)
	: Component(owner, context), activeState(nullptr)
{

}

/// <summary>
///		Destructor.
///		Cleans up all dynamically allocated State objects.
/// </summary>
///	<return>
///		void
///	</return>
bme::StateMachine::~StateMachine()
{
	for (auto &pair : states)
		delete pair.second;
}

/// <summary>
///		Overriden Start() method.
///		Sets activeState to the first State added
///		to the unordered_map of States.
///		Calls the OnStateEnter() method of activeState.
/// </summary>
///	<return>
///		void
///	</return>
void bme::StateMachine::Start()
{
	activeState = states[0];

	if (activeState)
		activeState->OnStateEnter();
}

/// <summary>
///		Checks if the State should transition
///		every frame.
/// </summary>
///	<return>
///		void
///	</return>
void bme::StateMachine::Update()
{
	Evaluate();
}

/// <summary>
///		Calls the Evaluate() method for the activeState
///		every frame. If Evaluate() returns true, 
///		calls the OnStateExit() method, sets the 
///		activeState to the result from the Evaluate() method,
///		and then calls the OnStateEnter() method. 
///		Otherwise, simply just calls OnStateUpdate().
/// </summary>
///	<return>
///		void
///	</return>
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

/// <summary>
///		Adds a State to the StateMachine.
/// </summary>
///	<param name="state">
///		A pointer to the State object to add.
///	</param>
///	<return>
///		void
///	</return>
void bme::StateMachine::AddState(State *state)
{
	states.insert(std::make_pair(state->GetID(), state));
}

/// <summary>
///		Adds a StateTransition to the StateMachine.
/// </summary>
///	<param name="start">
///		A pointer to the start State of the StateTransition.
///	</param>
///	<param name="end">
///		A pointer to the end State of the StateTransition.
///	</param>
///	<return>
///		void
///	</return>
void bme::StateMachine::AddTransition(State *start, State *end)
{
	start->AddTransition(StateTransition(start, end));
}

/// <summary>
///		Retrieves a State with the given id.
/// </summary>
///	<param name="id">
///		id of the State to retrieve.
///	</param>
///	<return>
///		A pointer to the State with the given id.
///	</return>
bme::State *bme::StateMachine::GetState(int id)
{
	return states[id];
}