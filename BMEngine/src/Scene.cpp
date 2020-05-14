#include "bmepch.h"
#include "Scene.h"
#include "Context.h"
#include "Renderer2D.h"
#include "GameObject.h"

///	<summary>
///		Paramterized constructor.
///		Initializes context.
/// </summary>
///	<param name="context">
///		The Context object.
///	</param>
///	<return>
///		void
///	</return>
bme::Scene::Scene(Context &context)
	: context(context)
{

}

///	<summary>
///		Destructor for the scene object.
///		Deletes all GameObjects in the Scene hierarchy.
/// </summary>
///	<return>
///		void
///	</return>
bme::Scene::~Scene()
{
	for (auto &go : hierarchy)
		delete go;
}

///	<summary>
///		Responsible for calling the virtual Awake() function of each 
///		GameObject in the hierarchy.
///		Performs any necessary operations before/after the Awake() call.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::OnAwake()
{
	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	Awake();
}

///	<summary>
///		Responsible for calling the virtual Start() function of each 
///		GameObject in the hierarchy.
///		Performs any necessary operations before/after the Start() call.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::OnStart()
{
	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Start();
	}

	Start();
}

///	<summary>
///		virtual Awake() function to be overridden by derived
///		Scene classes.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::Awake()
{

}

///	<summary>
///		virtual Start() function to be overridden by derived
///		Scene classes.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::Start()
{

}

///	<summary>
///		For all GameObjects that have not had their Awake()
///		and Start() methods called, calls those respective methods.
///		Calls the Update() function of all GameObjects
///		in the hierarchy.
///		Processes GameObject removals.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::Update()
{
	for (auto &go : hierarchy)
		go->CheckDestroy();

	ProcessRemoval();

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Start();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Update(go->GetTransform());
	}
}

///	<summary>
///		For all GameObjects that have not had their Awake()
///		and Start() methods called, calls those respective methods.
///		Calls the LateUpdate() function of all GameObjects
///		in the hierarchy.
///		Processes GameObject removals.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::LateUpdate()
{
	for (auto &go : hierarchy)
		go->CheckDestroy();

	ProcessRemoval();

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Start();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Start();
	}

	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->LateUpdate(go->GetTransform());
	}
}

///	<summary>
///		Sorts the GameObjects by z-order.
///		Calls the Render() method of each GameObject
///		with a Renderer Component.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::Render()
{
	std::sort(renderables.begin(), renderables.end(),
		[](GameObject *a, GameObject *b)
		{
			Renderer2D *aRend = a->GetComponent<Renderer2D>();
			Renderer2D *bRend = b->GetComponent<Renderer2D>();

			if ((!aRend && bRend) || !(aRend && bRend))
				return false;
			else if (aRend && !bRend)
				return true;

			return aRend->GetZOrder() < bRend->GetZOrder();
		});

	for (auto &go : renderables)
	{
		if (go->IsEnabled())
			go->Render();
	}
}

///	<summary>
///		Adds a GameObject to the Scene hierarchy and any GameObject
///		with a Renderer Component to the renderables list.
/// </summary>
///	<param name="object">
///		GameObject pointer to add to the Scene.
///	</param>
///	<return>
///		void
///	</return>
void bme::Scene::AddGameObject(GameObject *object)
{
	hierarchy.push_back(object);
	AddRenderable(object);
}

///	<summary>
///		Getter method for context.
/// </summary>
///	<return>
///		A reference to the Context object.
///	</return>
bme::Context &bme::Scene::GetContext()
{
	return context;
}

///	<summary>
///		Removes a GameObject from the Scene.
///		Performs a recursive depth first search for the GameObject.
///		The removed GameObject is sent to a queue for
///		deletion.
/// </summary>
///	<param name="object">
///		A pointer to the GameObject to remove.
///	</param>
/// <param name="id">
///		The id of the GameObject.
///	</param>
///	<return>
///		void
///	</return>
void bme::Scene::RemoveGameObject(GameObject *object, int id)
{
	for (auto rIt = renderables.begin(); rIt != renderables.end(); ++rIt)
	{
		if ((*rIt)->GetID() == id)
		{
			toRemove.push(*rIt);
			renderables.erase(rIt);
			break;
		}
	}

	for (auto hIt = hierarchy.begin(); hIt != hierarchy.end(); ++hIt)
	{
		if ((*hIt)->GetID() != id)
		{
			for (auto cIt = (*hIt)->GetChildren().begin(); cIt != (*hIt)->GetChildren().end(); ++cIt)
			{
				if ((*cIt)->GetID() == id)
				{
					(*hIt)->GetChildren().erase(cIt);
					return;
				}
				else
					RemoveGameObject(*cIt, id);
			}
		}
		else
		{
			hierarchy.erase(hIt);
			break;
		}
	}
}

///	<summary>
///		Deletes all the GameObjects in the queue.
/// </summary>
///	<return>
///		void
///	</return>
void bme::Scene::ProcessRemoval()
{
	while (!toRemove.empty())
	{
		delete toRemove.front();
		toRemove.pop();
	}
}

///	<summary>
///		Adds a renderable object to the renderables list and their
///		children.
/// </summary>
///	<param name="object">
///		A pointer to the GameObject to add to the renderables list.
///	</param>
///	<return>
///		void
///	</return>
void bme::Scene::AddRenderable(GameObject *object)
{
	if (object->GetComponent<Renderer>())
		renderables.push_back(object);

	AddRenderableChildren(object);
}

///	<summary>
///		Adds all child GameObjects to the renderables list
///		using a recursive depth first search.
/// </summary>
///	<param name="object">
///		A pointer to the GameObject to add to the renderables list.
///	</param>
///	<return>
///		void
///	</return>
void bme::Scene::AddRenderableChildren(GameObject *object)
{
	for (const auto &go : object->GetChildren())
	{
		AddRenderable(go);

		if (go->GetComponent<Renderer>())
			renderables.push_back(go);
	}
}
