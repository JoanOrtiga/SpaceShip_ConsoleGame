#pragma once

#include <string>

#include "Game.h"

namespace Lamter
{
	class GameExtensions
	{
	public:
		template<typename T>
		static T* GetGameObjectOfTypeByTag(Game* game, std::string _tag)
		{
			for (GameObject* gameObject : *game->gameObjects)
			{
				if (gameObject->tag == _tag)
				{
					auto gameObj = gameObject;
					auto x = dynamic_cast<T*>(gameObject);
					return reinterpret_cast<T*>(gameObject);
				}
			}
			return nullptr;
		}

		template<typename T>
		static std::vector<T*>& GetGameObjectsOfTypeByTag(Game* game, std::string _tag)
		{
			std::vector<T*> list;
			for (GameObject* gameObject : *game->gameObjects)
			{
				if (gameObject->tag == _tag)
				{
					list.push_back(gameObject);
				}
			}
			return list;
		}

		static GameObject* GetGameObjectOfTypeByTag(Game* game, std::string _tag)
		{
			for (GameObject* gameObject : *game->gameObjects)
			{
				if (gameObject->tag == _tag)
				{
					return gameObject;
				}
			}
			return nullptr;
		}

		static std::vector<GameObject*>& GetGameObjectsOfTypeByTag(Game* game, std::string _tag)
		{
			std::vector<GameObject*> list;
			for (GameObject* gameObject : *game->gameObjects)
			{
				if (gameObject->tag == _tag)
				{
					list.push_back(gameObject);
				}
			}
			return list;
		}
	};
}

