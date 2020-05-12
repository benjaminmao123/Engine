#include "Button.h"
#include "GameObject.h"
#include "TextRenderer.h"
#include "TextureResource.h"
#include "Context.h"
#include "ResourceManager.h"
#include "InputManager.h"

bme::Button::Button(GameObject *owner, Context &context)
	: Renderer2D(owner, context), text(nullptr),
		frame(sf::Vector2f(100, 100))
{
	frame.setFillColor(GetNormalColor());
}

void bme::Button::Start()
{
	text = GetOwner()->GetComponentInChildren<TextRenderer>();

	if (text)
		text->SetZOrder(GetZOrder() + 1);
}

void bme::Button::Update()
{
	if (text)
	{
		text->GetRect().width = frame.getSize().x;
		text->GetRect().height = frame.getSize().y;
	}

	if (GetIsInteractable())
	{
		frame.setFillColor(GetNormalColor());
		CheckSelection();
	}
	else
		frame.setFillColor(GetDisabledColor());
}

void bme::Button::Render() 
{
	Renderer2D::Render();

	GetContext().GetWindow().draw(frame, GetWorldTransform());
}

bme::Button *bme::Button::Clone(GameObject *owner)
{
	Button *clone = new Button(owner, GetContext());

	clone->frame = frame;
	clone->bounds = bounds;
	clone->SetIsInteractable(GetIsInteractable());
	clone->SetNormalColor(GetNormalColor());
	clone->SetHighlightedColor(GetHighlightedColor());
	clone->SetDisabledColor(GetDisabledColor());
	clone->SetSelectedColor(GetSelectedColor());
	clone->SetPressedColor(GetPressedColor());
	clone->SetIsSelected(GetIsSelected());
	clone->GetOnClickEvents() = GetOnClickEvents();
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->SetZOrder(GetZOrder());
	clone->SetIsEnabled(GetIsEnabled());
	clone->SetView(GetView());

	return clone;
}

void bme::Button::CheckSelection()
{
	ComputeBounds();

	sf::Vector2f mousePosition = sf::Vector2f(
		float(GetContext().GetInputManager().MousePosition().x),
		float(GetContext().GetInputManager().MousePosition().y));

	if (bounds.contains(mousePosition))
	{
		frame.setFillColor(GetHighlightedColor());

		if (GetContext().GetInputManager().GetKey(sf::Mouse::Left))
			frame.setFillColor(GetPressedColor());

		if (GetContext().GetInputManager().GetKeyUp(sf::Mouse::Left))
			OnClick();
	}
}

void bme::Button::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<TextureResource>(path);
	TextureResource *texture = GetContext().GetResourceManager().Get<TextureResource>(assetID);

	if (texture)
		frame.setTexture(&texture->Get());
}

void bme::Button::Load(int id)
{
	TextureResource *texture = GetContext().GetResourceManager().Get<TextureResource>(id);

	if (texture)
		frame.setTexture(&texture->Get());
}

sf::RectangleShape &bme::Button::GetFrame()
{
	return frame;
}

void bme::Button::ComputeBounds()
{
	sf::Vector2f transformPoint = GetWorldTransform().transformPoint(frame.getPosition());

	bounds.left = transformPoint.x;
	bounds.top = transformPoint.y;
	bounds.width = frame.getSize().x;
	bounds.height = frame.getSize().y;
}
