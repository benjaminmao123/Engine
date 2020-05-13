#include "bmepch.h"
#include "Point.h"
#include "Context.h"
#include "GameObject.h"

bme::Point::Point(GameObject *owner, Context &context, int zOrder)
	: Renderer2D(owner, context, zOrder), point(10)
{

}

void bme::Point::Render()
{
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
