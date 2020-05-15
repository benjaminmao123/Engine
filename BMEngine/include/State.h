#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>
#include <string>

namespace bme
{
	class StateTransition;

	/// <summary>
	///		Base State class to be used with StateMachine class.
	///		Any derived State class will have a
	///		unique id and a vector of transitions.
	/// </summary>
	class DLLEXPORT State
	{
	public:
		State(const std::string &name);
		State(const State &rhs);
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
		int id;
		static int nextID;
		std::vector<StateTransition> transitions;
	};
}