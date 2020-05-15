#include "bmepch.h"
#include "PointObject2D.h"
#include "Context.h"
#include "Point2D.h"

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
bme::PointObject2D::PointObject2D(Context &context, GameObject *parent,
	const sf::Vector2f &pos, const std::string &name)
	: GameObject(context, parent, pos, name)
{
	AddComponent<Point2D>();
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
bme::PointObject2D::PointObject2D(Context &context)
	: PointObject2D(context, nullptr, sf::Vector2f(), "PointObject")
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
bme::PointObject2D::PointObject2D(Context &context, GameObject *parent)
	: PointObject2D(context, parent, sf::Vector2f(), "PointObject")
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
bme::PointObject2D::PointObject2D(Context &context, GameObject *parent,
	const sf::Vector2f &pos)
	: PointObject2D(context, parent, pos, "PointObject")
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
bme::PointObject2D::PointObject2D(Context &context, const sf::Vector2f &pos)
	: PointObject2D(context, nullptr, pos, "PointObject")
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
bme::PointObject2D::PointObject2D(Context &context, const sf::Vector2f &pos,
	const std::string &name)
	: PointObject2D(context, nullptr, pos, name)
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
bme::PointObject2D::PointObject2D(Context &context, const std::string &name)
	: PointObject2D(context, nullptr, sf::Vector2f(), name)
{

}
