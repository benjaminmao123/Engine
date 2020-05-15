#include "bmepch.h"
#include "State.h"
#include "StateTransition.h"

int bme::State::nextID = 0;

///	<summary>
///		Paramterized constructor.
///		Initializes the name of the State and assigns
///		a unique id.
/// </summary>
///	<param name="name">
///		A std::string to assign as the name.
///	</param>
///	<return>
///		void
///	</return>
bme::State::State(const std::string &name)
	: name(name), id(nextID++)
{

}

///	<summary>
///		virtual destructor.
/// </summary>
///	<return>
///		void
///	</return>
bme::State::~State()
{

}

///	<summary>
///		Called upon entering a State.
/// </summary>
///	<return>
///		void
///	</return>
void bme::State::OnStateEnter()
{

}

///	<summary>
///		Called every frame to update the
///		current State.
/// </summary>
///	<return>
///		void
///	</return>
void bme::State::OnStateUpdate()
{

}

///	<summary>
///		Called every when exiting a State.
/// </summary>
///	<return>
///		void
///	</return>
void bme::State::OnStateExit()
{

}

///	<summary>
///		Checks if all conditions are met for a transition
///		to occur.
/// </summary>
///	<return>
///		True if conditions are met, otherwise false.
///	</return>
bme::State *bme::State::Evaluate()
{
	for (auto &transition : transitions)
	{
		if (transition.Evaluate())
			return transition.Evaluate();
	}
		
	return nullptr;
}

///	<summary>
///		Adds a StateTransition to the list of StateTransitions.
/// </summary>
///	<param name="transition">
///		The StateTransition object to add to the list of StateTransitions.
///	</param>
///	<return>
///		void
///	</return>
void bme::State::AddTransition(const StateTransition &transition)
{
	transitions.push_back(transition);
}

///	<summary>
///		Sets the name of the State.
/// </summary>
///	<param name="name">
///		The std::string to set the name to.
///	</param>
///	<return>
///		void
///	</return>
void bme::State::SetName(const std::string &name)
{
	this->name = name;
}

///	<summary>
///		Retrieves the name of the State.
/// </summary>
///	<return>
///		The std::string representing name of the State.
///	</return>
const std::string &bme::State::GetName() const
{
	return name;
}

///	<summary>
///		Retrieves the id of the State.
/// </summary>
///	<return>
///		The int representing the id of the State.
///	</return>
unsigned int bme::State::GetID() const
{
	return id;
}
