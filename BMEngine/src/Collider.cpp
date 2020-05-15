#include "bmepch.h"
#include "Collider.h"
#include "GameObject.h"
#include "Context.h"

/// <summary>
///		Parameterized constructor.
///		Initializes owner, context.
///	</summary>
/// <param name="owner">
///		Pointer to the owner of this Collider.
///	</param>
///	<param name="context>
///		The Context object.
///	</param>
///	<return>
///		void
/// </return>
bme::Collider::Collider(GameObject *owner, Context &context)
	: Component(owner, context)
{

}
