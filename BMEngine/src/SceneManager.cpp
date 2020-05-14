#include "bmepch.h"
#include "SceneManager.h"
#include "Scene.h"

bme::SceneManager::SceneManager()
	: currentScene(nullptr)
{

}

bme::SceneManager::~SceneManager()
{
	for (auto &scene : scenes)
		delete scene;
}

void bme::SceneManager::Awake()
{
	if (currentScene)
		currentScene->OnAwake();
}

void bme::SceneManager::Start()
{
	if (currentScene)
		currentScene->OnStart();
}

void bme::SceneManager::Update()
{
	if (currentScene)
		currentScene->Update();
}

void bme::SceneManager::LateUpdate()
{
	if (currentScene)
		currentScene->LateUpdate();
}

void bme::SceneManager::Render()
{
	if (currentScene)
		currentScene->Render();
}

void bme::SceneManager::AddScene(Scene *scene)
{
	scenes.push_back(scene);
}

void bme::SceneManager::SetCurrentScene(unsigned int idx)
{
	if (!scenes.empty())
	{
		if (idx < scenes.size())
		{
			currentScene = scenes[idx];
			Awake();
			Start();
		}
	}
}

bme::Scene *bme::SceneManager::CurrentScene()
{
	return currentScene;
}
