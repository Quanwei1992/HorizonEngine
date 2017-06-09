#pragma once
#include "GameObject.h"
#include <vector>
namespace HorizonEngine
{
	class Scene
	{

	public:
		GameObject CreateGameObject();
		std::vector<GameObject*>& GetAllObjects();

	public:
		Scene();
		~Scene();
		void Update(float deltaTime);

	private:
		std::vector<GameObject*> mObjects;
	};

}

