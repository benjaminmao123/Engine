#pragma once

namespace bme
{
	class StateCondition
	{
	public:
		virtual ~StateCondition();

		virtual bool Evaluate() const = 0;
	};
}