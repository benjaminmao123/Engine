#include "bmepch.h"
#include "BoxCollider2D.h"
#include "GameObject.h"
#include "Context.h"

bme::BoxCollider2D::BoxCollider2D(GameObject *owner, Context &context)
	: Collider(owner, context)
{
	rect.width = 100;
	rect.height = 100;
	rect.left = GetTransformable().getPosition().x - (rect.width / 2);
	rect.top = GetTransformable().getPosition().y - (rect.height / 2);
}

void bme::BoxCollider2D::Update()
{
	rect.left = GetTransformable().getPosition().x - (rect.width / 2);
	rect.top = GetTransformable().getPosition().y - (rect.height / 2);
}

bool bme::BoxCollider2D::Intersects() const
{
	

	return false;
}

bme::BoxCollider2D *bme::BoxCollider2D::Clone(GameObject *owner)
{
	BoxCollider2D *clone = new BoxCollider2D(owner, GetContext());

	return clone;
}

void bme::BoxCollider2D::SetBounds(float width, float height)
{
	rect.width = width;
	rect.height = height;
}

void bme::BoxCollider2D::SetBounds(const sf::Vector2f &dims)
{
	rect.width = dims.x;
	rect.height = dims.y;
}
