#pragma once

#include "BMEngine.h"

using namespace bme;

class Movement : public Component
{
public:
	Movement(GameObject *owner, Context &context)
		: Component(owner, context), speed(200)
	{

	}

	virtual void Update() override
	{
		if (GetContext().GetInputManager().GetKey(sf::Keyboard::Left))
			GetTransformable().move(-speed * GetContext().GetTimeManager().GetDeltaTime(), 0);
		if (GetContext().GetInputManager().GetKey(sf::Keyboard::Right))
			GetTransformable().move(speed * GetContext().GetTimeManager().GetDeltaTime(), 0);
		if (GetContext().GetInputManager().GetKey(sf::Keyboard::Up))
			GetTransformable().move(0, -speed * GetContext().GetTimeManager().GetDeltaTime());
		if (GetContext().GetInputManager().GetKey(sf::Keyboard::Down))
			GetTransformable().move(0, speed * GetContext().GetTimeManager().GetDeltaTime());
	}

	virtual Movement *Clone(GameObject *owner) override
	{
		Movement *clone = new Movement(owner, GetContext());

		return clone;
	}

	void SetSpeed(float speed)
	{
		this->speed = speed;
	}

private:
	float speed;
};