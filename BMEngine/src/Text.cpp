#include "bmepch.h"
#include "Text.h"
#include "Context.h"
#include "ResourceManager.h"
#include "FontResource.h"
#include "GameObject.h"

bme::Text::Text(GameObject *owner, Context &context, int zOrder)
	: Renderer2D(owner, context, zOrder), hAlign(HAlign::Center),
	  vAlign(VAlign::Middle), rect(0, 0, 100, 100)
{

}

void bme::Text::Update()
{
	AlignText();
}

void bme::Text::Render()
{
	GetContext().GetWindow().draw(text, GetWorldTransform());
}

bme::Text *bme::Text::Clone(GameObject *owner)
{
	Text *clone = new Text(owner, GetContext());
	clone->SetExecutionOrder(GetExecutionOrder());
	clone->SetZOrder(GetZOrder());
	clone->text = text;
	clone->font = font;
	clone->rect = rect;
	clone->hAlign = hAlign;
	clone->vAlign = vAlign;
	clone->SetIsEnabled(GetIsEnabled());
	clone->SetView(GetView());

	return clone;
}

void bme::Text::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<FontResource>(path);
	FontResource *font = GetContext().GetResourceManager().Get<FontResource>(assetID);

	if (font)
		text.setFont(font->Get());
}

void bme::Text::Load(int id)
{
	FontResource *font = GetContext().GetResourceManager().Get<FontResource>(id);

	if (font)
		text.setFont(font->Get());
}

sf::Text &bme::Text::GetText()
{
	return text;
}

sf::FloatRect &bme::Text::GetRect()
{
	return rect;
}

void bme::Text::AlignText()
{
	text.setPosition(0, 0);

	float x, y;

	switch (hAlign)
	{
	case HAlign::Left:
		text.setPosition(text.getPosition());
		break;
	case HAlign::Center:
		x = (text.getPosition().x + ((rect.width / 2)) - (text.getLocalBounds().width / 2));
		text.setPosition(x, text.getPosition().y);
		break;
	case HAlign::Right:
		x = (text.getPosition().x + rect.width) - text.getLocalBounds().width;
		text.setPosition(x, text.getPosition().y);
		break;
	default:
		break;
	}

	switch (vAlign)
	{
	case VAlign::Top:
		text.setPosition(text.getPosition());
		break;
	case VAlign::Middle:
		y = (text.getPosition().y + (rect.height / 2)) - (text.getCharacterSize() - 5);
		text.setPosition(text.getPosition().x, y);
		break;
	case VAlign::Bottom:
		y = (text.getPosition().y + rect.height - 4) - text.getLocalBounds().height;
		text.setPosition(text.getPosition().x, y);
		break;
	default:
		break;
	}
}
