/// <summary>
///		Camera component for the 2D world.
///		Renders the scene to a specific viewport that can be
///		set by the user.
/// </summary>

#include "bmepch.h"
#include "Camera2D.h"
#include "Context.h"

/// <summary>
///		Parameterized constructor. Initializes owner of the class and context.
///		Initializes the viewport to the size of the screen.
/// </summary>
/// <param name="owner">
///		The GameObject that owns this component.
///	</param>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
///	<returns>
///		void
///	</returns>
bme::Camera2D::Camera2D(GameObject *owner, Context &context)
	: Component(owner, context)
{
	view.setCenter(GetTransformable().getPosition());
	view.setSize(sf::Vector2f(context.GetWindow().getSize()));
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	ComputeViewBounds();
}

/// <summary>
///		Called every frame to update the boundaries of the viewport.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Camera2D::Update()
{
	ComputeViewBounds();
}

/// <summary>
///		Method to clone the component. Creates a deep copy of the component.
/// </summary>
/// <param name="owner">
///		The GameObject that owns this component.
///	</param>
///	<returns>
///		A pointer to the clone.
///	</returns>
bme::Camera2D *bme::Camera2D::Clone(GameObject *owner)
{
	Camera2D *clone = new Camera2D(owner, GetContext());
	clone->view = view;
	clone->viewBounds = viewBounds;
	clone->SetIsEnabled(GetIsEnabled());
	clone->SetExecutionOrder(GetExecutionOrder());

	return clone;
}

/// <summary>
///		Computes the boundaries of the viewport.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Camera2D::ComputeViewBounds()
{
	viewBounds.left = view.getViewport().left * view.getSize().x;
	viewBounds.top = view.getViewport().top * view.getSize().y;
	viewBounds.width = view.getSize().x;
	viewBounds.height = view.getSize().y;
}
