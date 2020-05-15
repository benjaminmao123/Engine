#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace bme
{
	/// <summary>
	///		Base class for all StateCondition objects.
	///		StateConditions are used with StateTransitions to
	///		specify a condition for switching to another State.
	///		All derived classes must override the Evaluate() method.
	///	</summary>
	class DLLEXPORT StateCondition
	{
	public:
		virtual ~StateCondition();

		virtual bool Evaluate();
	};
}