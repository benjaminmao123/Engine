#include "bmepch.h"
#include "TextObject.h"
#include "Text.h"
#include "Context.h"

/// <summary>
///		Parameterized constructor. 
///		Initializes context, the parent of the object, position, and name.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="parent">
///		The GameObject that parents this GameObject.
///	</param>
/// <param name="pos">
///		The position to place the GameObject.
///	</param>
/// <param name="name">
///		The name of the GameObject.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, GameObject *parent, 
							const sf::Vector2f &pos, const std::string &name)
	: GameObject(context, parent, pos, name)
{
	AddComponent<Text>();

	Text *text = GetComponent<Text>();
	text->Load("./assets/fonts/arial.ttf");
	text->GetText().setCharacterSize(15);
	text->GetText().setFillColor(sf::Color::Red);
	text->GetText().setString("My Text");
}

/// <summary>
///		Overloaded constructor. Initializes context and sets
///		parent, position, and name to default values.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context)
	: TextObject(context, nullptr, sf::Vector2f(), "TextObject")
{

}

/// <summary>
///		Overloaded constructor. Initializes context and parent.
///		Sets position and name to default values.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="parent">
///		The GameObject that parents this GameObject.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, GameObject *parent)
	: TextObject(context, parent, sf::Vector2f(), "TextObject")
{

}

/// <summary>
///		Overloaded constructor. Initializes context and parent
///		and position. Sets name to a default value.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="parent">
///		The GameObject that parents this GameObject.
///	</param>
/// <param name="pos">
///		The position to set the GameObject to.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, GameObject *parent, 
							const sf::Vector2f &pos)
	: TextObject(context, parent, pos, "TextObject")
{

}

/// <summary>
///		Overloaded constructor. Initializes context and position.
///		Sets parent and name to a default value.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="pos">
///		The position to set the GameObject to.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, const sf::Vector2f &pos)
	: TextObject(context, nullptr, pos, "TextObject")
{

}

/// <summary>
///		Overloaded constructor. Initializes context and position
///		and name. Sets name to a default value.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="pos">
///		The position to set the GameObject to.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, const sf::Vector2f &pos, 
							const std::string &name)
	: TextObject(context, nullptr, pos, name)
{

}

/// <summary>
///		Overloaded constructor. Initializes context and name.
///		Sets parent and position to a default value.
/// </summary>
/// <param name="context">
///		Context object that contains relevant information
///		needed by the class.
///	</param>
/// <param name="pos">
///		The position to set the GameObject to.
///	</param>
///	<returns>
///		void
///	</returns>
bme::TextObject::TextObject(Context &context, const std::string &name)
	: TextObject(context, nullptr, sf::Vector2f(), name)
{

}
