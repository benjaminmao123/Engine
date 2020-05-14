#include "bmepch.h"
#include "Selectable.h"

/// <summary>
///		Default consructor.
///		Initializes colors and whether or not the object is interactable.
/// </summary>
///	<return>
///		void
/// </return>
bme::Selectable::Selectable()
	: normalColor(sf::Color::White), highlightedColor(sf::Color::White),
	  pressedColor(sf::Color::White), selectedColor(sf::Color::White),
	  disabledColor(sf::Color::White), isInteractable(true),
	  isSelected(false)
{

}

/// <summary>
///		virtual destructor.
/// </summary>
///	<return>
///		void
/// </return>
bme::Selectable::~Selectable()
{

}

/// <summary>
///		Sets the normal color of the object when the object
///		is not being interacted with.
/// </summary>
///	<param name="color">
///		The sf::Color object.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetNormalColor(const sf::Color &color)
{
	normalColor = color;
}

/// <summary>
///		Sets the pressed color of the object when the object
///		is being pressed.
/// </summary>
///	<param name="color">
///		The sf::Color object.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetPressedColor(const sf::Color &color)
{
	pressedColor = color;
}

/// <summary>
///		Sets the highlighted color of the object when the object
///		is being hovered over.
/// </summary>
///	<param name="color">
///		The sf::Color object.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetHighlightedColor(const sf::Color &color)
{
	highlightedColor = color;
}

/// <summary>
///		Sets the selected color of the object when the object
///		is selected.
/// </summary>
///	<param name="color">
///		The sf::Color object.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetSelectedColor(const sf::Color &color)
{
	selectedColor = color;
}

/// <summary>
///		Sets the disabled color of the object when the object
///		is disabled.
/// </summary>
///	<param name="color">
///		The sf::Color object.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetDisabledColor(const sf::Color &color)
{
	disabledColor = color;
}

/// <summary>
///		Sets whether or not the object is interactable.
/// </summary>
///	<param name="state">
///		boolean to set the interactable state.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetIsInteractable(bool state)
{
	isInteractable = state;
}

/// <summary>
///		Retrieves the normal color of the object.
/// </summary>
///	<return>
///		A reference to the sf::Color object.
/// </return>
const sf::Color &bme::Selectable::GetNormalColor() const
{
	return normalColor;
}

/// <summary>
///		Retrieves the pressed color of the object.
/// </summary>
///	<return>
///		A reference to the sf::Color object.
/// </return>
const sf::Color &bme::Selectable::GetPressedColor() const
{
	return pressedColor;
}

/// <summary>
///		Retrieves the highlighted color of the object.
/// </summary>
///	<return>
///		A reference to the sf::Color object.
/// </return>
const sf::Color &bme::Selectable::GetHighlightedColor() const
{
	return highlightedColor;
}

/// <summary>
///		Retrieves the selected color of the object.
/// </summary>
///	<return>
///		A reference to the sf::Color object.
/// </return>
const sf::Color &bme::Selectable::GetSelectedColor() const
{
	return selectedColor;
}

/// <summary>
///		Retrieves the disabled color of the object.
/// </summary>
///	<return>
///		A reference to the sf::Color object.
/// </return>
const sf::Color &bme::Selectable::GetDisabledColor() const
{
	return disabledColor;
}

/// <summary>
///		Retrieves the interactable state of the object.
/// </summary>
///	<return>
///		A boolean representing if the object is interactable
///		or not.
/// </return>
bool bme::Selectable::GetIsInteractable() const
{
	return isInteractable;
}

/// <summary>
///		Retrieves whether or not the object is selected.
/// </summary>
///	<return>
///		A boolean representing if the object is selected.
/// </return>
bool bme::Selectable::GetIsSelected() const
{
	return isSelected;
}

/// <summary>
///		Adds an event to the onClick EventHandler for the object.
/// </summary>
///	<param name="event">
///		A pointer to an Event to add.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::AddEvent(Event *event)
{
	onClickEvents += event;
}

/// <summary>
///		Removes an event to the onClick EventHandler for the object.
/// </summary>
///	<param name="event">
///		A pointer to an Event to remove.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::RemoveEvent(Event *event)
{
	onClickEvents -= event;
}

/// <summary>
///		Invokes all of the Events in the onClick handler.
/// </summary>
///	<return>
///		void
/// </return>
void bme::Selectable::OnClick()
{
	onClickEvents.Invoke();
}

/// <summary>
///		Retrieves the onClick EventHandler object.
/// </summary>
///	<return>
///		A reference to the EventHandler object.
/// </return>
bme::EventHandler &bme::Selectable::GetOnClickEvents()
{
	return onClickEvents;
}

/// <summary>
///		Sets the selected state of the object.
/// </summary>
///	<param name="state">
///		The state to set isSelected to.
///	</param>
///	<return>
///		void
/// </return>
void bme::Selectable::SetIsSelected(bool state)
{
	isSelected = true;
}

