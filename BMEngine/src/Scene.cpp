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
	for (auto &go : gameObjects)
		delete go;
}

void bme::Scene::Awake()
{
	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Awake();
	}
}

void bme::Scene::Start()
{
	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Start();
	}
}

void bme::Scene::Update()
{
	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Start();
	}

	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Update(go->GetTransform());
	}
}

void bme::Scene::LateUpdate()
{
	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Awake();
	}

	for (auto &go : gameObjects)
	{
		if (go->IsEnabled())
			go->Start();
	}

	for (auto &go : gameObjects)
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
	gameObjects.emplace_back(object);
	AddRenderable(object);
}

bme::Context &bme::Scene::GetContext()
{
	return context;
}

void bme::Scene::AddRenderable(GameObject *object)
{
	if (object->GetComponent<Renderer>())
		renderables.emplace_back(object);

	AddRenderableChildren(object);
}

void bme::Scene::AddRenderableChildren(GameObject *object)
{
	for (const auto &go : object->GetChildren())
	{
		AddRenderable(go);

		if (go->GetComponent<Renderer>())
			renderables.emplace_back(go);
	}
}
