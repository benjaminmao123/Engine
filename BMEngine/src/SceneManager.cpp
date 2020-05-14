#include "bmepch.h"
#include "SceneManager.h"
#include "Scene.h"

/// <summary>
///		Default constructor.
///		Initializes the current scene pointer to nullptr.
/// </summary>
/// <return>
///		void
///	</return>
bme::SceneManager::SceneManager()
	: currentScene(nullptr)
{

}

/// <summary>
///		Destructor.
///		Deletes all scenes.
/// </summary>
/// <return>
///		void
///	</return>
bme::SceneManager::~SceneManager()
{
	for (auto &scene : scenes)
		delete scene;
}

/// <summary>
///		Calls the OnAwake() of the current scene.
/// </summary>
/// <return>
///		void
///	</return>
void bme::SceneManager::Awake()
{
	if (currentScene)
		currentScene->OnAwake();
}

/// <summary>
///		Calls the OnStart() of the current scene.
/// </summary>
/// <return>
///		void
///	</return>
void bme::SceneManager::Start()
{
	if (currentScene)
		currentScene->OnStart();
}

/// <summary>
///		Calls the Update() of the current scene.
/// </summary>
/// <return>
///		void
///	</return>
void bme::SceneManager::Update()
{
	if (currentScene)
		currentScene->Update();
}

/// <summary>
///		Calls the LateUpdate() of the current scene.
/// </summary>
/// <return>
///		void
///	</return>
void bme::SceneManager::LateUpdate()
{
	if (currentScene)
		currentScene->LateUpdate();
}

/// <summary>
///		Calls the Render() of the current scene.
/// </summary>
/// <return>
///		void
///	</return>
void bme::SceneManager::Render()
{
	if (currentScene)
		currentScene->Render();
}

/// <summary>
///		Adds a Scene to the list of Scenes.
/// </summary>
///	<param name="scene">
///		A pointer to the Scene to add.
///	</param>
/// <return>
///		void
///	</return>
void bme::SceneManager::AddScene(Scene *scene)
{
	scenes.push_back(scene);
}

/// <summary>
///		Sets the current active scene to a Scene at a given
///		index in the list.
/// </summary>
///	<param name="idx">
///		The index of the Scene to set the current scene to.
///	</param>
/// <return>
///		void
///	</return>
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

/// <summary>
///		Retrieves the current scene.
/// </summary>
/// <return>
///		A pointer to the current active scene.
///	</return>
bme::Scene *bme::SceneManager::CurrentScene()
{
	return currentScene;
}
