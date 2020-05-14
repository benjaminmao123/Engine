#include "bmepch.h"
#include "Point.h"
#include "Context.h"
#include "GameObject.h"

/// <summary>
///		Parameterized Constructor. Initializes the owner, context,
///		and zOrder of the object.
/// </summary>
///	<param name="owner">
///		The GameObject that owns this Component.
///	</param>
///	<param name="context">
///		Context needed by this GameObject.
///	</param>
///	<param name="zOrder">
///		The z-order of this object which is used to sort in
///		rendering.
///	</param>
///	<return>
///		void
///	</return>
bme::Point::Point(GameObject *owner, Context &context, int zOrder)
	: Renderer2D(owner, context, zOrder), point(10)
{

}

/// <summary>
///		Draws the point onto the screen.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Point::Render()
{
	GetContext().GetWindow().draw(point, GetWorldTransform());
}

/// <summary>
///		Clone method which creates a deep copy of
///		the object.
/// </summary>
///	<param name="owner">
///		The GameObject that will own the cloned Component.
///	</param>
///	<return>
///		void
///	</return>
bme::Point *bme::Point::Clone(GameObject *owner)
{
	Point *clone = new Point(owner, GetContext());
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->point = point;
	clone->SetZOrder(GetZOrder());
	clone->SetIsEnabled(GetIsEnabled());
	clone->SetView(GetView());

	return clone;
}

/// <summary>
///		Getter method to the sf::CircleShape object.
/// </summary>
///	<return>
///		The sf::CircleShape object representing the point.
///	</return>
sf::CircleShape &bme::Point::GetPoint()
{
	return point;
}
