/// <summary>
///		Serves as the Button Component for users to
///		use when creating UI.
/// </summary>

#include "bmepch.h"
#include "Button.h"
#include "GameObject.h"
#include "Text.h"
#include "TextureResource.h"
#include "Context.h"
#include "ResourceManager.h"
#include "InputManager.h"

/// <summary>
///		Parameterized constructor. Initializes owner of the class and context.
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
bme::Button::Button(GameObject *owner, Context &context, int zOrder)
	: Renderer2D(owner, context, zOrder), text(nullptr),
	  frame(sf::Vector2f(100, 100))
{
	frame.setFillColor(GetNormalColor());
}

/// <summary>
///		Start function for the component. Initializes text pointer
///		and sets the zOrder of the text.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Button::Start()
{
	text = GetOwner()->GetComponentInChildren<Text>();

	if (text)
		text->SetZOrder(GetZOrder() + 1);
}

/// <summary>
///		Update function for the component. Computes the bounds
///		of the button and checks if mouse is within the bounds.
/// </summary>
///	<returns>
///		void
///	</returns>
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

/// <summary>
///		Render function for the component. Draws the component
///		onto the screen.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Button::Render() 
{
	GetContext().GetWindow().draw(frame, GetWorldTransform());
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

/// <summary>
///		Computes the bounds of the button and checks if
///		the mouse is within. If it is, set appropriate colors
///		and if clicked, invoke events.
/// </summary>
///	<returns>
///		void
///	</returns>
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

/// <summary>
///		Loads a given texture into the frame.
/// </summary>
/// <param name="path">
///		The path of the texture.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Button::Load(const std::string &path)
{
	int assetID = GetContext().GetResourceManager().Add<TextureResource>(path);
	TextureResource *texture = GetContext().GetResourceManager().Get<TextureResource>(assetID);

	if (texture)
		frame.setTexture(&texture->Get());
}

/// <summary>
///		Loads a texture into the frame from the ResourceManager if it already exists.
/// </summary>
/// <param name="id">
///		The id of the sound to load.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::Button::Load(int id)
{
	TextureResource *texture = GetContext().GetResourceManager().Get<TextureResource>(id);

	if (texture)
		frame.setTexture(&texture->Get());
}

/// <summary>
///		Getter function for the frame.
/// </summary>
///	<returns>
///		Returns a reference to the sf::RectangleShape object.
///	</returns>
sf::RectangleShape &bme::Button::GetFrame()
{
	return frame;
}

/// <summary>
///		Computes the boundaries of the button.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::Button::ComputeBounds()
{
	sf::Vector2f transformPoint = GetWorldTransform().transformPoint(frame.getPosition());

	bounds.left = transformPoint.x;
	bounds.top = transformPoint.y;
	bounds.width = frame.getSize().x;
	bounds.height = frame.getSize().y;
}
