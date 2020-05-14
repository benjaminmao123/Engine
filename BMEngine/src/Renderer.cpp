#include "bmepch.h"
#include "Renderer.h"

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
bme::Renderer::Renderer(bme::GameObject *owner, bme::Context &context)
	: Component(owner, context)
{

}

/// <summary>
///		This function is responsible for calling the Render() function.
///		Necessary operations are performed here such as initialization before
///		the Render() call.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Renderer::OnRender()
{

}
