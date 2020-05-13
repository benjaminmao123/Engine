/// <summary>
///		Premade UI button object.
/// </summary>

#include "bmepch.h"
#include "PointObject.h"
#include "Context.h"
#include "Point.h"

/// <summary>
///		Overloaded constructor. 
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
bme::PointObject::PointObject(Context &context, GameObject *parent,
	const sf::Vector2f &pos, const std::string &name)
	: GameObject(context, parent, pos, name)
{
	AddComponent<Point>();
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
bme::PointObject::PointObject(Context &context)
	: PointObject(context, nullptr, sf::Vector2f(), "PointObject")
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
bme::PointObject::PointObject(Context &context, GameObject *parent)
	: PointObject(context, parent, sf::Vector2f(), "PointObject")
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
bme::PointObject::PointObject(Context &context, GameObject *parent,
	const sf::Vector2f &pos)
	: PointObject(context, parent, pos, "PointObject")
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
bme::PointObject::PointObject(Context &context, const sf::Vector2f &pos)
	: PointObject(context, nullptr, pos, "PointObject")
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
bme::PointObject::PointObject(Context &context, const sf::Vector2f &pos,
	const std::string &name)
	: PointObject(context, nullptr, pos, name)
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
bme::PointObject::PointObject(Context &context, const std::string &name)
	: PointObject(context, nullptr, sf::Vector2f(), name)
{

}
