#include "bmepch.h"
#include "Collider.h"
#include "GameObject.h"
#include "Context.h"

bme::Collider::Collider(GameObject *owner, Context &context)
	: Component(owner, context)
{

}
