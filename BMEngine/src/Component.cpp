#include "bmepch.h"
#include "Component.h"
#include "GameObject.h"
#include "Context.h"

/// <summary>
///		Parameterized constructor. 
///		Initializes owner of the Component and Context.
/// </summary>
/// <param name="owner">
///		The GameObject that that is owned by this Component.
///	</param>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
///	<returns>
///		void
///	</returns>
bme::Component::Component(GameObject *owner, Context &context)
	: owner(owner), context(context), isEnabled(true),
	  isAwakeCalled(false), isStartCalled(false),
	  executionOrder(0)
{

}

/// <summary>
///		Destructor.
/// </summary>
///	<returns>
///		void
///	</returns>
bme::Component::~Component()
{

}

/// <summary>
///		Wrapper function that calls Awake() and
///		sets the isAwakeCalled flag to true.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::OnAwake()
{
	if (!isAwakeCalled)
	{
		isAwakeCalled = true;
		Awake();
	}
}

/// <summary>
///		Wrapper function that calls Start() and
///		sets the isStartCalled flag to true.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::OnStart()
{
	if (!isStartCalled)
	{
		isStartCalled = true;
		Start();
	}
}

/// <summary>
///		Base Awake() function. This method is called
///		when the Scene starts, before any Start() method.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::Awake()
{

}

/// <summary>
///		Base Start() function. This method is called
///		when the Scene starts, after any Start() method.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::Start()
{

}

/// <summary>
///		Base Update() function. This method is called
///		every frame to Update the Component.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::Update()
{

}

/// <summary>
///		Base LateUpdate() function. This method is called
///		every frame after the Update() method.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Component::LateUpdate()
{

}

/// <summary>
///		Getter function for the isEnabled status.
/// </summary>
///	<returns>
///		The isEnabled boolean which specifies whether the
///		Component is enabled or not.
///	</returns>
bool bme::Component::GetIsEnabled() const
{
	return isEnabled;
}

/// <summary>
///		Setter function for the isEnabled status.
/// </summary>
///	<param name="state">
///		Boolean to set the isEnabled variable.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Component::SetIsEnabled(bool state)
{
	isEnabled = state;
}

/// <summary>
///		Getter function for the execution order of
///		the Component.
/// </summary>
///	<returns>
///		The execution order of the given Component.
///	</returns>
int bme::Component::GetExecutionOrder() const
{
	return executionOrder;
}

/// <summary>
///		Setter function for the execution order.
/// </summary>
///	<param name="value">
///		Integer value to set the execution order.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Component::SetExecutionOrder(int value)
{
	executionOrder = value;
}

/// <summary>
///		Getter function for the GameObject that owns
///		this Component.
/// </summary>
///	<returns>
///		A pointer to the GameObject that owns this
///		Component.
///	</returns>
bme::GameObject *bme::Component::GetOwner()
{
	return owner;
}

/// <summary>
///		Getter function for transformable of the
///		GameObject that owns this Component.
/// </summary>
///	<returns>
///		The sf::Transformable object of the GameObject
///		that owns this Component.
///	</returns>
sf::Transformable &bme::Component::GetTransformable()
{
	return owner->GetTransformable();
}

/// <summary>
///		Getter function for world transform of the
///		GameObject that owns this Component.
/// </summary>
///	<returns>
///		The world transform of the GameObject
///		that owns this Component.
///	</returns>
const sf::Transform &bme::Component::GetWorldTransform() const
{
	return owner->GetWorldTransform();
}

/// <summary>
///		Getter function for the Context.
/// </summary>
///	<returns>
///		The Context object.
///	</returns>
bme::Context &bme::Component::GetContext()
{
	return context;
}
