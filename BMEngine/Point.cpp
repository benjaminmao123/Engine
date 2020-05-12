#include "Point.h"
#include "Context.h"

bme::Point::Point(GameObject *owner, Context &context)
	:	Renderer2D(owner, context), point(10)
{

}

void bme::Point::Render()
{
	Renderer2D::Render();

	GetContext().GetWindow().draw(point, GetWorldTransform());
}

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

sf::CircleShape &bme::Point::GetPoint()
{
	return point;
}
