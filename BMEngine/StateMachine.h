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
		State *GetState(int id);

	private:
		void OnStateEnter();
		void OnStateExit();
		void OnStateUpdate();
		void SwitchState();

		unordered_map<int, State *> states;
		State *activeState;
	};
}