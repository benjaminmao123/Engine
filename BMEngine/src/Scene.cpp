#include "bmepch.h"
#include "Scene.h"
#include "Context.h"
#include "Renderer2D.h"
#include "GameObject.h"

bme::Scene::Scene(Context &context)
	: context(context)
{

}

bme::Scene::~Scene()
{
	for (auto &go : hierarchy)
		delete go;
}

void bme::Scene::OnAwake()
{
	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	Awake();
}

void bme::Scene::OnStart()
{
	for (auto &go : hierarchy)
	{
		if (go->IsEnabled())
			go->Start();
	}

	Start();
}

void bme::Scene::Awake()
{

}

void bme::Scene::Start()
{

}

void bme::Scene::Update()
{
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

void bme::Scene::LateUpdate()
{
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

void bme::Scene::AddGameObject(GameObject *object)
{
	hierarchy.push_back(object);
	AddRenderable(object);
}

bme::Context &bme::Scene::GetContext()
{
	return context;
}

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

void bme::Scene::ProcessRemoval()
{
	while (!toRemove.empty())
	{
		delete toRemove.front();
		toRemove.pop();
	}
}

void bme::Scene::AddRenderable(GameObject *object)
{
	if (object->GetComponent<Renderer>())
		renderables.push_back(object);

	AddRenderableChildren(object);
}

void bme::Scene::AddRenderableChildren(GameObject *object)
{
	for (const auto &go : object->GetChildren())
	{
		AddRenderable(go);

		if (go->GetComponent<Renderer>())
			renderables.push_back(go);
	}
}
