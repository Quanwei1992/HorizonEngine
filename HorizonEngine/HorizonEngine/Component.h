#pragma once


namespace HorizonEngine
{
	//class GameObject;
	class Component
	{
	public:
		virtual void Start() {};
		virtual void Update(float dt) {};
		virtual void OnDestory() {};
		virtual void OnPostRender() {};

		//GameObject& GetOnwer() { return *mOnwer; }
		Component();
		~Component();
	private:
		//Component(GameObject& onwer);
		
	private:
		//GameObject* mOnwer;

	};

}

