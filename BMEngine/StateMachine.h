#pragma once

#include <string>

#include "HashMap.h"
#include "Component.h"

namespace bme
{
	class State;

	class StateMachine : public Component
	{
	public:
		StateMachine(GameObject *owner, Context &context);

		virtual void Start() override;
		virtual void Update() override;

		void AddState(State *state);
		void AddTransition(State *start, State *end);
		State *GetState(unsigned int id);

	private:
		void Evaluate();

		unordered_map<unsigned int, State *> states;
		State *activeState;
	};
}