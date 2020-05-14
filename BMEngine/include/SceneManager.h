#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>

namespace bme
{
	class Scene;

	/// <summary>
	///		Manages all of the Scenes in the game.
	///		Responsible for calling the Awake(), Start(),
	///		Update(), and LateUpdate() methods of the Scenes.
	///		Scenes are stored as pointers in a std::vector.
	/// </summary>
	class SceneManager
	{
	public:
		DLLEXPORT SceneManager();
		DLLEXPORT ~SceneManager();

		DLLEXPORT void Update();
		DLLEXPORT void LateUpdate();
		DLLEXPORT void Render();

		DLLEXPORT void AddScene(Scene *scene);
		DLLEXPORT void SetCurrentScene(unsigned int idx);
		DLLEXPORT Scene *CurrentScene();

	private:
		void Awake();
		void Start();

		std::vector<Scene *> scenes;
		Scene *currentScene;
	};
}