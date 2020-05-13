#include "Renderer2D.h"
#include "Context.h"
#include "GameObject.h"

bme::Renderer2D::Renderer2D(GameObject *owner, Context &context, int zOrder)
	: Renderer(owner, context), zOrder(zOrder),
	  view(&context.GetWindow().getDefaultView())
{

}

void bme::Renderer2D::OnRender()
{
	GetContext().GetWindow().setView(*view);
	Render();
}

void bme::Renderer2D::Render()
{

}

int bme::Renderer2D::GetZOrder() const
{
	return zOrder;
}

void bme::Renderer2D::SetZOrder(int value)
{
	zOrder = value;
}

void bme::Renderer2D::SetView(const sf::View *view)
{
	this->view = view;
}

const sf::View *const bme::Renderer2D::GetView() const
{
	return view;
}
