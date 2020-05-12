#include "State.h"
#include "StateTransition.h"

unsigned int bme::State::nextID = 0;

bme::State::State(const std::string &name)
	: name(name), id(nextID++)
{

}

bme::State::~State()
{

}

void bme::State::OnStateEnter()
{

}

void bme::State::OnStateUpdate()
{

}

void bme::State::OnStateExit()
{

}

bme::State *bme::State::Evaluate()
{
	for (auto &transition : transitions)
	{
		if (transition.Evaluate())
			return transition.Evaluate();
	}
		
	return nullptr;
}

void bme::State::AddTransition(const StateTransition &transition)
{
	transitions.push_back(transition);
}

void bme::State::SetName(const std::string &name)
{
	this->name = name;
}

const std::string &bme::State::GetName() const
{
	return name;
}

unsigned int bme::State::GetID() const
{
	return id;
}
