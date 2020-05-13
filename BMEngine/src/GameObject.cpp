/// <summary>
///		Base GameObject class.
/// </summary>

#include "bmepch.h"
#include "GameObject.h"
#include "Scene.h"
#include "Component.h"
#include "Context.h"
#include "SceneManager.h"
#include "Renderer.h"

int bme::GameObject::nextID = 0;

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
bme::GameObject::GameObject(Context &context, GameObject *parent, 
							const sf::Vector2f &pos, const std::string &name)
	: context(context), parent(parent), name(name), isEnabled(true),
	  id(nextID++)
{
	transformable.setPosition(pos);
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
bme::GameObject::GameObject(Context &context)
	: GameObject(context, nullptr, sf::Vector2f(), "GameObject")
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
bme::GameObject::GameObject(Context &context, GameObject *parent)
	: GameObject(context, parent, sf::Vector2f(), "GameObject")
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
bme::GameObject::GameObject(Context &context, GameObject *parent, 
							const sf::Vector2f &pos)
	: GameObject(context, parent, pos, "GameObject")
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
bme::GameObject::GameObject(Context &context, const sf::Vector2f &pos)
	: GameObject(context, nullptr, pos, "GameObject")
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
bme::GameObject::GameObject(Context &context, const sf::Vector2f &pos, 
							const std::string &name)
	: GameObject(context, nullptr, pos, name)
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
bme::GameObject::GameObject(Context &context, const std::string &name)
	: GameObject(context, nullptr, sf::Vector2f(), name)
{

}

/// <summary>
///		Destructor. Cleans up components and
///		children.
/// </summary>
///	<returns>
///		void
///	</returns>
bme::GameObject::~GameObject()
{
	for (auto &c : components)
		delete c;

	for (auto &go : children)
		delete go;
}

/// <summary>
///		Calls all of the Awake() methods for components
///		for this GameObject and child GameObjects by
///		their execution order.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::GameObject::Awake()
{
	std::sort(components.begin(), components.end(),
		[](Component *a, Component *b)
		{
			return a->GetExecutionOrder() < b->GetExecutionOrder();
		});

	for (auto &c : components)
	{
		if (c->GetIsEnabled())
			c->OnAwake();
	}

	for (auto &go : children)
	{
		if (go->isEnabled)
			go->Awake();
	}
}

/// <summary>
///		Calls all of the Start() methods for components
///		for this GameObject and child GameObjects by
///		their execution order.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::GameObject::Start()
{
	std::sort(components.begin(), components.end(),
		[](Component *a, Component *b)
		{
			return a->GetExecutionOrder() < b->GetExecutionOrder();
		});

	for (auto &c : components)
	{
		if (c->GetIsEnabled())
			c->OnStart();
	}

	for (auto &go : children)
	{
		if (go->isEnabled)
			go->Start();
	}
}

/// <summary>
///		Calls all of the Update() methods for components
///		for this GameObject and child GameObjects.
/// </summary>
///	<param name="parentTransform">
///		The parentTransform to update the components relative to.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::Update(const sf::Transform &parentTransform)
{
	worldTransform = transformable.getTransform();

	if (parent)
		worldTransform = parentTransform * worldTransform;

	for (auto &c : components)
	{
		if (c->GetIsEnabled())
			c->Update();
	}

	for (auto &go : children)
	{
		if (go->isEnabled)
			go->Update(worldTransform);
	}
}

/// <summary>
///		Calls all of the LateUpdate() methods for components
///		for this GameObject and child GameObjects.
/// </summary>
///	<param name="parentTransform">
///		The parentTransform to update the components relative to.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::LateUpdate(const sf::Transform &parentTransform)
{
	worldTransform = transformable.getTransform();

	if (parent)
		worldTransform = parentTransform * worldTransform;

	for (auto &c : components)
	{
		if (c->GetIsEnabled())
			c->LateUpdate();
	}

	for (auto &go : children)
	{
		if (go->isEnabled)
			go->LateUpdate(worldTransform);
	}
}

/// <summary>
///		Calls all of the Render() methods for components
///		for all GameObjects.
/// </summary>
///	<returns>
///		void
///	</returns>
void bme::GameObject::Render()
{
	for (auto &c : components)
	{
		Renderer *rend = dynamic_cast<Renderer *>(c);

		if (rend && rend->GetIsEnabled())
			rend->OnRender();
	}
}

/// <summary>
///		Adds a child to the GameObject.
/// </summary>
///	<param name="object">
///		The child GameObject to add.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::AddChild(GameObject *object)
{
	children.push_back(object);
}

/// <summary>
///		Retrieves a GameObject with the given name.
/// </summary>
///	<param name="name">
///		The name of the GameObject to retrieve.
///	</param>
///	<returns>
///		A pointer to the GameObject that is found.
///	</returns>
bme::GameObject *bme::GameObject::GetChild(const std::string &name)
{
	auto it = std::find_if(children.begin(), children.end(),
		[&](GameObject *obj)
		{
			return obj->GetName() == name;
		});

	return *it;
}

/// <summary>
///		Instantiates a GameObject from another GameObject.
/// </summary>
///	<param name="object">
///		The GameObject to instantiate.
///	</param>
///	<returns>
///		A pointer to the GameObject that was created.
///	</returns>
bme::GameObject *bme::GameObject::Instantiate(const GameObject *object)
{
	GameObject *clone = object->InstantiateHelper(object);
	clone->parent = nullptr;
	object->context.GetSceneManager().CurrentScene()->AddGameObject(clone);

	return clone;
}

/// <summary>
///		Instantiates a GameObject from another GameObject and parents
///		it to another GameObject.
/// </summary>
///	<param name="object">
///		The GameObject to instantiate.
///	</param>
///	<param name="parent">
///		The GameObject to parent the created GameObject to.
///	</param>
///	<returns>
///		A pointer to the GameObject that was created.
///	</returns>
bme::GameObject *bme::GameObject::Instantiate(const GameObject *object, GameObject *parent)
{
	GameObject *clone = object->InstantiateHelper(object);
	clone->parent = parent;
	parent->AddChild(clone);

	return clone;
}

/// <summary>
///		Destroys a given GameObject.
/// </summary>
///	<param name="object">
///		The GameObject to destroy.
///	</param>
///	<param name="waitTime">
///		Optional amount of time to wait before destroying
///		the GameObject.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::Destroy(GameObject *&object, float waitTime)
{
	
}

/// <summary>
///		Getter for the parent of this GameObject.
/// </summary>
///	<returns>
///		A pointer to the parent GameObject.
///	</returns>
bme::GameObject *bme::GameObject::GetParent()
{
	return parent;
}

/// <summary>
///		Getter for the transform of this GameObject.
/// </summary>
///	<returns>
///		The sf::Transform of this GameObject.
///	</returns>
const sf::Transform &bme::GameObject::GetTransform() const
{
	return transform;
}

/// <summary>
///		Getter for the world transform of this GameObject.
/// </summary>
///	<returns>
///		The world sf::Transform of this GameObject.
///	</returns>
const sf::Transform &bme::GameObject::GetWorldTransform() const
{
	return worldTransform;
}

/// <summary>
///		Getter for the sf::Transformable of this GameObject.
/// </summary>
///	<returns>
///		The sf::Transformable of this GameObject.
///	</returns>
sf::Transformable &bme::GameObject::GetTransformable()
{
	return transformable;
}

/// <summary>
///		Getter for the isEnabled status of this GameObject.
/// </summary>
///	<returns>
///		The isEnabled boolean.
///	</returns>
bool bme::GameObject::IsEnabled() const
{
	return isEnabled;
}

/// <summary>
///		Setter for the isEnabled status of this GameObject.
/// </summary>
///	<param name="state">
///		Sets isEnabled to a given state.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::SetIsEnabled(bool state)
{
	isEnabled = state;
}

/// <summary>
///		Getter for the name of this GameObject.
/// </summary>
///	<returns>
///		void
///	</returns>
const std::string &bme::GameObject::GetName() const
{
	return name;
}

/// <summary>
///		Setter for the name of this GameObject.
/// </summary>
///	<param name="name">
///		The name to set this GameObject to.
///	</param>
///	<returns>
///		void
///	</returns>
void bme::GameObject::SetName(const std::string &name)
{
	this->name = name;
}

/// <summary>
///		Getter for the list of children that this GameObject holds.
/// </summary>
///	<returns>
///		A std::vector containing the list of children.
///	</returns>
const std::vector<bme::GameObject *> &bme::GameObject::GetChildren() const
{
	return children;
}

/// <summary>
///		Getter function for the Context object.
/// </summary>
///	<returns>
///		The Context object.
///	</returns>
bme::Context &bme::GameObject::GetContext()
{
	return context;
}

/// <summary>
///		Helper function to instantiate a GameObject from another 
///		GameObject.
/// </summary>
///	<param name="object">
///		The GameObject to instantiate.
///	</param>
///	<returns>
///		A pointer to the GameObject that was created.
///	</returns>
bme::GameObject *bme::GameObject::InstantiateHelper(const GameObject *object) const
{
	GameObject *clone = nullptr;

	if (object)
	{
		clone = new GameObject(context);

		for (const auto &go : object->children)
		{
			GameObject *child = InstantiateHelper(go);
			child->parent = clone;
			clone->children.push_back(child);
		}

		for (const auto &i : object->components)
			clone->components.push_back(i->Clone(clone));
	}

	return clone;
}

/// <summary>
///		Helper function to destroy a GameObject. Operation
///		is performed asychronously.
/// </summary>
///	<param name="object">
///		The GameObject to destroy.
///	</param>
///	<param name="waitTime">
///		The time to wait before destroying the object.
///	</param>
///	<returns>
///		A pointer to the GameObject that was created.
///	</returns>
void bme::GameObject::DestroyHelper(GameObject *&object, float waitTime)
{
	static float elapsedTime = 0;

	if (elapsedTime >= waitTime)
	{
		delete object;
		object = nullptr;
	}
}
