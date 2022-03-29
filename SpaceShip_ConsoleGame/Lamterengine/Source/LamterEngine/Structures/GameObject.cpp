#include "GameObject.h"

#include "Game.h"

namespace Lamter
{
	GameObject::GameObject(Game* _game) : game(_game)
	{
		game->AddGameObject(this);
	}

	template<class T>
	T* GameObject::GetComponent(GameObject* gameObject)
	{
		return dynamic_cast<T*>(gameObject);
	}

	void GameObject::SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode)
	{
	}

	void GameObject::LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode)
	{
	}
}
