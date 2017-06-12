#pragma once


namespace HorizonEngine
{
	class GameObject;
	class Component
	{
		friend GameObject;
	public:
		virtual void Start() {};
		virtual void Update(float dt) {};
		virtual void OnDestory() {};
		virtual void OnPostRender() {};

		const GameObject& getOnwer() const;

	protected:
		void setOnwer(const GameObject& onwer);
	public:
		Component();
		~Component();


		
	private:
		const GameObject* mOnwer;

	};

}

