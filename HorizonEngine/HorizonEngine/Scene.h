#pragma once
#include "GameObject.h"
#include <vector>
namespace HorizonEngine
{
	class Scene
	{

	public:
		GameObject& CreateGameObject();
		std::vector<GameObject*>& GetAllObjects();
		virtual void Start();
		virtual void Destory();

	public:
		Scene();
		~Scene();
		void Update(double deltaTime);

	private:
		std::vector<GameObject*> mObjects;
	};

}

