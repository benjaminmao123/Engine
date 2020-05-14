#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>
#include <queue>

namespace bme
{
	class GameObject;
	class Context;

	class Scene
	{
	public:
		DLLEXPORT Scene(Context &context);
		DLLEXPORT virtual ~Scene();

		DLLEXPORT void OnAwake();
		DLLEXPORT void OnStart();
		DLLEXPORT void Update();
		DLLEXPORT void LateUpdate();
		DLLEXPORT void Render();

		DLLEXPORT void AddGameObject(GameObject *object);
		DLLEXPORT Context &GetContext();
		DLLEXPORT void RemoveGameObject(GameObject *object, int id);
		DLLEXPORT void ProcessRemoval();

	protected:
		DLLEXPORT virtual void Awake();
		DLLEXPORT virtual void Start();

	private:
		void AddRenderable(GameObject *object);
		void AddRenderableChildren(GameObject *object);

		Context &context;
		std::vector<GameObject *> hierarchy;
		std::vector<GameObject *> renderables;
		std::queue<GameObject *> toRemove;
	};
}