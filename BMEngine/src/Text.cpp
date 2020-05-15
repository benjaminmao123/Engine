#include "bmepch.h"
#include "Text.h"
#include "Context.h"
#include "ResourceManager.h"
#include "FontResource.h"
#include "GameObject.h"

///	<summary>
///		Parameterized constructor.
///		Initializes owner, context, and zOrder.
///	</summary>
///	<param name="owner">
///		A pointer to the owner of the GameObject.
/// </param>
///	<param name="context">
///		The Context object.
///	</param>
///	<param name="zOrder">
///		The zOrder of this object.
///	</param>
///	<return>
///		void
///	</return>
bme::Text::Text(GameObject *owner, Context &context, int zOrder)
	: Renderer2D(owner, context, zOrder), hAlign(HAlign::Center),
	  vAlign(VAlign::Middle), rect(0, 0, 100, 100)
{

}

///	<summary>
///		Updates the alignment of the text every frame.
///	</summary>
///	<return>
///		void
///	</return>
void bme::Text::Update()
{
	AlignText();
}

///	<summary>
///		Draws the text onto the screen.
///	</summary>
///	<return>
///		void
///	</return>
void bme::Text::Render()
{
	GetContext().GetWindow().draw(text, GetWorldTransform());
}

///	<summary>
///		Clones the current GameObject.
///		This function should only be called in Instantiate().
///	</summary>
///	<param name="owner">
///		A pointer to the owner of the clone.
///	</param>
///	<return>
///		A pointer to the newly cloned object.
///	</return>
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

/// <summary>
///		Loads a given font into the text.
/// </summary>
/// <param name="path">
///		The path of the font.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Text::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<FontResource>(path);
	FontResource *font = GetContext().GetResourceManager().Get<FontResource>(assetID);

	if (font)
		text.setFont(font->Get());
}

/// <summary>
///		Loads a font into the text from the ResourceManager if it already exists.
/// </summary>
/// <param name="id">
///		The id of the font to load.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Text::Load(int id)
{
	FontResource *font = GetContext().GetResourceManager().Get<FontResource>(id);

	if (font)
		text.setFont(font->Get());
}

/// <summary>
///		Getter function for the text.
/// </summary>
///	<returns>
///		Returns a reference to the sf::Text object.
///	</returns>
sf::Text &bme::Text::GetText()
{
	return text;
}

/// <summary>
///		Getter function for the rect boundary of the text.
/// </summary>
///	<returns>
///		Returns a reference to the sf::FloatRect object.
///	</returns>
sf::FloatRect &bme::Text::GetRect()
{
	return rect;
}

/// <summary>
///		Aligns the text to a certain position depending on the
///		veritcal and horizontal alignment options given.
/// </summary>
///	<returns>
///		void
///	</returns>
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
