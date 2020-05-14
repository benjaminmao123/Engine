#include "bmepch.h"
#include "Renderer2D.h"
#include "Context.h"
#include "GameObject.h"

/// <summary>
///		Parameterized constructor. 
///		Initializes owner of the Component and Context.
///		Initializes optional parameter z-order which is used to determine the sorting 
///		order of 2D objects.
/// </summary>
/// <param name="owner">
///		The GameObject that that is owned by this Component.
///	</param>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
///	<param name="zOrder">
///		Optional argument to initialize z-order. Default is 0.
///	</param>
///	<returns>
///		void
///	</returns>
bme::Renderer2D::Renderer2D(GameObject *owner, Context &context, int zOrder)
	: Renderer(owner, context), zOrder(zOrder),
	  view(&context.GetWindow().getDefaultView())
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
void bme::Renderer2D::OnRender()
{
	GetContext().GetWindow().setView(*view);
	Render();
}

/// <summary>
///		Handles rendering an object onto the screen.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Renderer2D::Render()
{

}

/// <summary>
///		Getter function for the z-order.
/// </summary>
///	<returns>
///		The zOrder.
///	</returns>
int bme::Renderer2D::GetZOrder() const
{
	return zOrder;
}

/// <summary>
///		Sets the z-order.
/// </summary>
///	<param name="value">
///		The value to set the z-order.
///	</param>
/// <return>
///		void
///	</return>
void bme::Renderer2D::SetZOrder(int value)
{
	zOrder = value;
}

/// <summary>
///		Sets the view to a specified view.
/// </summary>
///	<param name="view">
///		The view to set the current view to.
///	</param>
/// <return>
///		void
///	</return>
void bme::Renderer2D::SetView(const sf::View *view)
{
	this->view = view;
}

/// <summary>
///		Getter function for the current view.
/// </summary>
/// <return>
///		A pointer to the current view.
///	</return>
const sf::View *const bme::Renderer2D::GetView() const
{
	return view;
}
