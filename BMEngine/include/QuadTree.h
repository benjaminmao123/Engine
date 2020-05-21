#pragma once

#ifdef BMENGINE_EXPORTS 
#define DLLEXPORT __declspec(dllexport)  
#else
#define DLLEXPORT __declspec(dllimport)  
#endif

#include <vector>

#include "BoxCollider2D.h"

namespace bme
{
	class DLLEXPORT QuadTree
	{
	public:
		QuadTree();

		void Insert(BoxCollider2D *collider);
		void Remove(BoxCollider2D *collider);
		std::vector<BoxCollider2D *> Search(const sf::FloatRect &area);
		void Clear();

	private:
		std::vector<BoxCollider2D *> collidedObjects;

	};
}