#pragma once

#include <string>

#include "Vector.h"

namespace bme
{
	class StateTransition;

	class State
	{
	public:
		State(const std::string &name);
		virtual ~State();

		virtual void OnStateEnter();
		virtual void OnStateUpdate();
		virtual void OnStateExit();

		State *Evaluate();
		void AddTransition(const StateTransition &transition);
		void SetName(const std::string &name);
		const std::string &GetName() const;
		unsigned int GetID() const;

	private:
		std::string name;
		unsigned int id;
		static unsigned int nextID;
		vector<StateTransition> transitions;
	};
}